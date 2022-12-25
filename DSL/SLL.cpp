#include <iostream>
using namespace std;

class node
{
    public:
    int data;
    node* next;
};
    node* head = NULL;

int main()
{
    node* temp1 = new node;
    temp1->data = 10;
    temp1->next = NULL;
    head = temp1;

    node* temp2 = new node;
    temp1->next = temp2;
    temp2->data = 20;
    temp2->next = NULL;

    node* temp3 = new node;
    temp2->next = temp3;
    temp3->data = 30;
    temp3->next = NULL;

    node* itr = head;
    cout << "Original linked list : ";
    while(itr != NULL)
    {
        cout << itr->data << " ";
        itr = itr->next;
    }
    cout << endl;

    node* temp4 = new node;
    temp4->data = 40;
    temp2->next = temp4;
    temp4->next = temp3;
    temp3->next = NULL;

    cout << "After insertion : ";
    itr = head;
    while(itr != NULL)
    {
        cout << itr->data << " ";
        itr = itr->next;
    }
    cout << endl;

    //Insert at begining

    node* temp5 = new node;
    temp5->data = 50;
    temp5->next = temp1;
    head = temp5;

    cout << "Insertion at head : ";

    itr = head;
    while(itr != NULL)
    {
        cout << itr->data << " ";
        itr = itr->next;
    }
    cout << endl;
    
    // Insert at end
    node* temp6 = new node;
    temp3->next = temp6;
    temp6->data = 60;
    temp6->next = NULL;

    cout << "Insertion at End : ";

    itr = head;
    while(itr != NULL)
    {
        cout << itr->data << " ";
        itr = itr->next;
    }
    cout << endl;

    //Deletion at end
    temp3->next = NULL;

    cout << "Deletion at end : ";

    itr = head;
    while(itr != NULL)
    {
        cout << itr->data << " ";
        itr = itr->next;
    }
    cout << endl;

    //Deletion at begining
    head = temp1;

    cout << "Deletion at head : ";

    itr = head;
    while(itr != NULL)
    {
        cout << itr->data << " ";
        itr = itr->next;
    }
    cout << endl;

    delete temp1;
    delete temp2;
    delete temp3;
    delete temp4;
    delete temp5;
    delete temp6;
    
    return 0;
}