/*Implementation of Binary Search Technique considering a real-world
application.*/

#include <stdio.h>

int main()
{
    int a[5] = {101, 102, 103, 104, 105};
    int key, low = 0, high = 4, mid;

    printf("Enter roll number to search: ");
    scanf("%d", &key);

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (a[mid] == key)
        {
            printf("Student found at position %d", mid + 1);
            return 0;
        }
        else if (a[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    printf("Student not found");

    return 0;
}