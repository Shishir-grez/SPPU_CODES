#include <iostream>
using namespace std;

int main()
{
    // Take input from user
    cout << "Enter the size of the array ";
    int size;
    cin >> size;
    int * arr = new int[size];
    cout << endl << "Enter elements :-" << endl;
    for(int i=0;i<size;i++)
    {
        int x;
        cout << "Element no " << i << ":-";
        cin >> x;
        cout << endl;
        arr[i] = x;
    }
    cout << "Enter Key :-";
    int key;
    cin >> key;
    
}