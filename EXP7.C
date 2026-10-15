/*Implementation of any one Graph Traversal Technique for real-world application.*/

#include <stdio.h>

int main()
{
    int a[5][5] = {
        {0,1,1,0,0},
        {1,0,0,1,0},
        {1,0,0,1,1},
        {0,1,1,0,1},
        {0,0,1,1,0}
    };

    int visited[5] = {0};
    int q[5], front = 0, rear = 0;
    int i, v;

    q[rear++] = 0;
    visited[0] = 1;

    printf("BFS Traversal: ");

    while (front < rear)
    {
        v = q[front++];
        printf("%d ", v);

        for (i = 0; i < 5; i++)
        {
            if (a[v][i] == 1 && visited[i] == 0)
            {
                q[rear++] = i;
                visited[i] = 1;
            }
        }
    }

    return 0;
}