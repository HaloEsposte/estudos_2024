#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int arr[], int n)
{
    int i = 0; 
    int j = 0;
    int k = 0;
    
    for (i = 1; i < n; i++)
    {
        k = arr[i];
        j = i - 1;
        
        while (j >= 0 && arr[j] > k)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        
        arr[j + 1] = k;
    }
}

void print_array(const char* msg, int arr[], int n)
{
    int i = 0;

    printf("%s", msg);
    
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    
    printf("\n");
}

int main(int argc, char** argv) 
{
    int arr[] = {12, 11, 13, 5, 6, 1, 25, 72, 40, 21};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    print_array("Unsorted: ", arr, n);

    insertion_sort(arr, n);
    
    print_array("Sorted: ", arr, n);
    
    return EXIT_SUCCESS;
}
