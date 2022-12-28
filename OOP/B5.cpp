#include <iostream>
using namespace std;

template <typename T>
void selection_sort(T arr[], int size)
{
    for(int i=0;i<size;i++)
    {
        T min = arr[i];
        int min_indx = 0; 
        bool check = false;
        for(int j=i+1;j<size;j++)
        {
            if(min > arr[j])
            {
                min = arr[j];
                min_indx = j;
                check = true;
            }
        }
        if(check == true)
        {
        T temp = arr[i];
        arr[i] = arr[min_indx];
        arr[min_indx] = temp;
        }
    }
    cout << "\nSorted Array is :-";
    for(int i=0;i<size;i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    // for integer array 
    cout << "Enter the number of elements for integer array :-";
    int size1;
    cin >> size1;
    int* arr1 = new int[size1];
    for(int i=0;i<size1;i++)
    {
        int y;
        cout << "\nEnter element no " << i+1 << ":-";
        cin >> y;
        arr1[i] = y;
    }
    selection_sort(arr1,size1);

    cout << "Enter the number of elements for float array :-";
    int size2;
    cin >> size2;
    float* arr2 = new float[size1];
    for(int i=0;i<size2;i++)
    {
        float y;
        cout << "\nEnter element no " << i+1 << ":-";
        cin >> y;
        arr2[i] = y;
    }
    selection_sort(arr2,size2);
    return 0;
}