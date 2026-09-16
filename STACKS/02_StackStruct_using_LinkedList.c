#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct stack *next;
    int size;
    int top;
    int *arr;
};

struct Node *push(struct Node *s, int value)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if(s->top == s->size-1){
        printf("Stack is Overflow");
    }
    else{
        n->data = s;
        n->next = s->top;
        s->top = n;
    }
}

struct Node *pop(struct Node *s, int value)
{
    if(s->top == NULL){
        printf("Stack is Empty!");
        return 1;
    }
    else{
        printf("Poped sucessfullt : %d\n", value);
        s->top--;
    }
}


int main(){
    struct Node *s = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter the size of stack : ");
    scanf("%d", s->size);
    s->top = -1;
    s->arr = (int*)malloc(s->size * sizeof(int));

    int value, choice;
    do{
       printf("Enter the choice : ");
       scanf("%d", choice);
       printf("\n1. push\n2. pop\n3. peek\n4. isEmpty\n5. isFull\n6. Display\n7. Exit\n");
       switch (choice){
          case 1:
        printf("Enter the number you want to push : ");
        scanf("%d", value);
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
        Dsplay(s);
        break;
    case 7:
        printf("Exiting\n");
        break;
    default:
        printf("\nInvalid choice");
    }
    while(choice != 7);
    }
    return 0;
}