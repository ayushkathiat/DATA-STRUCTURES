#include <stdio.h>
#include <stdlib.h>

struct Stack{
    int size;
    int top;
    int *arr;
};
void push(struct Stack *s, int value){
    if(s->top == s->size-1){
        printf("Stack is full\n");
        return;
    }
    else{
        s->top++;
        s->arr[s->top] = value;
        printf("Pushed Sucessfully : %d\n", value);
    }
}
void pop(struct Stack *s){
    if(s->top == -1){
        printf("Stack is empty\n");
    }
    else{
        printf("\nPoped sucessfully : %d\n", s->arr[s->top]);
        s->top--;
    }
}
int peek(struct Stack *s){
    if(s->top == -1){
        printf("stack is empty");
        return -1;
    }else{
        printf("\n%d : is the peek value \n", s->arr[s->top]);
        return s->arr[s->top];
    }
}
int isEmpty(struct Stack *s){
    if(s->top == -1){
        printf("Stack is empty!");
        return 1;
    }
    else{
        printf("Stack is not Empty");
        return 0;
    }
}
int isFull(struct Stack *s){
    if(s->top == s->size-1){
        printf("Stack is Overflow");
        return 1;
    }
    else{
        printf("Stack is not Full!");
        return 0;
    }
}
void diaplay(struct Stack *s, int index){
    if(s->top == -1){
        printf("Stack is Underflow");
    }
    else{
        for(int i = index; i >= 0; i--){
            printf("\n%d", s->arr[i]);
        }
    }
}

int main(){
    struct Stack *s = (struct Stack *)malloc(sizeof(struct Stack));  // 🔧 fix: struct ke liye memory allocate ki

    //s->size = 6;
    printf("Enter stack size: ");
    scanf("%d", &s->size);
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    int choice, value;
    do{
        printf("\n1. Push\n2. Pop\n3. Peek\n4. isEmpty\n5. isFull\n6. Display\n7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(s, value);
                break;
            case 2:
                pop(s);
                break;
            case 3:
                peek(s);
                break;
            case 4:
                isEmpty(s);
                break;
            case 5:
                isFull(s);
                break;
            case 6:
                diaplay(s, s->top);
                break;
            case 7:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice != 7);

    free(s->arr);
    free(s);
    return 0;
}