#include <iostream>
#include <stdio.h>

using namespace std;

class Lstack{
    int data;
    Lstack* top;
    Lstack* next;
    public:

    Lstack()
    {
        top = NULL;
    }

    bool isempty()
    {
        if(top == NULL)
        {
            return true;
        }
        return false;
    }

    void push(int x)
    {
        if(isempty())
        {
            Lstack* temp = new Lstack;
            temp->data = x;
            temp->next = NULL; // Only for this 
            top = temp;
        }
        else
        {
            Lstack* temp = new Lstack;
            temp->data = x;
            temp->next = top;
            top = temp;
        }
    }
    void pop()
    {
        
        Lstack* temp = top;
        cout << temp->data << endl;
        top = top->next; // increment
        delete temp;
    }
    void display()
    {
        Lstack* temp = top;
        while(temp!=NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    Lstack a;
    a.push(1);
    a.push(2);
    a.push(3);
    a.display();
    a.pop();
    a.display();
    a.pop();
    a.display();
    a.pop();
    a.push(7);
    a.display();

    return 0;
}