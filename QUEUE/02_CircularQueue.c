#include <stdio.h>
#include <stdlib.h>

struct CircularQueue{
    int f,r;
    int size;
    int *arr;
};

int isFull(struct CircularQueue *q){
    if((q->r+1)%q->size==q->f){
        return 1;
    }
    return 0;
}

int isEmpty(struct CircularQueue *q){
    if(q->f==q->r){
        return 1;
    }
    return 0;
}

void Enqueue(struct CircularQueue *q, int val){
    if((q->r+1)%q->size==q->f){
        printf("QUeue is overflow!\n");
    }
    else{
        q->r=(q->r+1)%q->size;
        q->arr[q->r] = val;
        printf("Enqued ele is : %d\n", val);
    }
}

int Dequeue(struct CircularQueue *q){
    int val = -1;
    if(q->f==q->r){
        printf("QUeue is Underflow!\n");
    }
    else{
        q->f = (q->f+1)%q->size;
        val = q->arr[q->f];
    }
    return val;
}

int main(){

    struct CircularQueue *q = (struct CircularQueue *)malloc(sizeof(struct CircularQueue));
    q->f = q->r = 0;
    q->size = 4;
    q->arr = (int *)malloc(q->size*sizeof(int));

    Enqueue(q,12);
    Enqueue(q,1);
    Enqueue(q,2);
    Enqueue(q,123);
    Enqueue(q,1234);
    printf("Dequeue ele is : %d\n", Dequeue(q));
    printf("Dequeue ele is : %d\n", Dequeue(q));
    printf("Dequeue ele is : %d\n", Dequeue(q));

    if(isEmpty(q)){
        printf("Queue is EMpty!\n");
    }
 
    if(isFull(q)){
        printf("Queue is Full!\n");
    }


    return 0;
}