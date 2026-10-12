#include <stdio.h>

int b_search(int a[], int l, int r, int key) {
    int mid;
    while (l <= r) {
        mid = l + (r - l) / 2;
        if (key == a[mid]) {
            return mid;
        } else if (key > a[mid]) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return -1;
}

int main() {
    int a[10], n, i, key, result;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements in ascending order: \n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    printf("Enter key to search: ");
    scanf("%d", &key);
    result = b_search(a, 0, n - 1, key);
    if (result != -1) {
        printf("Element %d found at position %d\n", key, result + 1);
    } else {
        printf("Element %d not found\n", key);
    }
    return 0;
}