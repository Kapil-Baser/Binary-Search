#include <stdio.h>
/**
 * @brief Searches for a given value in a sorted array.
 * 
 * @array array to search in.
 * @size size of array.
 * @value to search for.
 * 
 * @return Index of value if found, -1 otherwise.
*/
int binary_search(int array[], int size, int value);
/**
 * @brief Recursive binary search.
 * 
 * @array array to search in.
 * @start_idx starting index of array.
 * @end_idx last index of array.
 * @value value to search for.
 * 
 * @return Index of value if found, -1 otherwise.
*/
int binary_search_recursive(int array[], int start_idx, int end_idx, int value);

int main(void)
{
    int arr[10] = {3, 17, 75, 80, 202, 240, 301, 320, 420, 690};

    printf("Value found at index [%d]\n", binary_search(arr, 10, 6));

    printf("Value found at index [%d]\n", binary_search_recursive(arr, 0, 9, 80));

    return 0;
}
int binary_search(int array[], int size, int value)
{
    /**
     * First, we establish the starting index and end index of where the value we are
     * searching for can be.
    */
    int start_idx = 0;
    int end_idx = size - 1;
    /**
     * We begin a loop in which we keep inspecting the middlemost value between starting
     * index and end index.
    */
    while (start_idx <= end_idx)
    {
        /**
         * We start with calculating the midpoint of the array.
        */
        int midpoint = (end_idx + start_idx) / 2;
        /**
         * If the value at midpoint is the one we are looking for, we are done.
        */
        if (value == array[midpoint])
        {
            return midpoint;
        }
        /**
         * If not, then we change the starting or end index based on whether we
         * need to search in upper half or lower half of the array.
        */
        else if (value < array[midpoint])
        {
            
            end_idx = midpoint - 1;
        }
        else if (value > array[midpoint])
        {
            start_idx = midpoint + 1;
        }
    } 

    return -1;
}

int binary_search_recursive(int array[], int start_idx, int end_idx, int value)
{
    if (start_idx <= end_idx)
    {
        int midpoint = start_idx + (end_idx - start_idx) / 2;

        if (value == array[midpoint])
        {
            return midpoint;
        }

        if (value < array[midpoint])
        {
            return binary_search_recursive(array, start_idx, midpoint - 1, value);
        }
        else
        {
            return binary_search_recursive(array, midpoint + 1, end_idx, value);
        }
    }
    return -1;
}
