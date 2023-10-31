#include <iostream>
#include <memory>
using namespace std;

int main()
{
    unique_ptr<int> ptr1(new int(4));
    shared_ptr<int> ptr2 = make_unique <int> (5);
    shared_ptr<int> ptr3 = ptr2;
    weak_ptr<int> ptr4 = ptr2;

    cout << *ptr1 << endl;
    cout << ptr1.get() << endl;

    cout << *ptr2 << endl;
    cout << ptr2.use_count() << endl;

   
    return 0;
}