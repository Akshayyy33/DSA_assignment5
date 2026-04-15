#include <stdio.h>
#include <stdlib.h>

struct NodeD {
    int val;
    struct NodeD *l, *r;
};

struct NodeD* create(int x) {
    struct NodeD* t = malloc(sizeof(struct NodeD));
    t->val = x;
    t->l = t->r = NULL;
    return t;
}

struct NodeD* stack[100];
int top = -1;

void push(struct NodeD* n) { stack[++top] = n; }
struct NodeD* pop() { return stack[top--]; }

void inorderNR(struct NodeD* root) {
    struct NodeD* curr = root;
    printf("Inorder: ");

    while (curr || top != -1) {
        while (curr) {
            push(curr);
            curr = curr->l;
        }
        curr = pop();
        printf("%d ", curr->val);
        curr = curr->r;
    }
    printf("\n");
}

void preorderNR(struct NodeD* root) {
    printf("Preorder: ");
    push(root);

    while (top != -1) {
        struct NodeD* temp = pop();
        printf("%d ", temp->val);

        if (temp->r) push(temp->r);
        if (temp->l) push(temp->l);
    }
    printf("\n");
}

int main() {
    struct NodeD* root = create(1);
    root->l = create(2);
    root->r = create(3);

    int ch;

    printf("\n--- Non-Recursive Traversals ---\n");
    printf("1.Inorder  2.Preorder  3.Exit\n");

    while (1) {
        printf("\nEnter choice: ");
        scanf("%d", &ch);

        if (ch == 3) break;

        if (ch == 1) inorderNR(root);
        else if (ch == 2) preorderNR(root);
        else printf("Invalid choice\n");
    }
    return 0;
}
