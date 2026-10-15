/*Implementation of Singly Linked List and various operations for real-world application.*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert()
{
    struct node *newnode, *temp;
    newnode = (struct node*)malloc(sizeof(struct node));

    printf("Enter student roll number: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;

    if (head == NULL)
        head = newnode;
    else
    {
        temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
    }
}

void delete()
{
    struct node *temp;

    if (head == NULL)
        printf("List is empty\n");
    else
    {
        temp = head;
        head = head->next;
        free(temp);
        printf("Student deleted\n");
    }
}

void display()
{
    struct node *temp = head;

    if (temp == NULL)
        printf("List is empty\n");
    else
    {
        while (temp != NULL)
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main()
{
    int ch;

    do
    {
        printf("\n1.Insert  2.Delete  3.Display  4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1: insert(); break;
            case 2: delete(); break;
            case 3: display(); break;
            case 4: break;
            default: printf("Invalid choice\n");
        }
    } while (ch != 4);

    return 0;
}