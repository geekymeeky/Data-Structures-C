#include <stdio.h>

int inputArr(int arr[], int size)
{
    int i = 0;
    for (i = 0; i < size; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

void printArr(int arr[], int size)
{
    int i = 0;
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}

int linearSearch(int arr[], int size, int key)
{
    int i = 0;
    for (i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            printf("Elememnt %d found at position %d", key, i + 1);
            return (i + 1);
        }
        else if (i == size - 1)
        {
            printf("Element not found");
            return -1;
        }
    }
}

int main(int argc, char const *argv[])
{
    int pos, n, key, arr[100];
    printf("Enter the number of elements you want to enter: ");
    scanf("%d", &n);
    inputArr(arr, n);
    printArr(arr, n);
    printf("\nEnter the element you want to search: ");
    scanf("%d", &key);
    pos = linearSearch(arr, n, key);
    return 0;
}
