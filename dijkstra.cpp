#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <limits>

using namespace std;

vector<int> dijkstra(int n, vector<vector<pair<int, int>>> &graph, int start)
{
    vector<int> dist(n, numeric_limits<int>::max());
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    while (!pq.empty())
    {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (d > dist[u])
            continue;
        for (auto &edge : graph[u])
        {
            int v = edge.first;
            int w = edge.second;
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main()
{
    int n = 4; // number of nodes
    vector<vector<pair<int, int>>> graph(n);
    // Example graph: 0->1 (1), 0->2 (4), 1->2 (2), 1->3 (5), 2->3 (1)
    graph[0].push_back({1, 1});
    graph[0].push_back({2, 4});
    graph[1].push_back({2, 2});
    graph[1].push_back({3, 5});
    graph[2].push_back({3, 1});

    int start = 0;
    vector<int> distances = dijkstra(n, graph, start);
    cout << "Shortest distances from node " << start << ":\n";
    for (int i = 0; i < n; ++i)
    {
        cout << "To node " << i << ": " << distances[i] << endl;
    }
    return 0;
}
