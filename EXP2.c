/*Write a program to implement a Linear Queue using an array.
Queue application to print an alert for heatwave prediction. 
Temperature>=40 deg print(Yellow Alert) (Enqueue Operation)
Temperature>=43 deg print(Orange Alert)  (Enqueue Operation)
Temperature>=45 deg print(Red Alert)  (Enqueue Operation)
Temperature<40 deg: remove all active alerts, Perform Dqueue Operation.
                              OR
1. Implement queue using array
2.  Design and implement a Temperature Reading Queue using C. The system receives temperature readings from a weather sensor, stores them using a queue, processes readings in FIFO order, and generates a heatwave alert when the temperature crosses a predefined threshold. */

#include <stdio.h>
#define MAX 5

int q[MAX], front = -1, rear = -1;

void enqueue(int t)
{
    if (rear == MAX - 1)
        printf("Queue is Full\n");
    else
    {
        if (front == -1)
            front = 0;
        q[++rear] = t;
        printf("Temperature: %d\n", t);

        if (t >= 45)
            printf("Red Alert\n");
        else if (t >= 43)
            printf("Orange Alert\n");
        else if (t >= 40)
            printf("Yellow Alert\n");
        else
            printf("No Heatwave Alert\n");
    }
}

void dequeue()
{
    if (front == -1 || front > rear)
        printf("Queue is Empty\n");
    else
    {
        printf("Removed Temperature: %d\n", q[front++]);
        if (front > rear)
            front = rear = -1;
    }
}

int main()
{
    int t, i, n;

    printf("Enter number of readings: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter temperature: ");
        scanf("%d", &t);

        if (t >= 40)
            enqueue(t);
        else
        {
            printf("Temperature below 40. Clearing alerts.\n");
            while (front != -1)
                dequeue();
        }
    }

    printf("\nProcessing remaining readings:\n");
    while (front != -1)
        dequeue();

    return 0;
}