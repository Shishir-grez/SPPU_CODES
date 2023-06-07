#include <iostream>
#include <stdio.h>
#define MAX 100
using namespace std;

class dequeue{
    int front, rear;
    int data[MAX];

    public:

    dequeue()
    {
        front = -1;
        rear = -1;
    }

    bool is_full()
    {
        if((rear+1) % MAX == front)
        {
            return true;
        }    
        return false;
    }

    bool is_empty()
    {
        if(rear == -1 && front == -1)
        {
            return true;
        }
        return false;
    }

    void add_from_rear(int x)
    {
        if(is_empty())
        {
            front = 0;
            rear = 0;
            data[rear] = x;
        }
        else
        {
            if(is_full())
            {
                cout << "Array is full !!";cout << endl;
            }
            else
            {
                rear = (rear+1) % MAX;
                data[rear] = x;
            }

        }
    }
    void delete_from_front()
    {
        if(is_empty())
        {
            cout << "Empty Queue!"; cout << endl;
        }
        else
        {
            if(rear == front)
            {
                cout << data[front] << endl;
                front = -1;
                rear = -1;
            }
            else
            {
            cout << data[front] << endl;
            front = (front+1) % MAX;
            }
        }
    }

    void insert_from_front(int x)
    {
        if(is_empty())
        {
            front = 0;
            rear = 0;
            data[front] = x;        
        }
        else
        {
            if(front == 0)
            {
                front = MAX - 1;
                data[front] = x; 
            }
            else
            {
                front = front - 1;
                data[front] = x;
            }
        }
    }

    void delete_from_end()
    {
        if(is_empty())
        {
            cout << "Array is empty!" << endl;
        }
        else
        {
            if(rear == front)
            {
                data[rear] = -1;
                front = -1;
                rear = -1;
            }
            else if(rear == 0)
            {
                data[rear] = -1;
                rear = MAX - 1;
            }
            else
            {
                data[rear] = -1;
                rear = rear - 1;
            }
        }
    }

    void display()
    {
        int i = front;
       while(i!=rear)
       {
        cout << data[i] << " ";
        i = (i+1) % MAX;
       } 
       // Print till n-1
       cout << data[rear] << endl;
    }
};

int main()
{
    
    dequeue a;
    a.add_from_rear(1);
    a.insert_from_front(2);
    a.display();

    a.delete_from_front();
    a.delete_from_end();
    a.display();

    return 0;
}