#include <stdio.h>      // FIX 1: Stdio.h -> stdio.h (lowercase)
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

void push(struct stack *s, char value)   // FIX 2: return type char -> void (kuch return nahi karta)
{
    if (s->top == s->size - 1)
    {
        printf("Stack is overflow!\n");
    }
    else
    {
        s->top++;
        s->arr[s->top] = value;          // FIX 3: s->size -> s->top
    }
}

char pop(struct stack *s)
{
    if (s->top == -1)
    {
        printf("Stack is Underflow!\n");  // FIX 4: \n add kiya
        return 0;                         // FIX 5: underflow case mein bhi value return karo
    }
    else
    {
        char val = s->arr[s->top];        // FIX 6: s->size -> s->top
        s->top--;
        return val;
    }
}

int isEmpty(struct stack *s)
{
    if(s->top == -1){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(struct stack *s)
{
     if (s->top == s->size - 1)
        return 1;
    else
        return 0;
}

int Match(char a, char b)
{
    if (a == '(' && b == ')')
    {
        return 1;
    }
    if (a == '{' && b == '}')
    {
        return 1;
    }
    if (a == '[' && b == ']')
    {
        return 1;
    }
    return 0;
}

int MultipleParenthesis(char *exp)
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));  // FIX 7: struct ke liye memory allocate ki
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    char poped_ch;

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(sp, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (isEmpty(sp))
            {
                return 0;
            }
            poped_ch = pop(sp);
            if(!Match(poped_ch, exp[i]))
            {
                return 0;
            }
        }
    }   // FIX 9: for loop yahan band hota hai (pehle ye } neeche tha)

    // FIX 10: ye final check ab loop ke BAHAR hai
    int result = isEmpty(sp);
    return result;
}

int main()
{
    char *exp = "(12*90+{2-10})[9+{8}]";

    if (MultipleParenthesis(exp))
    {
        printf("The parenthesis is matching!");
    }
    else
    {
        printf("Parenthesis does not match!");
    }

    return 0;
}