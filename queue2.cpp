#pragma once
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

inline void error( char * str){
    fprintf(stderr, "%s\n", str);
    exit(1);
};

#define MAX_QUEUE_SIZE 100

class CircularQueue{
    protected:
        int front;
        int rear;
        int data[MAX_QUEUE_SIZE];
    public:
        CircularQueue(){front = rear = 0;}
        ~CircularQueue(){}
        bool isEmpty(){return front == rear; }
        bool isFull(){return (rear+1)%MAX_QUEUE_SIZE == front;}
        void enqueue(int val);
        int dequeue();
        int peek();
        void display();
};

class CircularDeque : public CircularQueue{
    public:
        CircularDeque(){};
        void addRear(int val){ enqueue(val); }
        int deleteFront(){ return dequeue(); }
        int getFront(){return peek(); }
        void addFront(int val);
        int deleteRear();
        int getRear();
        void display();
};

int main(){
    CircularDeque deq;
    for (int i = 1; i < 8; i++){
        if (i%2) deq.addFront(i);
        else deq.addRear(i);
    }
    deq.display();

    deq.deleteFront();
    deq.deleteRear();
    deq.deleteFront();
    deq.display();

    return 0;
}

void CircularQueue::enqueue(int val){
    if(isFull()) error("error : queue full.\n");
    else{
        rear = (rear+1)%MAX_QUEUE_SIZE;
        data[rear] = val;
    }
};

int CircularQueue::dequeue(){
    if (isEmpty()) error("error : queue empty.\n");
    else{
        front = (front+1)%MAX_QUEUE_SIZE;
        return data[front];
    }
};

int CircularQueue::peek(){
    if (isEmpty()) error("error : queue empty.\n");
    else return data[(front+1)%MAX_QUEUE_SIZE];
};

void CircularQueue::display(){
    cout << "queue : ";
    int maxi = (front < rear) ? rear : rear+MAX_QUEUE_SIZE;
    for (int i = front +1; i<=maxi; i++){
        cout << data[i%MAX_QUEUE_SIZE] << " ";
    }
    cout << endl;
};

void CircularDeque::addFront(int val){
    if (isFull()) error("error : dack full.\n");
    else{
        data[front] = val;
        front = (front-1+MAX_QUEUE_SIZE)%MAX_QUEUE_SIZE;
    }
};

int CircularDeque::deleteRear(){
    if (isEmpty()) error("error : dack empty.\n");
    else{
        int ret = data[rear];
        rear = (rear-1+MAX_QUEUE_SIZE)%MAX_QUEUE_SIZE;
        return ret;
    }
};

int CircularDeque::getRear(){
    if (isEmpty()) error("error : dack empty.\n");
    else return data[rear];

    return 0;
};

void CircularDeque::display(){
    cout << "dack : ";
    int maxi = (front < rear) ? rear : rear+MAX_QUEUE_SIZE;
    for (int i = front+1; i <= maxi; i++) cout << data[i%MAX_QUEUE_SIZE];
    cout << endl;
};