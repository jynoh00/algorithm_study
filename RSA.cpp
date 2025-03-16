// RSA - Algorithm 
// 공개키 암호화 방식
#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h> // for random, header

using namespace std;

// public, 전역
int p = 0, q = 0, n, t, flag, e[100], d[100], temp[100], j, m[100], en[100], i; 
char msg[100];

int prand(){ // p_random, 난수 생성
    int j;
    srand((unsigned)time(NULL));
    while(true){
        j = (rand()%98)+2; // 2 ~ 99까지의 수
        if (j == 2) return j;
        for (int l = 2; l < j; l++){
            if (j%l == 0) break;
            if((l+1) == j) return j;
        }
    }
}

// prime 판별, return 1 or 0
int prime(int pr){
    int i;
    j = sqrtl(pr);
    for (i = 2;  i <= j; i++){
        if (pr%i == 0) return 0;
    }
    return 1;
}

int cd(int x){
    int k = 1;
    while (true){
        k += t;
        if (k%x == 0) return (k/x);
    }
}

void ce(){
    int k = 0;
    for (i = 2; i < t; i++){
        if (t%i == 0) continue;
        flag = prime(i);
        if (flag == 1 && i != p && i != q){
            e[k] = i;
            flag = cd(e[k]);
            if (flag > 0){
                d[k] = flag;
                k++;
            }
            if (k == 99){
                break;
            }
        }
    }
}

// 암호화
void encrypt(){
    int pt, ct, key = e[0], k, len;
    i = 0;
    len = strlen(msg);
    while(i != len){
        pt = m[i];
        pt -= 96;
        k = 1;
        for (j = 0; j < key; j++){
            k *= pt;
            k %= n;
        }
        temp[i] = k;
        ct = k + 96;
        en[i] = ct;
        i++;
    }
    en[i] = -1;
    cout << "\nTHE ENCRYPTED MESSAGE IS" << endl;
    for (i = 0; en[i] != -1; i++){
        cout << (char)en[i] << endl;
    }
}

// 복호화
void decrypt(){
    int pt, ct, key = d[0], k;
    i = 0;
    while (en[i] != -1){
        ct = temp[i];
        k = 1;
        for (j = 0; j < key; j++){
            k *= ct;
            k %= n;
        }
        pt += 96;
        m[i] = pt;
        i++;
    }
    m[i] = -1;
    cout << "THE DECRYPTED MESSAGE IS" << endl;
    for (i = 0; m[i] != -1; i++){
        cout << (char)m[i] << endl;
    }
}

int main(){
    cout << "First Number" << endl;
    p = prand();
    cout << p << endl;
    cout << "Second Number" << endl;
    while(true){
        q = prand();
        if (q != p){
            break;
        }
    }
    cout << q << endl;
    cout << "ENTER MESSAGE" << endl;
    fflush(stdin);
    cin >> msg;
    for (i = 0; msg[i] != NULL; i++){
        m[i] = msg[i];
    }
    n = p*q;
    t = (p-1)*(q-1);
    ce();
    encrypt();
    decrypt();

    return 0;
}