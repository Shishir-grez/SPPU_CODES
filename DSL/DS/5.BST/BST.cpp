#include <iostream>
#include <string>

using namespace std;

struct Node
{
    string keyword;
    string meaning;
    Node *left;
    Node *right;
};

Node *createNode(string keyword, string meaning)
{
    Node *newNode = new Node();
    newNode->keyword = keyword;
    newNode->meaning = meaning;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

Node *insertNode(Node *root, string keyword, string meaning)
{
    if (root == nullptr)
    {
        root = createNode(keyword, meaning);
    }
    else if (keyword < root->keyword)
    {
        root->left = insertNode(root->left, keyword, meaning);
    }
    else if (keyword > root->keyword)
    {
        root->right = insertNode(root->right, keyword, meaning);
    }
    return root;
}

Node *minValueNode(Node *node)
{
    Node *current = node;
    while (current && current->left != nullptr) // Checks if current is a valid pointer + checks if current->left != nullptr
    {
        current = current->left;
    }
    return current;
}

Node *deleteNode(Node *root, string keyword)
{
    if (root == nullptr)
    {
        return root;
    }
    else if (keyword < root->keyword)
    {
        root->left = deleteNode(root->left, keyword);
    }
    else if (keyword > root->keyword)
    {
        root->right = deleteNode(root->right, keyword);
    }
    else
    {
        if (root->left == nullptr)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else
        {
            Node *temp = minValueNode(root->right); // Find inorder successor
            root->keyword = temp->keyword;
            root->meaning = temp->meaning;
            root->right = deleteNode(root->right, temp->keyword);
        }
    }
    return root;
}

void updateNode(Node *root, string keyword, string newMeaning)
{
    if (root == nullptr)
    {
        return;
    }
    else if (keyword < root->keyword)
    {
        updateNode(root->left, keyword, newMeaning);
    }
    else if (keyword > root->keyword)
    {
        updateNode(root->right, keyword, newMeaning);
    }
    else
    {
        root->meaning = newMeaning;
        cout << "Keyword updated successfully!" << endl;
        return; // Exit the function after updating the meaning
    }
    // Keyword not found in the current node, check the child nodes
    cout << "Keyword does not exist in the dictionary." << endl;
}

void inorderTraversal(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    inorderTraversal(root->left);
    cout << root->keyword << " - " << root->meaning << endl;
    inorderTraversal(root->right);
}

void reverseInorderTraversal(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    reverseInorderTraversal(root->right);
    cout << root->keyword << " - " << root->meaning << endl;
    reverseInorderTraversal(root->left);
}

int getMaximumComparisons(Node *root, string keyword, int comparisons)
{
    if (root == nullptr)
    {
        return -1; // Return a negative value to indicate that the keyword was not found
    }
    else if (root->keyword == keyword)
    {
        return comparisons + 1;
    }
    else if (keyword < root->keyword)
    {
        int leftComparisons = getMaximumComparisons(root->left, keyword, comparisons + 1);
        if (leftComparisons == -1)
        {
            cout << "Keyword does not exist in the dictionary." << endl;
            return -1;
        }
        else
        {
            return leftComparisons;
        }
    }
    else
    {
        int rightComparisons = getMaximumComparisons(root->right, keyword, comparisons + 1);
        if (rightComparisons == -1)
        {
            cout << "Keyword does not exist in the dictionary." << endl;
            return -1;
        }
        else
        {
            return rightComparisons;
        }
    }
}

int main()
{
    Node *root = nullptr;

    int choice;
    string keyword, meaning;
    int maxComparisons;

    while (true)
    {
        cout << "----- Dictionary Menu -----" << endl;
        cout << "1. Add a new keyword" << endl;
        cout << "2. Delete a keyword" << endl;
        cout << "3. Update the meaning of a keyword" << endl;
        cout << "4. Display data in ascending order" << endl;
        cout << "5. Display data in descending order" << endl;
        cout << "6. Find the maximum comparisons required for a keyword" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "Enter keyword: ";
            cin.ignore();
            getline(cin, keyword);
            cout << "Enter meaning: ";
            getline(cin, meaning);
            root = insertNode(root, keyword, meaning);
            cout << "Keyword added successfully!" << endl;
            break;
        }
        case 2:
        {
            cout << "Enter keyword to delete: ";
            cin.ignore();
            getline(cin, keyword);
            Node *originalRoot = root;
            root = deleteNode(root, keyword);
            if (root == originalRoot)
            {
                cout << "No such word exists in the dictionary." << endl;
            }
            else
            {
                cout << "Keyword deleted successfully!" << endl;
            }
            break;
        }
        case 3:
        {
            cout << "Enter keyword to update: ";
            cin.ignore();
            getline(cin, keyword);
            cout << "Enter new meaning: ";
            getline(cin, meaning);
            updateNode(root, keyword, meaning);

            break;
        }
        case 4:
        {
            cout << "Dictionary data in ascending order:" << endl;
            inorderTraversal(root);
            break;
        }
        case 5:
        {
            cout << "Dictionary data in descending order:" << endl;
            reverseInorderTraversal(root);
            break;
        }
        case 6:
        {
            cout << "Enter keyword to find maximum comparisons: ";
            cin.ignore();
            getline(cin, keyword);
            maxComparisons = getMaximumComparisons(root, keyword, 0);
            cout << "Maximum comparisons required to find the keyword: " << maxComparisons << endl;
            break;
        }
        case 7:
        {
            exit(0);
        }
        default:
            cout << "Invalid choice. Please try again." << endl;
        }

        cout << endl;
    }

    return 0;
}
