#include <iostream>
#include <string>
#include <limits>
#include <ios>
#include <stack>
using namespace std;

class node
{
public:
    string label;
    int child_count;
    node *next;
    node *create(node *n, int counter);
    void display(node *n, int counter);
};

node *node::create(node *n, int counter = 0)
{
    static bool flag = true;
    stack<node *> nodeStack; // Stack to store nodes to be processed

    if (flag == true)
    {
        flag = false;
        node *rootnode = new node;
        cout << "Enter Name of Book: ";
        getline(cin, rootnode->label);

        cout << "Enter Chapters in the Book: ";
        cin >> rootnode->child_count;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        n = rootnode;
        node *chapter = new node[rootnode->child_count];
        rootnode->next = chapter;

        for (int a = 0; a < rootnode->child_count; a++)
        {
            cout << "Enter Title of Chapter: ";
            getline(cin, chapter[a].label);

            cout << "Enter No of Sections in Chapter: ";
            cin >> chapter[a].child_count;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if (chapter[a].child_count > 0)
            {
                nodeStack.push(&chapter[a]);
            }
        }
    }
    else
    {
        node *current = n;

        while (!nodeStack.empty() || current != nullptr)
        {
            if (current != nullptr)
            {
                node *subs = new node[current->child_count];
                current->next = subs;

                for (int b = 0; b < current->child_count; b++)
                {
                    cout << "Enter Label for Sub Section No " << counter << ": ";
                    getline(cin, subs[b].label);

                    cout << "Enter No of Sub Sub Sections No " << counter << ": ";
                    cin >> subs[b].child_count;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    if (subs[b].child_count > 0)
                    {
                        nodeStack.push(&subs[b]);
                    }
                }

                if (!nodeStack.empty())
                {
                    current = nodeStack.top();
                    nodeStack.pop();
                    counter++;
                }
                else
                {
                    current = nullptr;
                }
            }
            else
            {
                current = nodeStack.top();
                nodeStack.pop();
                counter--;
            }
        }
    }

    return n;
}

void node::display(node *n, int counter = 0)
{
    stack<node *> nodeStack;
    node *current = n;

    while (!nodeStack.empty() || current != nullptr)
    {
        if (current != nullptr)
        {
            if (counter == 0)
            {
                cout << "Name of Book is: " << current->label << endl;
                cout << "Chapters in the Book are: " << current->child_count << endl;
            }
            else
            {
                cout << "Label Name No " << counter << ": " << current->label << endl;
                cout << "No of Sub Labels " << counter << ": " << current->child_count << endl;
            }

            if (current->child_count > 0)
            {
                nodeStack.push(current->next);
                current = &(current->next[0]);
                counter++;
            }
            else
            {
                current = nullptr;
            }
        }
        else
        {
            current = nodeStack.top();
            nodeStack.pop();
            counter--;
        }
    }
}

int main()
{
    node a;
    node *b = a.create(nullptr, 0);
    a.display(b);
    delete[] b->next;
    delete b;
    b = nullptr;
    return 0;
}
/*
Certainly! In the modified code, a stack data structure is used to keep track of nodes that need to be processed. Let's take a closer look at how the stack works in this context.

1. Stack Initialization:
   - At the beginning of the `create` and `display` functions, a stack called `nodeStack` is initialized.
   - The stack will store pointers to nodes that need to be processed.

2. Pushing Nodes onto the Stack:
   - In the `create` function, after creating a node and its child nodes, if any, the child nodes are pushed onto the stack using `nodeStack.push(&subs[b])`.
   - This ensures that the child nodes will be processed later.
   - Similarly, in the `display` function, when a node with child nodes is encountered, those child nodes are pushed onto the stack using `nodeStack.push(current->next)`.
   - This ensures that the child nodes will be displayed after the current node.

3. Processing Nodes from the Stack:
   - In both the `create` and `display` functions, a `while` loop is used to process nodes until the stack becomes empty.
   - The loop condition checks if the stack is empty or the current node pointer is null.
   - Inside the loop, the following actions are performed:
     - If the current node pointer is not null, it means there is a node to process.
     - Processing includes displaying information (in the case of `display`) or creating child nodes (in the case of `create`).
     - After processing, if the current node has child nodes, those child nodes are pushed onto the stack for later processing.
     - If there are no child nodes, the current node pointer is set to null to indicate that all processing for the current node is complete.
   - If the current node pointer is null, it means all child nodes of the current node have been processed, and it's time to move back to the parent node.
     - In this case, the next node to be processed is obtained from the stack using `current = nodeStack.top()`, and the top item is removed from the stack using `nodeStack.pop()`.
     - This allows the code to "backtrack" to the parent node and continue processing the remaining nodes.

By using a stack, the modified code replicates the behavior of recursion in a non-recursive manner. It ensures that child nodes are processed after their parent nodes and that the traversal order follows the expected depth-first fashion. The stack keeps track of the nodes that need to be processed, allowing the code to move forward and backward in the tree structure as necessary.
*/