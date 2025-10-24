#include <iostream>
#include <vector>
#include <limits>

using namespace std;

void floyd_warshall(int n, vector<vector<int>> &dist)
{
    for (int k = 0; k < n; ++k)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (dist[i][k] != numeric_limits<int>::max() && dist[k][j] != numeric_limits<int>::max())
                {
                    if (dist[i][j] > dist[i][k] + dist[k][j])
                    {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
    }
}

int main()
{
    int n = 4;
    vector<vector<int>> dist(n, vector<int>(n, numeric_limits<int>::max()));
    // Example graph: 0->1 (1), 0->2 (4), 1->2 (2), 1->3 (5), 2->3 (1)
    dist[0][0] = 0;
    dist[0][1] = 1;
    dist[0][2] = 4;
    dist[1][1] = 0;
    dist[1][2] = 2;
    dist[1][3] = 5;
    dist[2][2] = 0;
    dist[2][3] = 1;
    dist[3][3] = 0;

    floyd_warshall(n, dist);
    cout << "All-pairs shortest distances:\n";
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (dist[i][j] == numeric_limits<int>::max())
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
