#include <iostream>
#include <string>
#include <limits>
#include <ios>
#include <stdio.h>
using namespace std;

class node
{
public:
    string label;
    int child_count;
    node *next;
    node *create(int counter);
    void display(node *n, int counter = 0);
};

node *node::create(int counter)
{
    node *new_node = new node;
    cout << "Enter Label for Node No " << counter << " :- ";
    getline(cin, new_node->label);

    cout << "Enter No of Children for Node No " << counter << " :- ";
    cin >> new_node->child_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (new_node->child_count > 0)
    {
        new_node->next = new node[new_node->child_count];
        for (int i = 0; i < new_node->child_count; i++)
        {
            new_node->next[i].create(counter + 1);
        }
    }
    else
    {
        new_node->next = NULL;
    }

    return new_node;
}

void node::display(node *n, int counter)
{
    cout << "Label Name No " << counter << " :- " << n->label << endl;
    cout << "No of Children for Node No " << counter << " :- " << n->child_count << endl;

    for (int i = 0; i < n->child_count; i++)
    {
        display(&n->next[i], counter + 1);
    }
}

int main()
{
    node a;
    node *root = a.create(0);
    a.display(root, 0);
    return 0;
}
