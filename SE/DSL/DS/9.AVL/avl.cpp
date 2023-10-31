#include <iostream>
#include <string>

class Node
{
public:
    std::string keyword;
    std::string meaning;
    int height;
    Node *left;
    Node *right;

    Node(std::string key, std::string value)
    {
        keyword = key;
        meaning = value;
        height = 1;
        left = nullptr;
        right = nullptr;
    }
};

class AVLDictionary
{
private:
    Node *root;

public:
    AVLDictionary()
    {
        root = nullptr;
    }

    // Get the height of a node
    int getHeight(Node *node)
    {
        if (node == nullptr)
            return 0;
        return node->height;
    }

    // Calculate the balance factor of a node
    int getBalanceFactor(Node *node)
    {
        if (node == nullptr)
            return 0;
        return getHeight(node->left) - getHeight(node->right);
    }

    // Update the height of a node
    void updateHeight(Node *node)
    {
        if (node == nullptr)
            return;
        node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));
    }

    // Perform a right rotation
    Node *rotateRight(Node *node)
    {
        Node *newRoot = node->left;
        Node *temp = newRoot->right;

        newRoot->right = node;
        node->left = temp;

        updateHeight(node);
        updateHeight(newRoot);

        return newRoot;
    }

    // Perform a left rotation
    Node *rotateLeft(Node *node)
    {
        Node *newRoot = node->right;
        Node *temp = newRoot->left;

        newRoot->left = node;
        node->right = temp;

        updateHeight(node);
        updateHeight(newRoot);

        return newRoot;
    }

    // Perform the necessary rotations to balance the tree
    Node *balance(Node *node)
    {
        updateHeight(node);

        if (getBalanceFactor(node) > 1) // Left subtree is taller
        {
            if (getBalanceFactor(node->left) < 0) // Left-Right case
                node->left = rotateLeft(node->left);
            return rotateRight(node); // Left-Left case
        }
        else if (getBalanceFactor(node) < -1) // Right subtree is taller
        {
            if (getBalanceFactor(node->right) > 0) // Right-Left case
                node->right = rotateRight(node->right);
            return rotateLeft(node); // Right-Right case
        }

        return node; // No imbalance, return the same node
    }

    // Insert a new keyword and its meaning into the dictionary
    Node *insert(Node *node, std::string key, std::string value)
    {
        if (node == nullptr)
            return new Node(key, value);

        if (key < node->keyword)
            node->left = insert(node->left, key, value);
        else if (key > node->keyword)
            node->right = insert(node->right, key, value);
        else // Duplicate keyword, update the meaning
            node->meaning = value;

        return balance(node);
    }

    // Search for a keyword in the dictionary
    Node *search(Node *node, std::string key)
    {
        if (node == nullptr || node->keyword == key)
            return node;

        if (key < node->keyword)
            return search(node->left, key);
        else
            return search(node->right, key);
    }

    // Find the node with minimum keyword in the tree
    Node *findMinNode(Node *node)
    {
        if (node == nullptr || node->left == nullptr)
            return node;
        return findMinNode(node->left);
    }

    // Delete a keyword from the dictionary
    Node *remove(Node *node, std::string key)
    {
        if (node == nullptr)
            return node;

        if (key < node->keyword)
            node->left = remove(node->left, key);
        else if (key > node->keyword)
            node->right = remove(node->right, key);
        else
        {
            if (node->left == nullptr || node->right == nullptr)
            {
                Node *temp = node->left ? node->left : node->right;

                if (temp == nullptr)
                {
                    temp = node;
                    node = nullptr;
                }
                else
                    *node = *temp;

                delete temp;
            }
            else
            {
                Node *temp = findMinNode(node->right);
                node->keyword = temp->keyword;
                node->meaning = temp->meaning;
                node->right = remove(node->right, temp->keyword);
            }
        }

        if (node == nullptr)
            return node;

        return balance(node);
    }

    // Inorder traversal to display the dictionary in ascending order
    void displayAscending(Node *node)
    {
        if (node == nullptr)
            return;

        displayAscending(node->left);
        std::cout << node->keyword << ": " << node->meaning << std::endl;
        displayAscending(node->right);
    }

    // Inorder traversal to display the dictionary in descending order
    void displayDescending(Node *node)
    {
        if (node == nullptr)
            return;

        displayDescending(node->right);
        std::cout << node->keyword << ": " << node->meaning << std::endl;
        displayDescending(node->left);
    }

    // Find the maximum number of comparisons required for searching a keyword
    int findMaxComparisons(Node *node, std::string key, int count)
    {
        if (node == nullptr || node->keyword == key)
            return count;

        if (key < node->keyword)
            return findMaxComparisons(node->left, key, count + 1);
        else
            return findMaxComparisons(node->right, key, count + 1);
    }

    // Public functions to interact with the AVLDictionary

    void addKeyword(std::string key, std::string value)
    {
        root = insert(root, key, value);
        std::cout << "Keyword added successfully!" << std::endl;
    }

    void deleteKeyword(std::string key)
    {
        root = remove(root, key);
        std::cout << "Keyword deleted successfully!" << std::endl;
    }

    void updateKeyword(std::string key, std::string value)
    {
        Node *node = search(root, key);
        if (node != nullptr)
        {
            node->meaning = value;
            std::cout << "Keyword updated successfully!" << std::endl;
        }
        else
            std::cout << "Keyword not found!" << std::endl;
    }

    void displayAscendingOrder()
    {
        std::cout << "Dictionary in ascending order:" << std::endl;
        displayAscending(root);
    }

    void displayDescendingOrder()
    {
        std::cout << "Dictionary in descending order:" << std::endl;
        displayDescending(root);
    }

    void findMaxComparisonsForKeyword(std::string key)
    {
        int maxComparisons = findMaxComparisons(root, key, 0);
        if (maxComparisons > 0)
            std::cout << "Maximum comparisons required for keyword \"" << key << "\": " << maxComparisons << std::endl;
        else
            std::cout << "Keyword not found!" << std::endl;
    }
};

int main()
{
    AVLDictionary dictionary;
    int choice;
    std::string key, value;

    do
    {
        std::cout << "\nDictionary Menu\n";
        std::cout << "1. Add a keyword\n";
        std::cout << "2. Delete a keyword\n";
        std::cout << "3. Update the meaning of a keyword\n";
        std::cout << "4. Display dictionary in ascending order\n";
        std::cout << "5. Display dictionary in descending order\n";
        std::cout << "6. Find maximum comparisons for a keyword\n";
        std::cout << "7. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            std::cout << "Enter the keyword to add: ";
            std::cin >> key;
            std::cout << "Enter the meaning of the keyword: ";
            std::cin.ignore();
            std::getline(std::cin, value);
            dictionary.addKeyword(key, value);
            break;
        case 2:
            std::cout << "Enter the keyword to delete: ";
            std::cin >> key;
            dictionary.deleteKeyword(key);
            break;
        case 3:
            std::cout << "Enter the keyword to update: ";
            std::cin >> key;
            std::cout << "Enter the new meaning of the keyword: ";
            std::cin.ignore();
            std::getline(std::cin, value);
            dictionary.updateKeyword(key, value);
            break;
        case 4:
            dictionary.displayAscendingOrder();
            break;
        case 5:
            dictionary.displayDescendingOrder();
            break;
        case 6:
            std::cout << "Enter the keyword to search: ";
            std::cin >> key;
            dictionary.findMaxComparisonsForKeyword(key);
            break;
        case 7:
            std::cout << "Exiting...\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
            break;
        }
    } while (choice != 7);

    return 0;
}
