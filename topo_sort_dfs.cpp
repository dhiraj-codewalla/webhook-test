#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfs_topo(int u, const vector<vector<int>> &graph, vector<bool> &visited, stack<int> &st)
{
    visited[u] = true;
    for (int v : graph[u])
    {
        if (!visited[v])
        {
            dfs_topo(v, graph, visited, st);
        }
    }
    st.push(u);
}

vector<int> topo_sort_dfs(int n, const vector<vector<int>> &graph)
{
    vector<bool> visited(n, false);
    stack<int> st;
    for (int i = 0; i < n; ++i)
    {
        if (!visited[i])
        {
            dfs_topo(i, graph, visited, st);
        }
    }
    vector<int> order;
    while (!st.empty())
    {
        order.push_back(st.top());
        st.pop();
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

    vector<int> order = topo_sort_dfs(n, graph);
    cout << "Topological Sort (DFS): ";
    for (int node : order)
        cout << node << " ";
    cout << endl;
    return 0;
}
