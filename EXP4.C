/*Array Implementation of Double-ended Queue using Array for real-world
application.*/

#include <stdio.h>
#define MAX 5

int q[MAX], front = -1, rear = -1;

void insertRear(int x)
{
    if (rear == MAX - 1)
        printf("Queue Full\n");
    else
    {
        if (front == -1)
            front = 0;
        q[++rear] = x;
    }
}

void insertFront(int x)
{
    if (front == 0)
        printf("Cannot insert at front\n");
    else
    {
        if (front == -1)
            front = rear = 0;
        else
            front--;
        q[front] = x;
    }
}

void deleteFront()
{
    if (front == -1)
        printf("Queue Empty\n");
    else
    {
        printf("Deleted: %d\n", q[front]);
        if (front == rear)
            front = rear = -1;
        else
            front++;
    }
}

void display()
{
    int i;
    if (front == -1)
        printf("Queue Empty\n");
    else
    {
        for (i = front; i <= rear; i++)
            printf("%d ", q[i]);
        printf("\n");
    }
}

int main()
{
    insertRear(10);
    insertRear(20);
    insertFront(5);

    printf("Deque: ");
    display();

    deleteFront();

    printf("After deletion: ");
    display();

    return 0;
}