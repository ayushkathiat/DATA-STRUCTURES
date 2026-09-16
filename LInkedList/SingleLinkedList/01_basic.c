#include <Stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

// TRAVERSAL IN LINKED LIST
void linkedListTraversal(struct Node *ptr){
    while(ptr != NULL){
        printf("Ele : %d\n", ptr->data);
        ptr = ptr->next;
    }
}

// INSERTION IN LINKED LIST CASE1
struct Node *insertAtFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->next = head;
    ptr->data = data;
    head = ptr;
    return head;
};
// INSERTION CASE2
struct Node *insertInBetween(struct Node *head, int index, int data){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;
    while(i != index-1){
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
};
// INSERTION CASE3
struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head;
    while(p->next != NULL){
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
};
// INSERTION CASE4
struct Node *insertAfterNode(struct Node *head, int data, int value){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    ptr->data = data;
    while(p->data != value){
        p = p->next;
    }
    ptr->next = p->next;
    p->next = ptr;
    return head;
};

// DELETION IN LINKED LIST CASE 1
struct Node *deletionFirst(struct Node *head)
{
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
};
// CASE 2
struct Node *deletionAtIndex(struct Node *head, int index)
{
    struct Node *ptr = head;
    struct Node *p = head->next;
    int i = 0;
    while(i < index-1){
        ptr = ptr->next;
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    free(p);
    return head;
};
// CASE 3
struct Node *deletionAtEnd(struct Node *head)
{
    struct Node * ptr = head;
    struct Node *p = head->next;
    while(p->next != NULL){
        ptr = ptr->next;
        p = p->next;
    }
    ptr->next = NULL;
    free(p);
    return head;
};
// CASE 4
struct Node *deletingValue(struct Node *head, int value)
{
    struct Node *ptr = head;
    struct Node *p = ptr->next;
    while(p->data != value && p->next != NULL){
        ptr = ptr->next;
        p = p->next;
    }
    if(p->data == value){
        ptr->next = p->next;
        free(p);
    }

    return head;
};

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
    fourth->next = NULL;

    printf("Linkedlist before INsertion\n");
    linkedListTraversal(head);


    // INSERTION
    printf("\nlinked list after insertion\n");
    //head = insertAtFirst(head, 10);
    // head = insertInBetween(head, 3, 20);
    //head = insertAtEnd(head, 30);
    head = insertAfterNode(head, 40, 6);
    linkedListTraversal(head);

    // // DELETION
    // printf("\n Linked list after deletion \n");
    // //head = deletionFirst(head);
    // //head = deletionAtIndex(head, 2);
    // // head = deletionAtEnd(head);
    head = deletingValue(head, 6);
    // linkedListTraversal(head);

    return 0;
}