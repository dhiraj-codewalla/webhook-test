#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> topo_sort_bfs(int n, const vector<vector<int>> &graph)
{
    vector<int> indegree(n, 0);
    for (int u = 0; u < n; ++u)
    {
        for (int v : graph[u])
        {
            indegree[v]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < n; ++i)
    {
        if (indegree[i] == 0)
            q.push(i);
    }
    vector<int> order;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        order.push_back(u);
        for (int v : graph[u])
        {
            indegree[v]--;
            if (indegree[v] == 0)
                q.push(v);
        }
    }
    return order;
}

int main()
{
    int n = 6;
    vector<vector<int>> graph(n);
    // Example DAG: 5->2, 5->0, 4->0, 4->1, 2->3, 3->1
    graph[5] = {2, 0};
    graph[4] = {0, 1};
    graph[2] = {3};
    graph[3] = {1};
    // graph[0] and graph[1] are empty

    vector<int> order = topo_sort_bfs(n, graph);
    cout << "Topological Sort (BFS/Kahn's): ";
    for (int node : order)
        cout << node << " ";
    cout << endl;
    return 0;
}
