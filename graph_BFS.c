#include <stdio.h>
#include <conio.h>
#define max 30
int adj_mat[20][20], queue[max], n, rear = -1, front = -1;
int visited[max];

void deque();
void enque(int val);

void BFS(int v)
{
    while (front != -1)
    {
        deque(v);
        printf("%d ", v);
        visited[v] = 1;

        for (int i = 1; i <= n; i++)
            if (adj_mat[v][i])
            {
                enque(i);
                // printf("enque of %d \n", i);
            }
        for (int i = front; i <= rear; i++)
        {
            BFS(queue[i]);
        }
    }
}

void enque(int val)
{
    if (rear == max - 1)
    {
        printf("queue overflow");
    }
    else if (front == -1)
    {
        front++;
    }
    rear++;
    queue[rear] = val;
}

void deque()
{
    if (front == -1)
    {
        printf("queue underflow");
    }
    else if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front++;
    }
}

void main()
{
    int i, j, count = 0;
    printf("\n Enter number of vertices:");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        visited[i] = 0;
        for (j = 1; j <= n; j++)
            adj_mat[i][j] = 0;
    }

    // printf("\n Enter the adjacency matrix:\n");
    // for (i = 1; i <= n; i++)
    //     for (j = 1; j <= n; j++)
    //         scanf("%d", &adj_mat[i][j]);

    int adj_mat[5][5] = {
        {0,1,0,0,1},
        {1,0,1,1,0},
        {0,1,0,0,0},
        {0,1,0,0,0},
        {1,0,0,0,0}
    };

    enque(1);
    BFS(1);
    printf("\n");

    for (i = 1; i <= n; i++)
    {
        if (visited[i])
            count++;
    }
    if (count == n)
        printf("\n Graph is connected");
    else
        printf("\n Graph is not connected");
}