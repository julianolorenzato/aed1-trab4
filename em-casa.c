#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y)
{
    int temp = *y;
    *y = *x;
    *x = temp;
}

int partition(int *arr, int start, int end)
{
    int pivot = arr[end];

    int middle = start;
    int curr = start;
    while (curr < end)
    {
        if (arr[curr] <= pivot)
        {
            swap(&arr[curr], &arr[middle]);
            middle++;
        }

        curr++;
    }

    swap(&arr[middle], &arr[end]);

    return middle;
}

void quick_sort(int *arr, int start, int end)
{
    if (start < end)
    {
        int pivot_index = partition(arr, start, end);

        quick_sort(arr, start, pivot_index - 1);
        quick_sort(arr, pivot_index + 1, end);
    }
}

int *topKFrequent(int *nums, int numsSize, int k, int *returnSize)
{
    *returnSize = k;

    quick_sort(nums, 0, numsSize - 1);

    int *res = (int *)calloc(k, sizeof(int));
    int *frequencies = (int *)calloc(k, sizeof(int));

    int curr = 0;
    int curr_frequency = 0;

    // res[0] = curr;
    // frequencies[0] = curr_frequency;

    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] != curr)
        {
            curr = nums[i];
            curr_frequency = 1;
        }
        else
        {
            curr_frequency++;
        }

        // test and change frequencies
        for (int i = 0; i < k; i++)
        {
            if (frequencies[i] < curr_frequency)
            {
                res[i] = curr;
                frequencies[i] = curr_frequency;
                break;
            }
        }
    }

    return res;
}

int main(int argc, char const *argv[])
{
    int returnSize;

    int arr1[6] = {1, 1, 1, 2, 2, 3};
    int *res1 = topKFrequent(arr1, 6, 2, &returnSize);
    for (int i = 0; i < returnSize; i++)
    {
        printf("%d \n", res1[i]);
    }

    printf("\n");

    int arr2[1] = {1};
    int *res2 = topKFrequent(arr2, 1, 1, &returnSize);
    for (int i = 0; i < returnSize; i++)
    {
        printf("%d \n", res2[i]);
    }

    printf("\n");

    int arr3[4] = {0, 3, 0, 1};
    int *res3 = topKFrequent(arr3, 4, 3, &returnSize);
    for (int i = 0; i < returnSize; i++)
    {
        printf("%d \n", res3[i]);
    }

    return 0;
}
