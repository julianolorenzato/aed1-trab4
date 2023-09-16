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
    int arr[6] = {1, 1, 1, 2, 2, 3};

    int returnSize;

    int *res = topKFrequent(arr, 6, 2, &returnSize);

    for (int i = 0; i < 2; i++)
    {
        printf("%d \n", res[i]);
    }

    return 0;
}
