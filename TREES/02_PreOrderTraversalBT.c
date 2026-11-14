#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data){
    struct node *n;
    n = (struct node *) malloc (sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
};

void PreOrder(struct node *root){
    if(root != NULL){
        printf("%d ", root->data);
        PreOrder(root->left);
        PreOrder(root->right);
    }
}

int main(){

    struct node * p = createNode(10);
    struct node * p1 = createNode(1);
    struct node * p2 = createNode(2);
    struct node * p3 = createNode(3);
    struct node * p4 = createNode(4);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    PreOrder(p);

    return 0;
}


// #include <stdio.h>
// #include <stdlib.h>

// struct node {
//     int data;
//     struct node *left;
//     struct node *right;
// };

// struct node *createNode(int data) {
//     struct node *n;
//     n = (struct node *)malloc(sizeof(struct node));

//     n->data = data;
//     n->left = NULL;
//     n->right = NULL;

//     return n;
// }

// // Iterative Preorder Traversal
// void PreOrder(struct node *root) {

//     struct node *stack[100];
//     int top = -1;

//     if (root == NULL)
//         return;

//     stack[++top] = root;

//     while (top != -1) {

//         struct node *temp = stack[top--];

//         printf("%d ", temp->data);

//         if (temp->right != NULL) {
//             stack[++top] = temp->right;
//         }

//         if (temp->left != NULL) {
//             stack[++top] = temp->left;
//         }
//     }
// }

// int main() {

//     struct node *p = createNode(10);
//     struct node *p1 = createNode(1);
//     struct node *p2 = createNode(2);
//     struct node *p3 = createNode(3);
//     struct node *p4 = createNode(4);

//     p->left = p1;
//     p->right = p2;

//     p1->left = p3;
//     p1->right = p4;

//     PreOrder(p);

//     return 0;
// }


