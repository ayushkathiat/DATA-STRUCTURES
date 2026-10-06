#include <Stdio.h>
#include <stdlib.h>

struct stack{
    int size;
    int top;
    char *arr;
};

void push(struct stack *s, char value){
    if(s->top == s->size-1){
        printf("Stack is overflow!\n");
    }
    else{
        s->top++;
        s->arr[s->top] = value;
    }
}

char pop(struct stack *s){
    if(s->top == -1){
        printf("Stack is underflow!");
        return 0;
    }
    else{
        int val = s->arr[s->top];
        s->top--;
        return val;
    }
}

int isEmpty(struct stack *s){
    if(s->top == -1){
        return 1;
    }
    else return 0;
}

int isFull(struct stack *s){
    if(s->top == s->size-1) return 1;
    else return 0;
}

char InToPostfix(char *infix){

}

int main(){
  
    char *infix = " ";

    struct stack *s;
    s->top = -1;
    s->size = 100;
    s->arr = (char *)malloc(s->size * sizeof(char));

    return 0;
}