
#include <stdio.h>

int a[10][10], visited[10], n;

void DFS(int v) {
    int i;
    printf("%d ", v);
    visited[v] = 1;

    for (i = 0; i < n; i++) {
        if (a[v][i] == 1 && visited[i] == 0)
            DFS(i);
    }
}

void BFS(int start) {
    int q[10], front = 0, rear = 0;
    int i, v;

    for (i = 0; i < n; i++)
        visited[i] = 0;

    q[rear++] = start;
    visited[start] = 1;

    while (front < rear) {
        v = q[front++];
        printf("%d ", v);

        for (i = 0; i < n; i++) {
            if (a[v][i] == 1 && visited[i] == 0) {
                q[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int i, j, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    if (n < 1 || n > 10)
        return 1;

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    if (start < 0 || start >= n)
        return 1;

    for (i = 0; i < n; i++)
        visited[i] = 0;

    printf("DFS Traversal: ");
    DFS(start);

    printf("\nBFS Traversal: ");
    BFS(start);

    return 0;
}
