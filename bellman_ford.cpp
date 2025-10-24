#include <iostream>
#include <vector>
#include <limits>

using namespace std;

struct Edge
{
    int from, to, weight;
};

vector<int> bellman_ford(int n, const vector<Edge> &edges, int start)
{
    vector<int> dist(n, numeric_limits<int>::max());
    dist[start] = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        for (const auto &edge : edges)
        {
            if (dist[edge.from] != numeric_limits<int>::max() && dist[edge.from] + edge.weight < dist[edge.to])
            {
                dist[edge.to] = dist[edge.from] + edge.weight;
            }
        }
    }
    // Check for negative cycles
    for (const auto &edge : edges)
    {
        if (dist[edge.from] != numeric_limits<int>::max() && dist[edge.from] + edge.weight < dist[edge.to])
        {
            cout << "Graph contains a negative-weight cycle" << endl;
            break;
        }
    }
    return dist;
}

int main()
{
    int n = 4; // number of nodes
    vector<Edge> edges = {
        {0, 1, 1},
        {0, 2, 4},
        {1, 2, 2},
        {1, 3, 5},
        {2, 3, 1}};
    int start = 0;
    vector<int> distances = bellman_ford(n, edges, start);
    cout << "Shortest distances from node " << start << ":\n";
    for (int i = 0; i < n; ++i)
    {
        cout << "To node " << i << ": " << distances[i] << endl;
    }
    return 0;
}
