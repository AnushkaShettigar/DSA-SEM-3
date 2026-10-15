/*Implementation of any one Sorting Technique considering a real-world
application.*/

#include <stdio.h>

int main()
{
    int a[5], i, j, temp;

    printf("Enter 5 students' marks: ");
    for (i = 0; i < 5; i++)
        scanf("%d", &a[i]);

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 4 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    printf("Sorted marks: ");
    for (i = 0; i < 5; i++)
        printf("%d ", a[i]);

    return 0;
}