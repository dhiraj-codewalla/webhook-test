#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(int start, const vector<vector<int>> &graph, vector<bool> &visited)
{
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for (int v : graph[u])
        {
            if (!visited[v])
            {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

void dfs_util(int u, const vector<vector<int>> &graph, vector<bool> &visited)
{
    visited[u] = true;
    cout << u << " ";
    for (int v : graph[u])
    {
        if (!visited[v])
        {
            dfs_util(v, graph, visited);
        }
    }
}

void dfs(int start, const vector<vector<int>> &graph, vector<bool> &visited)
{
    dfs_util(start, graph, visited);
}

int main()
{
    int n = 5;
    vector<vector<int>> graph(n);
    // Example undirected graph
    graph[0] = {1, 2};
    graph[1] = {0, 3};
    graph[2] = {0, 4};
    graph[3] = {1};
    graph[4] = {2};

    vector<bool> visited_bfs(n, false);
    cout << "BFS starting from node 0: ";
    bfs(0, graph, visited_bfs);
    cout << endl;

    vector<bool> visited_dfs(n, false);
    cout << "DFS starting from node 0: ";
    dfs(0, graph, visited_dfs);
    cout << endl;
    return 0;
}
