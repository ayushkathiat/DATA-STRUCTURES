#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int top;
    int size;
    char *arr;
};

int parenthesisMatch(char * exp){
    struct stack *sp;
    sp->top = -1;   
    sp->size = 20;
    sp->arr = (char *)malloc(sp->size * sizeof(char));

    for(int i = 0; exp[i] != '\n'; i++){
        if(exp[i] == '('){
            push(sp, exp);
        }
        else if(exp[i] == '('){
            if(isEmpty(sp)){
                return 0;
            }
            pop(sp);
        }
    }
    if(isEmpty(sp)) return 1;
    else return 0;
}

char push(struct stack *s, int value){
    if(s->top == s->size-1){
        printf("Stack is overflow!");
    }
    else{
        s->top++;
        s->arr[s->size]=value;
    }
}

char pop(struct stack *s){
    if(s->top == -1){
        printf("Stack is underflow!");
    }else{
        s->top--;
    }
}

int isEmpty(struct stack *s){
    if(s->top==-1){
        printf("Stack is underflow!");
        return 1;
    }else{
        return 0;
    }
}

int isFull(struct stack *s){
    if(s->top == s->size-1){
        printf("Stack is overflow!");
        return 1;
    }
    else return 0;
}

int main(){

    char *exp = "(12*90+{2-10})";
 
    if(parenthesisMatch(exp)){
        printf("THe parenthesis is matching");
    }
    else{
        printf("THe parenthesis is not matching");
    }
}