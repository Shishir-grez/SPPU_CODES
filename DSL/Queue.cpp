#include <iostream>
#define MAX 20
#include <stdio.h>
using namespace std;

class queue
{
    private:
    int front, rear;
    int data[MAX];
    public:
    queue()
    {
        front = -1;
        rear = -1;
    }

    bool is_full()
    {
        if(front + rear == MAX-1)
        {
            return true;
        }
        return false;
    }

    bool is_empty()
    {
        if(front == -1 && rear == -1)
        {
            return true;
        }
        return false;
    }

    void enqueue(int x)
    {
        if(is_empty())
        {
            front = rear = 0;
            data[rear] = x;
            rear++;
        }
        else
        {
            if(is_full())
            {
                cout << "Queue is full"; cout << endl;
                exit;
            }
            else
            {
                data[rear] = x;
                rear ++;
            }
        }
    }
    
    void deque()
    {
        if(is_empty())
        {
            cout << "Queue is empty"; cout << endl;
        }
        else
        {
            if(rear == front)
            {
                cout << data[front] << endl;
                rear = -1;
                front = -1;
            }
            else
            {
                cout << data[front] << endl;
                front ++;
            }
        }
    }
    void display()
    {
        for(int i=front; i<rear;i++)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    queue a;
    a.enqueue(1);
    a.enqueue(2);
    a.enqueue(3);
    a.enqueue(4);
    a.display();
    a.deque();
    a.deque();
    a.deque();
    a.deque();
    return 0;
}