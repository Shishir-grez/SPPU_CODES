#include <iostream>
#include <ios>
#include <limits>
#define maxi 20
using namespace std;

class infi_to_post
{
    public:
    int top;
    char stack[maxi];
    infi_to_post()
    {
        top = -1;
    }
    bool isfull();
    bool isempty();
    void push(char c);
    void pop();
};

bool infi_to_post::isempty()
{
    if(top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool infi_to_post::isfull()
{
    if(top == maxi -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void infi_to_post::push(char c)
{
    if(top == -1)
    {
        top = 0;
        stack[top] = c;
    }
    else
    {
        top = top + 1;
        stack[top] = c;
    }
}

int prefrence(char x)
{
    if(x == '^')
    {
        return 3;
    }
    else if(x == '*' || x == '/')
    {
        return 2;
    }
    else if(x == '+' || x == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


void infi_to_post::pop()
{
    if(!isempty())
    {
        cout << stack[top];
        top = top - 1;
    }
}

void conversion(string obj)
{
    infi_to_post a;

    int i = 0;
    while(obj[i] != '\0')
    {
        
        if(obj[i] == '(')
        {

            if(a.top == -1)
            {
                a.top = 0;
                a.stack[a.top] = '(';
                i++;
            }
            // Missing when brackets comes after operators
            else
            {
                a.push('(');
                i++;
            }
        }
        else if(obj[i] == '^' || obj[i] == '*' || obj[i] == '/' || obj[i] == '+' || obj[i] == '-')
        {
            if(a.top == -1)
            {
                a.top = 0;
                a.stack[a.top] = obj[i];
                i++;
            }
            else
            {
                if(prefrence(obj[i]) > prefrence(a.stack[a.top]))
                {
                    a.push(obj[i]);
                    i++;
                }
                else if(prefrence(obj[i]) > prefrence(a.stack[a.top]))
                {
                    a.pop();
                }
                else 
                {
                    a.pop();
                }
            }
        }
        else if(obj[i] == '(')
        {
            while(obj[i] != ')')
            {
                a.pop();
            }
            i++;
           a.top = a.top - 1; // for '('
        }
        else
        {
            cout << obj[i];
            i++;
        }
        
    } 
    while(a.top != -1) // to empty stack
        {
            a.pop();
            i++;
        }
}

int main()
{
    cout << "Enter characters upto length 20 ";
    cout << "\nEnter expression :-";

    string text;
    cin >> text;

    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    conversion(text); 
    return 0;
}