#include <iostream>

#define MAX_NODES 100

class Graph
{
private:
    int numNodes;
    int adjMatrix[MAX_NODES][MAX_NODES];
    int adjList[MAX_NODES][MAX_NODES];
    int listSizes[MAX_NODES];

public:
    Graph(int n)
    {
        numNodes = n;
        for (int i = 0; i < MAX_NODES; i++)
        {
            for (int j = 0; j < MAX_NODES; j++)
            {
                adjMatrix[i][j] = 0;
                adjList[i][j] = -1;
            }
            listSizes[i] = 0;
        }
    }

    void addEdge(int u, int v)
    {
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;

        adjList[u][listSizes[u]] = v;
        adjList[v][listSizes[v]] = u;

        listSizes[u]++;
        listSizes[v]++;
    }

    void dfs(int startNode)
    {
        bool visited[MAX_NODES];
        for (int i = 0; i < MAX_NODES; i++)
        {
            visited[i] = false;
        }

        // Explicitly implement a stack using an array
        int stack[MAX_NODES];
        int top = -1;

        stack[++top] = startNode;
        visited[startNode] = true;

        while (top != -1)
        {
            int currentNode = stack[top--];
            std::cout << currentNode << " ";

            for (int i = 0; i < listSizes[currentNode]; i++)
            {
                int neighbor = adjList[currentNode][i];
                if (!visited[neighbor])
                {
                    stack[++top] = neighbor;
                    visited[neighbor] = true;
                }
            }
        }
    }

    void bfs(int startNode)
    {
        bool visited[MAX_NODES];
        for (int i = 0; i < MAX_NODES; i++)
        {
            visited[i] = false;
        }

        // Explicitly implement a queue using an array
        int queue[MAX_NODES];
        int front = 0;
        int rear = -1;

        queue[++rear] = startNode;
        visited[startNode] = true;

        while (front <= rear)
        {
            int currentNode = queue[front++];
            std::cout << currentNode << " ";

            for (int i = 0; i < listSizes[currentNode]; i++)
            {
                int neighbor = adjList[currentNode][i];
                if (!visited[neighbor])
                {
                    queue[++rear] = neighbor;
                    visited[neighbor] = true;
                }
            }
        }
    }
};

int main()
{
    int numNodes, numEdges;
    std::cout << "Enter the number of nodes: ";
    std::cin >> numNodes;
    std::cout << "Enter the number of edges: ";
    std::cin >> numEdges;

    Graph graph(numNodes);

    std::cout << "Enter the edges (node u, node v):" << std::endl;
    for (int i = 0; i < numEdges; i++)
    {
        int u, v;
        std::cin >> u >> v;
        graph.addEdge(u, v);
    }

    int choice;
    do
    {
        std::cout << "\nGraph Traversal Menu\n";
        std::cout << "1. Depth-First Search (DFS)\n";
        std::cout << "2. Breadth-First Search (BFS)\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int startNode;
            std::cout << "Enter the starting node for DFS: ";
            std::cin >> startNode;
            std::cout << "DFS traversal: ";
            graph.dfs(startNode);
            std::cout << std::endl;
            break;
        }
        case 2:
        {
            int startNode;
            std::cout << "Enter the starting node for BFS: ";
            std::cin >> startNode;
            std::cout << "BFS traversal: ";
            graph.bfs(startNode);
            std::cout << std::endl;
            break;
        }
        case 3:
            std::cout << "Exiting...\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
            break;
        }
    } while (choice != 3);

    return 0;
}
