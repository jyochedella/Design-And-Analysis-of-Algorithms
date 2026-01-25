//CH.S.U4CSE24107
#include <stdio.h>
#include <stdlib.h>

#define RED 1
#define BLACK 0

/* Red-Black Tree Node */
struct Node {
    int data;
    int color;
    struct Node *left, *right, *parent;
};
struct Node *root = NULL;

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->color = RED;   
    node->left = node->right = node->parent = NULL;
    return node;
}
void leftRotate(struct Node* x) {
    struct Node* y = x->right;
    x->right = y->left;

    if (y->left != NULL)
        y->left->parent = x;

    y->parent = x->parent;

    if (x->parent == NULL)
        root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;

    y->left = x;
    x->parent = y;
}

void rightRotate(struct Node* y) {
    struct Node* x = y->left;
    y->left = x->right;

    if (x->right != NULL)
        x->right->parent = y;

    x->parent = y->parent;

    if (y->parent == NULL)
        root = x;
    else if (y == y->parent->left)
        y->parent->left = x;
    else
        y->parent->right = x;

    x->right = y;
    y->parent = x;
}

void fixInsert(struct Node* z) {

    while (z != root && z->parent->color == RED) {

        if (z->parent == z->parent->parent->left) {

            struct Node* y = z->parent->parent->right; // Uncle

            if (y != NULL && y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            }
            else {
                if (z == z->parent->right) {
                    z = z->parent;
                    leftRotate(z);
                }

                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                rightRotate(z->parent->parent);
            }
        }

        else {

            struct Node* y = z->parent->parent->left; // Uncle

            if (y != NULL && y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            }
            else {
                if (z == z->parent->left) {
                    z = z->parent;
                    rightRotate(z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                leftRotate(z->parent->parent);
            }
        }
    }

    root->color = BLACK;
}

void insert(int data) {

    struct Node* z = newNode(data);
    struct Node* y = NULL;
    struct Node* x = root;

    while (x != NULL) {
        y = x;
        if (z->data < x->data)
            x = x->left;
        else
            x = x->right;
    }

    z->parent = y;

    if (y == NULL)
        root = z;
    else if (z->data < y->data)
        y->left = z;
    else
        y->right = z;

    fixInsert(z);
}
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d(%s) ", root->data,
               root->color == RED ? "R" : "B");
        inorder(root->right);
    }
}

int main() {

    int values[] = {157,110,147,122,111,149,151,141,123,112,117,133};
    int n = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < n; i++)
        insert(values[i]);

    printf("Inorder traversal of Red-Black Tree:\n");
    inorder(root);

    return 0;
}
