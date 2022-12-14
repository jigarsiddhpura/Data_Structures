
#include <stdio.h>
#define Max 5
int f = -1;
int r = -1;
int a[Max];

// a = adjacency matrix , v = visited array

void insert(int val)
{
    if (r == Max - 1)
        printf("Overflow");
    else if (f == -1 && r == -1)
    {
        f = r = 0;
    }
    else
        r++;

    a[r] = val;
}

int delete()
{
    if (f == -1 && r == -1)
        return -10;
    else
    {
        int t = a[f];
        f++;
        if (f > r)
        {
            f = r = -1;
        }
        return t;
    }
}

int isempty()
{
    if (f == -1 && r == -1)
        return -10;
    else
    {
        return a[f];
    }
}

void display()
{
    if (f == -1 && r == -1)
        printf("Under flow");
    else
    {
        for (int i = f; i <= r; i++)
        {
            printf("%d\t", a[i]);
        }
    }
}

void main()
{
    int n = 5, v[100];
    // i is the start vertex
    int i ;
    int a[100][100];
    printf("Enter the size of matrix : ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter the %d row : ", i + 1);
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        v[i] = 0;
    }

    printf("Adjacency matrix : ");

    for (int i = 0; i < n; i++)
    {
        printf("\n");
        for (int j = 0; j < n; j++)
        {
            printf(" %d ", a[i][j]);
        }
    }

    printf("\nEnter the starting vertex : ");
    scanf("%d",&i);
    printf("%d", i);
    v[i] = 1;
    insert(i);
    while (isempty() != -10)
    {
        int node = delete ();
        for (int j = 0; j < n; j++)
        {
            if (a[node][j] == 1 && v[j] == 0)
            {
                printf("%d", j);
                v[j] = 1;
                insert(j);
            }
        }
    }
}
