#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data)
{
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void Inorder(struct node *root)
{
    if (root != NULL)
    {
        Inorder(root->left);
        printf("%d ", root->data);
        Inorder(root->right);
    }
}

int isBST(struct node *root)
{
    static struct node *prev = NULL;
    if (root != NULL)
    {
        if (!isBST(root->left))
        {
            return 0;
        }
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else
        return 1;
}

void insert(struct node *root, int key)
{
    struct node *prev = NULL;

    while (root != NULL)
    {
        prev = root;

        if (key == root->data)
        {
            printf("Cannot insert %d, already in BST\n", key);
            return;
        }
        else if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }

    struct node *newNode = createNode(key);

    if (key < prev->data)
        prev->left = newNode;
    else
        prev->right = newNode;
}

int main()
{

    struct node *p = createNode(50);
    struct node *p1 = createNode(40);
    struct node *p2 = createNode(60);
    struct node *p3 = createNode(20);
    struct node *p4 = createNode(45);
    struct node *p5 = createNode(55);
    struct node *p6 = createNode(70);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    p2->left = p5;
    p2->right = p6;

    insert(p, 57);
    printf("%d ", p->right->right->data);

    return 0;
}