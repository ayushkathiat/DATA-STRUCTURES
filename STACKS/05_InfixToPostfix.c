#include <Stdio.h>
#include <stdlib.h>
#include <string.h>

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
        char val = s->arr[s->top];
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

int precedence(char ch){
    if(ch == '*' || ch == '/') return 3;
    else if(ch == '+' || ch == '-') return 2;
    else return 0;
}

int stackTop(struct stack * s){
    if(s->top == -1) return 0;
    return s->arr[s->top];
}

int isOperator(char ch){
    if(ch == '*' || ch == '/' || ch == '+' || ch == '-') return 1;
    else return 0;
}

char * InToPostfix(char *infix){
    struct stack * sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    char * postfix = (char *)malloc((strlen(infix)+1) * sizeof(char));

    int i = 0; // track infix traversal
    int j = 0; // track postfix addition

    while(infix[i]!='\0'){
        if(!isOperator(infix[i])){
            postfix[j] = infix[i];
            i++;
            j++;
        }
        else{
            if(precedence(infix[i]) > precedence(stackTop(sp))){
                push(sp, infix[i]);
                i++;
            }
            else{
                postfix[j] = pop(sp);
                j++;
            }
        }
    }
        while(!isEmpty(sp)){
            postfix[j] = pop(sp);
            j++;
        }
        postfix[j] = '\0';
        return postfix;
    }


int main(){
  
    char *infix = "a+b*c/d";

    printf("Postfix is %s", InToPostfix(infix));

    return 0;
}