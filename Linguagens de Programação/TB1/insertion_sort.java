import java.util.*;
import java.lang.*;
import java.io.*;

class Main
{
    public static void insertionSort(int[] arr)
    {        
        for (int i = 1; i < arr.length; ++i)
        {
            int key = arr[i];
            int j = i - 1;
            
            while (j >= 0 && arr[j] > key) 
            {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            
            arr[j + 1] = key;
        }
    }

    public static void printArray(String msg, int[] arr)
    {
        System.out.print(msg);
        
        for (int i = 0; i < arr.length; ++i)
            System.out.print(arr[i] + " ");
        
        System.out.println();
    }

    public static void main(String[] args) 
    {
        int arr[] = {12, 11, 13, 5, 6, 1, 25, 72, 40, 21};

        printArray("Unsorted: ", arr);

        insertionSort(arr);
    
        printArray("Sorted: ", arr);
    }
}
