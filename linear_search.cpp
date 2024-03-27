#include<stdio.h>

// Function declaration
int linear_search(int a[], int n, int item);

int main() {
    int a[50], n, i, item, pos;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    printf("Enter elements into array as per size: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    printf("Enter item to search: ");
    scanf("%d", &item);
    pos = linear_search(a, n, item);
    if (pos == -1) {
        printf("Item not found.\n");
    } else {
        printf("Item found at position %d.\n", pos);
    }
    return 0;
}

// Function definition
int linear_search(int a[], int n, int item) {
    int pos = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] == item) {
            pos = i + 1; // Incrementing position to match human-readable indexing
            break;
        }
    }
    return pos;
}

