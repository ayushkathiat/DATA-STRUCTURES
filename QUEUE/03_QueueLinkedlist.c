#include <stdio.h>
#include <stdlib.h>

struct Node{
    int size;
    int f,r;
    int *arr;
    int data, next;
};

int isFULL(struct Node *n){
    if(n == NULL){
        return 1;
    } return 0;
}

int isEmpty(struct Node *f){
    if(f == NULL){
        return 1;
    } return 0;
}

void Enqueue(struct Node *f, struct Node *r, int val){
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if(n == NULL){
        printf("Queue is FULL!");
    } 
    else{
        n->data = val;
        n->next = NULL;
        if(f == NULL){
            f = r = n;
        }
        else{
            r->next = n;
            r = n;
        }
    }
}

int Dequeue(struct Node *f){
    int val = -1;
    struct Node *ptr = f;
    if(f == NULL){
        printf("QUeue is empty!");
    }
    else{
        f = f->next;
        val = ptr->data;
        free(ptr);
    } return val;
}
               
int main(){

    struct Node *r = NULL;
    struct Node *f = NULL;

    // LinkedListTraversal(f);
    // printf("Dequeing ele %d\n", Dequeue());
    // Enqueue(34);
    // Enqueue(4);
    // Enqueue(12);
    // printf("Dequeing ele %d\n", Dequeue());
    // printf("Dequeing ele %d\n", Dequeue());
    // LinkedListTraversal(f);

    return 0;
}
 