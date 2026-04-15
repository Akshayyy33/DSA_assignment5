#include <stdio.h>

int treeArr[100];
int endPos = -1;

void insertVal() {
    int val;
    printf("Enter value: ");
    scanf("%d", &val);
    treeArr[++endPos] = val;
}

void displayVals() {
    if (endPos == -1) {
        printf("Tree is empty\n");
        return;
    }
    printf("Tree: ");
    for (int i = 0; i <= endPos; i++)
        printf("%d ", treeArr[i]);
    printf("\n");
}

void showRelation() {
    int idx;
    printf("Enter index: ");
    scanf("%d", &idx);

    if (idx > endPos || idx < 0) {
        printf("Invalid index\n");
        return;
    }

    printf("Node: %d\n", treeArr[idx]);

    if (idx != 0)
        printf("Parent: %d\n", treeArr[(idx - 1) / 2]);

    if (2 * idx + 1 <= endPos)
        printf("Left: %d\n", treeArr[2 * idx + 1]);

    if (2 * idx + 2 <= endPos)
        printf("Right: %d\n", treeArr[2 * idx + 2]);
}

int main() {
    int choice;

    printf("\n--- Array Binary Tree ---\n");
    printf("1.Insert  2.Display  3.Relations  4.Exit\n");

    while (1) {
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 4) break;

        switch (choice) {
            case 1: insertVal(); break;
            case 2: displayVals(); break;
            case 3: showRelation(); break;
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}
