#include <iostream>
using namespace std;

/*
    Tip ** Write down the entire solution of code in notebook and verify if "your" code matches each line of your answer
*/

void Merge_sort(int arr[],const int len)
{
   if(len > 1)
   {
        int mid = len / 2;  // Division does not round off value 
        // eg 7/2 = 3

        if(len !=2) // for length == 2 dont round off
        {
            if(mid % 2 != 0) // if length is odd and greater than 2 round off to next integer
            {
                mid ++; 
            }
        }

        int* left;  //left array [alloted dynamically]
        int* right; //right array [alloted dynamically]


        if(len % 2 != 0) // if length of array is odd
        {
            left = new int[len - mid  + 1];
            right = new int [len - mid];
        }

        else // if length of array is even
        {
            left = new int[len - mid];
            right = new int[len - mid];
        }


        int x = 0;  // index of array

        if(len > 2)
        {
        for(int i = 0; i < mid; i++) // left part of the array from (0:mid-1)
        {
            left[i] = arr[x];
            x++;
        }

        for(int j=0; j < len-mid; j++) // right part of the array from (mid: last)
        {
            right[j] = arr[x];
            x++;
        }
    }
    else // if length of array is 2 , then left and right will both have only 1 element each
    {
        int i=0;
        left[i] = arr[x];
        x++;
        right[i] = arr[x];
        x++;
    }

        // We use  Recursion here

        Merge_sort(left,mid); //Apply merge sort on left array

        Merge_sort(right,len-mid); // Apply merge sort on right array

        int i, j, k;

        i=j=k=0;

        while(i < (mid) && j < (len - mid))
        {
            if(left[i] <= right[j]) // Compare elements from left and right array and rearrange "array"
            {
                arr[k] = left[i];
                i++;
                k++;
            }
            else
            {
                arr[k] = right[j];
                j++;
                k++;
            }
        }

        // Add left off element to array either from left/right array

        while(i < mid)
        {
            arr[k] = left[i];
            i++;k++;
        }
        
        while(j < (len - mid))
        {
            arr[k] = right[j];
            j++;k++;
        }

        delete [] left; // Free memory after usage
        delete [] right;
   }
        
}

int main()
{
    int * arr;
    int size;

    cout << "Enter size of array : ";
    cin >> size;

    arr = new int [size];

    for(int i=0;i<size;i++)
    {
        int x;
        cout << "\nEnter element no " << i+1 << " : ";
        cin >> x;
        arr[i] = x;
    }

    cout << "Original Array : " << endl;

    for(int i=0;i<size;i++)
    {
        cout << arr[i] << " ";
    }

    Merge_sort(arr,size);

    cout << "\nSorted array : " << endl;

    for(int i=0;i<size;i++)
    {
        cout << arr[i] << " ";
    }
    
    delete [] arr; // Free memory after usage
    return 0;
}