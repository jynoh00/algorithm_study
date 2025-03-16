/*

    RTT to time-out-interval, in TCP (reliable data transfer)

*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <random>

#define ALPHA 0.125
#define BETA 0.25
#define NUM 4

using namespace std;

float f_estimatedRTT(float esRTT, float spRTT);
float f_devRTT(float dRTT, float spRTT, float esRTT);
float f_timeOutInterval(float esRTT, float dRTT);

int main(){
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(15,17);

    random_device rd2;
    mt19937 mt2(rd2());
    uniform_int_distribution<int> gist(0,99);

    float estimatedRTT = 16.0, devRTT = 0.5, timeOutInterval;
    float sampleRTT;
    int dot_left;
    int dot_right;

    for (int i = 0; i < 100000; i++){
        sampleRTT = dist(mt) + 0.01 * gist(mt2); // new sampleRTT
        estimatedRTT = f_estimatedRTT(estimatedRTT, sampleRTT); // return new esRTT
        devRTT = f_devRTT(devRTT, sampleRTT, estimatedRTT);

        timeOutInterval = f_timeOutInterval(estimatedRTT, devRTT);

        cout << "sampleRTT: " << sampleRTT << "ms" << " - ";
        cout << "estimatedRTT: " << estimatedRTT << "ms" << " - " << "timeOutInterval: " << timeOutInterval << "ms" << endl;
    }
    return 0;
}

float f_estimatedRTT(float esRTT, float spRTT){
    return (1-ALPHA)*esRTT + ALPHA*spRTT;
}

float f_devRTT(float dRTT, float spRTT, float esRTT){
    if (spRTT >= esRTT) return (1-BETA)*dRTT + BETA*(spRTT-esRTT);
    else return (1-BETA)*dRTT + BETA*(esRTT-spRTT);   
}

float f_timeOutInterval(float esRTT, float dRTT){
    return esRTT + NUM*dRTT;
}