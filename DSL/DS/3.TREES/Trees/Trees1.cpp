#include <iostream>
#include <string>
#include <limits>
#include <ios>
#define ENABLE_NEW_DELETE_TRACE_DUMP // From offical documentation https://github.com/mvorbrodt/blog/blob/master/src/newtrace.txt
#include "newtrace.hpp"              // https://github.com/mvorbrodt/blog/blob/master/src/newtrace.hpp
using namespace std;

/////////////////// Required C++ 17 or Above to Execute ///////////////////////////////
//////////////////// Code Carefully while using Dynamic Memory (May cause Segmetation Error) /////////
class node
{
public:
    string label;
    int child_count;
    node *next;
    node *create(node *n, int counter);
    void display(node *n, int counter); // We cannot give default arguments in here incase  function is not defined inside the body
};

node *head = NULL; // Global Variable to make things easy

node *node::create(node *n, int counter = 0)
{
    static bool flag = true; // Block will execute only once
    if (flag == true)        // Creation of Root Node
    {
        flag = false;
        node *rootnode = new node;
        cout << "Enter Name of Book :- ";
        getline(cin, rootnode->label);

        cout << "Enter Chapters in the Book :- ";
        cin >> rootnode->child_count;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        n = rootnode;
        node *chapter = new node[rootnode->child_count]; // Create an Array of children
        rootnode->next = chapter;                        // next node for rootnode is chapter[0]

        for (int a = 0; a < rootnode->child_count; a++)
        {
            cout << "Enter Title of Chapter :- ";
            getline(cin, chapter[a].label);

            cout << "Enter No of Sections in Chapter :- ";
            cin >> chapter[a].child_count;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if (chapter[a].child_count > 0)
            {
                create(&(chapter[a])); // We provided refrence to function create of name(chapter),type = pointer
            }
            else
            {
                continue;
            }
        }
    }
    else
    {
        // Child nodes of Chapter then ....
        node *subs = new node[n->child_count];
        n->next = subs;
        for (int b = 0; b < n->child_count; b++)
        {
            // Entries for subs
            cout << "Enter Label for Sub Section No " << counter << " :- ";
            getline(cin, subs[b].label);

            cout << "Enter No of Sub Sub Sections No " << counter << " :- ";
            cin >> subs[b].child_count;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if (subs[b].child_count > 0)
            {
                create(&(subs[b]), counter + 1);
            }
            else
            {
                continue; /* The continue statement inside the if block tells Python to immediately move on to the next iteration of the loop without executing any code in the current iteration. */
            }
        }
    }

    return n;
}

void node::display(node *n, int counter = 0)
{
    static bool flag1 = true;
    if (flag1 == true)
    { // Displays Root node and Immediate Child Nodes
        flag1 = false;
        string lbl = n->label;
        cout << "Name of Book is :- " << lbl << endl;
        cout << "Chapters in the Book are :- " << n->child_count << endl;
        node *temp = n->next;
        for (int i = 0; i < n->child_count; i++)
        {
            cout << "Chapter " << i + 1 << " Title is :- " << temp[i].label << endl;
            cout << "No of Sections in Chapter " << i + 1 << " are :- " << temp[i].child_count << endl;
            display(&temp[i], counter + 1);
        }
    }
    else
    { // For Remaining Tree
        node *temp = n->next;
        for (int i = 0; i < n->child_count; i++)
        {
            cout << "Label Name No " << counter << " :- " << temp[i].label << endl;
            cout << "No of Sub Labels " << counter << " :- " << temp[i].child_count << endl;
            if (temp[i].child_count > 0)
            {
                display(&temp[i], counter + 1);
            }
        }
    }
}

// Delete all the memory used
void del_mem(node *n)
{
    for (int i = 0; i < n->child_count; i++) // Checks for child_count of node
    {
        node *temp = n->next;   // n->next is the array containing children
        node *temp1 = &temp[i]; // But children may contain their own children

        for (int j = 0; j < temp->child_count; j++) // following block deleted them also
        {
            if (temp1->child_count > 0) // if child_count > 0 , Recursively call the fnc
            {
                del_mem(temp1);
                delete[] temp1; // 1st statement after recursive call ends , Deletes array from bottom up
            }
            else
            {
                delete temp1; // If node has no child , delete individual node
            }
        }
    }
}

int main()
{
    node a;
    node *b = a.create(head, 0);
    cout << "*****************************" << endl;
    a.display(b);
    del_mem(b);
    delete b;
    b = NULL;
    ndt::dump_mismatch(); // Call this fnc to check where memory leak is occuring
    return 0;
}

// Use smart pointers instead