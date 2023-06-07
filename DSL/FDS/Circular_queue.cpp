#include<iostream>
#define max 20
using namespace std;

class queue
{
    int r,f;
    int data[max];
    
    public:
        queue()
        {
            f = -1;
            r = -1;
        }
    int isempty()
    {
        if(f == -1 && r == -1)
            return 1;
        else
            return 0;
    }
    int isfull()
    {
        if(((r+1)%max) == f )
            return 1;
        else
            return 0;
     }
    void enqueue(int x)
    {
        int i;
        if(isempty())
        {
            r=f=0;
            data[r] = x;
            
        }
        else
            if(isfull())
            {
                cout<<"The queue is full";
            }
            else
            {
                r = (r+1)%max;
                data[r] = x;
            }
     }
     void deque()
     {
         int x;
         if(isempty()){
              cout<<"queue is empty";
         }
         else
         {
            if(r==f)
            {  
                // This is the last element
                x = data[f];
                r = f = -1;
            }  
            else
            {
                x = data[f];
                f = (f+1) % max;
                cout<<x<<"queue is deleted";
            }
         }
     }
     void reset()
     {
         r=f=-1;
     }               
     void display()
     {
         int i;
         cout<<"placed order are"<<endl;
         for(i = f;i<=r;((i+1) % max))
         {
             cout<<data[i]<<endl;  
          }
      }
};               
int main()
{
    queue obj;
    obj.enqueue(1);
    obj.enqueue(2);
    obj.enqueue(3);
    obj.enqueue(4);
    obj.enqueue(5);
    cout<<endl;
    obj.display();
    //cout<<endl;
    
    obj.deque();
    obj.deque();
    obj.deque();
    obj.deque();
    obj.deque();
    obj.reset();
    obj.display();