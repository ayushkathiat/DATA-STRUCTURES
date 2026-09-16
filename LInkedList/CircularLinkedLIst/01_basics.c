#include <Stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

// TRAVERSAL IN CIRCULAR LINKED LIST
void linkedListTraversal(struct Node *head){
    struct Node *ptr = head;
    do{
        printf("ELE is : %d\n", ptr->data);
        ptr = ptr->next;
    }while(ptr != head);
}

// INSERTION IN CIRCULAR LINKED LIST CASE1
struct Node *insertionAtFirst(struct Node *head, int data){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head->next;
    while(p->next != head && head->next != ptr){ 
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
}
// INSERTION CASE2
struct Node * insertionAtIndex(struct Node *head, int data , int index){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head->next;
    int i = 0;
    while(i != index-1){
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    p->next = ptr;
    return head;
}
// INSERTION CASE3
struct Node *insertionAtEnd(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head->next;
    while(p->next != head){
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
    return head;
};
// INSERTION CASE4
struct Node * insertAtValue(struct Node *head, int data, int value)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head->next;
    while(p->data != value){
        p = p->next;
    }
    ptr->next = p->next;
    p->next = ptr;
    return head;
};

// DELETION IN LINKED LIST CASE 1
struct Node *deletionAtFirst(struct Node *head)
{
    struct Node *ptr = head;
    struct Node *p = head->next;
    while(p->next != head){
        p = p->next;
    }
    head = head->next;
    p->next = head;
    free(ptr);
    return head;
};
// CASE 2
struct Node *deletionAtIndex(struct Node *head, int index){
    struct Node *ptr = head;
    struct Node *p = ptr->next;
    int i = 0;
    while(i != index-1){
        ptr = ptr->next;
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    free(p);
    return head;
}
// CASE 3
struct Node *deletionAtEnd(struct Node *head){
    struct Node *ptr = head;
    struct Node *p = head->next;
    while(p->next != head){
        ptr = ptr->next;
        p = p->next;
    }
    ptr->next = head;
    free(p);
    return head;
}
// CASE 4
struct Node *deletionAtValue(struct Node *head, int value){
    struct Node *ptr = head;
    struct Node *p = ptr->next;
    while(p->data != value && p->next != head){
        ptr = ptr->next;
        p = p->next;
    }
    if(p->data == value){
       ptr->next = p->next;
       free(p);
    }
    return head;
}

int main(){
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // ALLOCATION
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // LINK FIRST AND SECONT
    head->data = 2;
    head->next = second;

    // LINK SECOND AND THIRD
    second->data = 4;
    second->next = third;

    // LINK THIRD AND FOURTH
    third->data = 6;
    third->next = fourth;

    // LINK FOURTH AND NULL
    fourth->data = 8;
    fourth->next = head;

    printf("Linkedlist before INsertion\n");
    linkedListTraversal(head);

    printf("\nLinkedlist after INsertion\n");
    //head = insertionAtFirst(head, 10);
    // head = insertionAtIndex(head, 20, 1);
    // head = insertionAtEnd(head, 30);
    // head = insertAtValue(head, 40, 6);
    linkedListTraversal(head);

    printf("\nLinkedlist after Deletion\n");
    // head = deletionAtFirst(head);
    // head = deletionAtIndex(head, 1);
    // head = deletionAtEnd(head);
    head = deletionAtValue(head, 4);
    linkedListTraversal(head);

    return 0;
}