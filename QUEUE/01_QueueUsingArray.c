#include <stdio.h>
#include <stdlib.h>

struct queue{
    int size;
    int f, r;
    int *arr;
};

int isFull(struct queue *q){
    if(q->r==q->size-1){
        return 1;
    }
    else return 0;
}

int isEmpty(struct queue *q){
    if(q->f==q->r){
        return 1;
    }
    else return 0;
}

void enqueue(struct queue *q, int value){
    if(q->r==q->size-1){
        printf("Queue is Overflow!");
    }
    else{
        q->r++;
        q->arr[q->r] = value;
    }
}

int dequeue(struct queue *q){
    int a = -1;
    if(q->f==q->r){
        printf("Queue is Underflow!");
    }
    else{
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}

int main(){
    struct queue *q;
    q->size = 10;
    q->f, q->r = -1;
    q->arr = (int *)malloc(q->size * sizeof(int));

    if(isEmpty(q)){
        printf("Queue is EMpty!");
    }

    return 0;
}
