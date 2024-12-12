#include <bits/stdc++.h>

#include <iostream>
typedef long long ll;
using namespace std;

bool inBounds(int x, int y, int n, int m) {
  return x >= 0 && x < n && y >= 0 && y < m;
}

void dfs(vector<string> &grid, vector<vector<bool>> &visited, int i, int j,
         vector<vector<int>> &dirs, int &area, int &perimeter) {
  visited[i][j] = true;
  area++;
  for (auto dir : dirs) {
    int ni = i + dir[0], nj = j + dir[1];
    if (inBounds(ni, nj, grid.size(), grid[0].size()) &&
        grid[ni][nj] == grid[i][j] && !visited[ni][nj]) {
      dfs(grid, visited, ni, nj, dirs, area, perimeter);
    } else if (!inBounds(ni, nj, grid.size(), grid[0].size()) ||
               grid[ni][nj] != grid[i][j]) {
      perimeter++;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  vector<string> grid;
  string line;
  while (cin >> line) {
    grid.push_back(line);
  }
  int n = grid.size(), m = grid[0].size();
  int total = 0;
  vector<vector<bool>> visited(n, vector<bool>(m, false));
  vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!visited[i][j]) {
        int area = 0;
        int perimeter = 0;
        dfs(grid, visited, i, j, dirs, area, perimeter);

        // cout << "Region: " << grid[i][j] << " Area: " << area
        //      << " Perimeter: " << perimeter << endl;
        total += area * perimeter;
      }
    }
  }
  cout << total << endl;
}
