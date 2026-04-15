#include <stdio.h>
#include <stdlib.h>

struct NodeB {
    int data;
    struct NodeB *l, *r;
};

struct NodeB* create(int x) {
    struct NodeB* t = malloc(sizeof(struct NodeB));
    t->data = x;
    t->l = t->r = NULL;
    return t;
}

void inorder(struct NodeB* root) {
    if (root) {
        inorder(root->l);
        printf("%d ", root->data);
        inorder(root->r);
    }
}

void preorder(struct NodeB* root) {
    if (root) {
        printf("%d ", root->data);
        preorder(root->l);
        preorder(root->r);
    }
}

void postorder(struct NodeB* root) {
    if (root) {
        postorder(root->l);
        postorder(root->r);
        printf("%d ", root->data);
    }
}

int main() {
    struct NodeB* root = create(1);
    root->l = create(2);
    root->r = create(3);

    int ch;

    printf("\n--- Traversals ---\n");
    printf("1.Inorder  2.Preorder  3.Postorder  4.Exit\n");

    while (1) {
        printf("\nEnter choice: ");
        scanf("%d", &ch);

        if (ch == 4) break;

        if (ch == 1) {
            printf("Inorder: ");
            inorder(root);
        }
        else if (ch == 2) {
            printf("Preorder: ");
            preorder(root);
        }
        else if (ch == 3) {
            printf("Postorder: ");
            postorder(root);
        }
        else {
            printf("Invalid choice");
        }
        printf("\n");
    }
    return 0;
}
