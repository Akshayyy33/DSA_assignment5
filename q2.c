#include <stdio.h>
#include <stdlib.h>

struct NodeA {
    int val;
    struct NodeA *l, *r;
};

struct NodeA* rootA = NULL;

struct NodeA* createNew(int x) {
    struct NodeA* t = malloc(sizeof(struct NodeA));
    t->val = x;
    t->l = t->r = NULL;
    return t;
}

struct NodeA* insertNode(struct NodeA* root, int val) {
    if (!root) return createNew(val);

    if (val < root->val)
        root->l = insertNode(root->l, val);
    else
        root->r = insertNode(root->r, val);

    return root;
}

int totalNodes(struct NodeA* root) {
    if (!root) return 0;
    return 1 + totalNodes(root->l) + totalNodes(root->r);
}

int leafCount(struct NodeA* root) {
    if (!root) return 0;
    if (!root->l && !root->r) return 1;
    return leafCount(root->l) + leafCount(root->r);
}

int heightTree(struct NodeA* root) {
    if (!root) return -1;
    int lh = heightTree(root->l);
    int rh = heightTree(root->r);
    return (lh > rh ? lh : rh) + 1;
}

int main() {
    int choice, val;

    printf("\n--- Linked Binary Tree ---\n");
    printf("1.Insert  2.Total  3.Leaves  4.Height  5.Exit\n");

    while (1) {
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 5) break;

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                rootA = insertNode(rootA, val);
                break;
            case 2:
                printf("Total Nodes: %d\n", totalNodes(rootA));
                break;
            case 3:
                printf("Leaf Nodes: %d\n", leafCount(rootA));
                break;
            case 4:
                printf("Height: %d\n", heightTree(rootA));
                break;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
