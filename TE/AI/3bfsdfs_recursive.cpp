#include <iostream>
#include <stack>
#include <queue>

using namespace std;

void createGraph(int graph[15][15], int n)
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            graph[i][j] = -1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                graph[i][j] = 0;
                continue;
            }
            else
            {
                if (graph[i][j] == -1)
                {
                    cout << "Enter edge " << i << "-" << j << " :";
                    cin >> graph[i][j];
                    graph[j][i] = graph[i][j];
                }
            }
        }
    }

    cout << "\nAdjacency Matrix" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

void BFS_REC(int graph[15][15], int n, int v, int *visited, queue<int> &q){
    if(q.empty())
        return;

    v=q.front();
    q.pop();
    cout<<v<<"->";
    for(int i=0;i<n;i++)
        cout<<visited[i];
    for (int i = 0; i < n; ++i) {
        if (graph[v][i] && visited[i]==0) {
            visited[i] = 1;
            q.push(i);
        }
    }
    BFS_REC(graph, n, v, visited, q);
}

void BFS(int graph[15][15], int n, int v, int *visited)
{

    queue<int> q;
    q.push(v);
    visited[v] = 1;

    BFS_REC(graph, n, v, visited, q);
}


void DFS(int graph[15][15], int n, int v, int *visited)
{

    cout << v << "->";
    visited[v] = 1;
    for (int i = 0; i < n; i++)
    {
        if (graph[v][i] && visited[i] == 0)
        {
            DFS(graph, n, i, visited);
        }
    }
}

int main()
{
    int graph[15][15];
    int n, v;
    cout << "Enter no of vertices: ";
    cin >> n;
    int visited[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    createGraph(graph, n);
    cout << "Enter starting vertex: ";
    cin >> v;
    
    BFS(graph, n, v, visited);

    for(int i=0;i<n;i++){
        visited[i]=0;
    }
    DFS(graph, n, v, visited);

    return 0;
}
