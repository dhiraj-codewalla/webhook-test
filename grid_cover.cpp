#include <iostream>
#include <vector>
using namespace std;

void dfs(int x, int y, vector<vector<int>> &grid, vector<vector<bool>> &visited)
{
    int n = grid.size(), m = grid[0].size();
    if (x < 0 || x >= n || y < 0 || y >= m || visited[x][y] || grid[x][y] == 0)
        return;
    visited[x][y] = true;
    // 4 directions: up, down, left, right
    dfs(x + 1, y, grid, visited);
    dfs(x - 1, y, grid, visited);
    dfs(x, y + 1, grid, visited);
    dfs(x, y - 1, grid, visited);
}

int countComponents(vector<vector<int>> &grid)
{
    int n = grid.size(), m = grid[0].size(), count = 0;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (grid[i][j] == 1 && !visited[i][j])
            {
                dfs(i, j, grid, visited);
                count++;
            }
        }
    }
    return count;
}

int main()
{
    vector<vector<int>> grid = {
        {1, 1, 0, 0},
        {0, 1, 0, 1},
        {1, 0, 0, 1},
        {0, 0, 1, 1}};
    cout << "Number of connected components: " << countComponents(grid) << endl;
    return 0;
}
