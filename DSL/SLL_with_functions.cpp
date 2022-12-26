#include <iostream>
using namespace std;
class node
{
    int data;
    node* next;
    public:
    void create();
    void display();
    void ins_beg();
    void ins_bet();
    void ins_end();
    void del_beg();
    void del_bet();
    void del_end();
    void count();
    
};

node* head = NULL;

void node:: create()
    {
        node* itr;
        if(head == NULL)
        {
            node* temp = new node;
            cout << "Enter data for head : ";
            cin >> temp->data;

            head = temp;
            itr = temp;
            temp->next = NULL;
        }
        else
        {
            node* temp = new node;
            cout << "Enter data for node : ";
            cin >> temp->data;

            temp->next = NULL;
            itr->next = temp;
            itr = itr->next;
        }
    }

void node:: display()
        {
            node* itr = head;
            while(itr != NULL)
            {
                cout << itr->data << " ";
                itr = itr->next;
            }
        }

void node::ins_beg()
{
    node* temp = new node;
    cout << "Enter data for new head : ";
    cin >> temp->data;

    temp->next = head;
    head = temp;
}

void node::ins_bet()
{
    node* temp = new node;
    cout << "Enter the element after insertion is to be done : ";
    int x;
    cin >> x;

    node* itr = head;
    while(itr->data != x)
    {
        itr = itr->next;
    }

    cout << "Enter data for new node : ";
    cin >> temp->data;

    temp->next = itr->next;
    itr->next = temp;

}

void node:: ins_end()
{
    node* temp = new node;
    cout << "Enter data for node at end : ";
    cin >> temp->data;

    temp->next = NULL;
    node* itr = head;
    while(itr->next != NULL)
    {
        itr = itr->next;
    }

    itr->next = temp;
}

void node::del_beg()
{
    node* temp = head;
    head = head->next;
    cout << "Deleted !" << endl;
    delete temp;
}

void node::del_bet()
{
    node* itr =  head;
    node* temp;
    cout << "Enter the data of node to be deleted : ";
    int x;
    cin >> x;

    while(itr->next->data != x)
    {
        itr = itr->next;
    }

    temp = itr->next;
    itr->next = itr->next->next;
    delete temp;

}
void node:: del_end()
{
    node* itr = head;
    while(itr->next->next!=NULL)
    {
        itr = itr->next;
    }

    node* temp = itr ->next;
    delete temp;
    itr->next = NULL;

}
void node::count()
{
    node* itr = head;
    int x = 0;
    while(itr!=NULL)
    {   
        x++;
        itr = itr->next;
    }
    cout << "\nNo of nodes in SLL are : " << x;
}
int main()
{
    node a;
    a.create();
    a.create();
    a.create();
    a.create();
    a.create();
    a.ins_beg();
    a.ins_bet();
    a.ins_end();
    a.del_beg();
    a.del_bet();
    a.del_end();
    a.display();
    a.count();
    return 0;
}