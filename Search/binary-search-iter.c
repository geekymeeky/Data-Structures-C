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

int binarySearch(int arr[], int low, int high, int key)
{
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (key > arr[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    int idx, n, key, arr[100];
    printf("Enter the number of elements you want to enter: ");
    scanf("%d", &n);
    inputArr(arr, n);
    printArr(arr, n);
    printf("\nEnter the element you want to search: ");
    scanf("%d", &key);
    idx = binarySearch(arr, 0, n - 1, key);
    if (idx < 0)
        printf("Element not found!\n");
    else
        printf("\nElement present at index %d\n", idx);
    return 0;
}
