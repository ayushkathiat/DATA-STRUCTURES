#include <Stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node* top = NULL;


void StackTraversal(struct Node *ptr){
    while(ptr != NULL){
        printf("Ele is : %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node* push(struct Node *top, int s){
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if(n == NULL){
        printf("Stack is overflow!");
    }else{
        n->data = s;
        n->next = top;
        top = n;
    }
}

int pop(struct Node* tp ){
    if(tp == NULL){
        printf("Stack is Underflow!");
    }else{
    struct Node *n = tp;
        top = tp->next;
        int x = n->data;
        free(n);
        return x;
    }
} 

int peek(struct Node *top){
    if(top == NULL){
        printf("stack is Underflow!");
        return -1;
    }else{
        struct Node *ptr = top;
        int i = 0;
        while(i < pos-1 && ptr != NULL){
            i++;
        }
        
        top = top->data;


    }

}

int isEmpty(struct Node *top){
    if(top == NULL){
        printf("Stack is empty");
        return 1;
    }
    else return 0;
}

int isFull(struct Node *top){
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if(n == NULL){
        printf("Stack is FUll!");
        return 1;
    }
    else return 0;
}

int main(){
    top = push(top, 10);
    top = push(top, 20);
    top = push(top, 30);
    StackTraversal(top);

    int element = pop(top);
    printf("Poped ele is : %d\n", element);
    StackTraversal(top);

    return 0;
}
