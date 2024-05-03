#include <iostream>
using namespace std;

void sort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[min] > arr[j])
            {
                min = j;
            }
        }
        swap(arr[i], arr[min]);
    }
}

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    cout << "Enter the size of the array : ";
    int size;
    cin >> size;
    cout << "\n";

    cout << "Enter the elements of array : ";
    int *array = new int[size];

    for (int i = 0; i < size; i++)
    {
        cin >> array[i];
    }
    cout << "\n";

    cout << "Sorted Array is : ";

    sort(array, size);
    print(array, size);

    cout << "\n";
    return 0;
}