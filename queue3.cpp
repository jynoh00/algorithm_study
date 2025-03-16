//C 기반 Queue (basic)

#include <stdio.h>
#define MAX 5
#define ENQ 1
#define DEQ 2

#define _CRT_SECURE_NO_WARNINGS

struct Queue{
    int front;
    int rear;
    int lastOp;
    int data[MAX];
};

int isFull(struct Queue * p);
int isEmpty(struct Queue * p);
void enqueue(struct Queue * p, int data);
int dequeue(struct Queue * p);
void printQ(struct Queue * p);

int main(){
    struct Queue q;
    q.front = 0;
    q.rear = 0;
    q.lastOp = 0;

    printf("%d\n",q.data[1]);

    for (int i = 1; i <= 6; i++){
        enqueue(&q,i*10);
    }
    printQ(&q);

    printf("%d \n", dequeue(&q));
    enqueue(&q, 60);
    printQ(&q);

    for (int i = 0; i < 7; i++){ printf("%d \n", dequeue(&q)); }
    for (int j = 1; j < 7; j++){ enqueue(&q, j*10); }

    printQ(&q);

    printf("%d - %d - %d - %d - %d \n",q.data[0],q.data[1],q.data[2],q.data[3],q.data[4]);
    printf("front : %d, rear : %d\n",q.front, q.rear);

    return 0;
}

int isFull(struct Queue * p){
    if (p->front == p->rear && p->lastOp == ENQ) return 1;
    return 0;
}
int isEmpty(struct Queue * p){
    if (p->front == p->rear && p->lastOp == DEQ){ // p->lastOp != ENQ
        printf("Q is empty.\n");
        return 1;
    }
    return 0;
}
void enqueue(struct Queue * p, int data){
    if (!isFull(p)){
        printf("%d is queued. \n", data);
        p->rear = ((p->rear+1)%MAX);
        p->data[p->rear] = data;
        p->lastOp = ENQ;
    }else{ printf("Can't enqueue. It's full. \n"); }
}
int dequeue(struct Queue * p){
    if (!isEmpty(p)){
        printf("DeQ.\n");
        p->lastOp = DEQ;
        int tmp = (p->front+1)%MAX;
        p->front = ((p->front+1)%MAX);
        return p->data[tmp];
    }
    return 0;
}
void printQ(struct Queue * p){
    int numberOfQ;
    numberOfQ = p->rear > p->front ? p->rear - p->front : (p->rear + MAX) - p->front;
    int index = p->front+1;
    for (int i = 0; i < numberOfQ; i++){
        printf("%d ", p->data[(index+i)%MAX]);
    }
    printf("\n");
}