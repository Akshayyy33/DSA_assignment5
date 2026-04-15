#include <stdio.h>
#include <stdlib.h>

struct NodeC {
    int val;
    struct NodeC *l, *r;
};

struct NodeC* newNode(int x) {
    struct NodeC* t = malloc(sizeof(struct NodeC));
    t->val = x;
    t->l = t->r = NULL;
    return t;
}

struct NodeC* q[100];
int f = 0, r = 0;

void levelOrder(struct NodeC* root) {
    f = r = 0;
    q[r++] = root;

    printf("Level Order: ");

    while (f < r) {
        struct NodeC* temp = q[f++];
        printf("%d ", temp->val);

        if (temp->l) q[r++] = temp->l;
        if (temp->r) q[r++] = temp->r;
    }
    printf("\n");
}

int main() {
    struct NodeC* root = newNode(1);
    root->l = newNode(2);
    root->r = newNode(3);

    int ch;

    printf("\n--- Level Order ---\n");
    printf("1.Display  2.Exit\n");

    while (1) {
        printf("\nEnter choice: ");
        scanf("%d", &ch);

        if (ch == 2) break;

        if (ch == 1)
            levelOrder(root);
        else
            printf("Invalid choice\n");
    }
    return 0;
}
