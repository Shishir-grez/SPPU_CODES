#include <iostream>
#include <stdio.h>
using namespace std;

class LQueue
{
    private:
    LQueue* front;
    LQueue* rear;
    int data;
    LQueue* next;
    public:
    LQueue()
    {
        front = NULL;
        rear = NULL;
    }

    bool is_empty()
    {
        if(front == NULL && rear == NULL)
        {
            return true;
        }
        return false;
    }

    void enqueue(int x)
    {
        if(is_empty())
        {
            //Create new node
            LQueue* temp = new LQueue;
            temp->next = NULL; // To siginify last element of linked list
            temp->data = x;

            front = temp;  // Equivalent to front = rear = 0
            rear = temp;
        }
        else
        {
            LQueue* temp = new LQueue;
            temp->next = NULL;
            temp->data = x;
            rear->next = temp;
            rear = rear->next;
        }
    }
    void dequeue()
    {
        if(is_empty())
        {
            cout << "Queue is empty!" << endl;
        }
        else
        {
            if(rear == front)
            {
                //Last element
                LQueue* temp = front;
                cout << temp->data << endl;
                delete temp;
                temp = NULL;
                front = NULL;
                rear = NULL;
            }
            LQueue* temp = front;
            cout << temp->data << endl;
            front = front->next;
            delete temp;
            temp = NULL;
        }
    }
    void display()
    {
        LQueue* temp = front;
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
    LQueue a;
    a.enqueue(1);
    a.enqueue(2);
    a.enqueue(3);
    a.enqueue(4);

    a.display();
    a.dequeue();

    a.display();
    a.dequeue();

    a.display();
    a.dequeue();

    a.display();
    a.dequeue();

    a.display();
    return 0;
}