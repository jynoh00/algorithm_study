// CPP 기반 Queue (basic)

#include <iostream>
#define MAX 5
#define PUSH 1
#define POP 2

#define _CRT_SECURE_NO_WARNINGS

using namespace std;

class Queue{
    private:
        int front, rear, lastOP, data[MAX]; // .
    public:
        Queue(){
            front = 0;
            rear = 0;
            lastOP = 0;
        }
        int isFull();
        int isEmpty();
        void enqueue(int data);
        int dequeue();
        void printQ();
};

int main(){
    Queue q;
    for (int i = 1; i < 7; i++) q.enqueue(10*i);
    q.printQ();
    cout << q.dequeue() << endl;
    q.printQ();
    q.enqueue(60);
    q.printQ();
}

int Queue::isFull(){
    // if (front == rear && lastOP == PUSH) return 1;
    // return 0;

    return front == rear && lastOP == PUSH ? 1 : 0;
}
int Queue::isEmpty(){
    // if ( front == rear && lastOP == POP) return 1;
    // return 0;

    return front == rear && lastOP == POP ? 1 : 0;
}
void Queue::enqueue(int data){
    if (!isFull()){
        cout << data << " is queued." << endl;
        rear = ((rear+1)%MAX);
        this->data[rear] = data;
        lastOP = PUSH;
    }else{ cout << "Can't enqueue. It's full." << endl; }
}
int Queue::dequeue(){
    if (!isEmpty()){
        cout << "DeQ." << endl;
        lastOP = POP;
        front = ((front+1)%MAX);
        return data[front];
    }
    return 0;
}
void Queue::printQ(){
    int numberOfQ;
    numberOfQ = rear > front ? rear-front : (rear + MAX) - front;
    int index = front +1;
    for (int i = 0; i < numberOfQ; i++){
        cout << data[(index+i)%MAX] << " ";
    }
    cout << endl;
}