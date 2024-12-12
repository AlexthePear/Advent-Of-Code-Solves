#include <bits/stdc++.h>
using namespace std;

bool inBounds(int i, int j, int n, int m) {
  return i >= 0 && i < n && j >= 0 && j < m;
}

int countUniqueSides(
    const vector<vector<pair<int, int>>> &boundarySidesByDirection) {
  int uniqueSides = 0;

  for (int d = 0; d < 4; d++) {
    const auto &sides = boundarySidesByDirection[d];
    if (sides.empty()) continue;

    vector<pair<int, int>> sortedSides = sides;

    if (d == 0 || d == 2) {
      sort(sortedSides.begin(), sortedSides.end(),
           [&](const pair<int, int> &a, const pair<int, int> &b) -> bool {
             if (a.first != b.first) return a.first < b.first;
             return a.second < b.second;
           });

      int current_i = sortedSides[0].first;
      int current_j = sortedSides[0].second;
      int prev_j = current_j;

      for (size_t k = 1; k < sortedSides.size(); k++) {
        int ci = sortedSides[k].first;
        int cj = sortedSides[k].second;

        if (ci == current_i && cj == prev_j + 1) {
          prev_j = cj;
        } else {
          uniqueSides++;
          current_i = ci;
          current_j = cj;
          prev_j = cj;
        }
      }
      uniqueSides++;
    } else {
      sort(sortedSides.begin(), sortedSides.end(),
           [&](const pair<int, int> &a, const pair<int, int> &b) -> bool {
             if (a.second != b.second) return a.second < b.second;
             return a.first < b.first;
           });

      int current_j = sortedSides[0].second;
      int current_i = sortedSides[0].first;
      int prev_i = current_i;

      for (size_t k = 1; k < sortedSides.size(); k++) {
        int ci = sortedSides[k].first;
        int cj = sortedSides[k].second;

        if (cj == current_j && ci == prev_i + 1) {
          prev_i = ci;
        } else {
          uniqueSides++;
          current_i = ci;
          current_j = cj;
          prev_i = ci;
        }
      }
      uniqueSides++;
    }
  }

  return uniqueSides;
}

pair<int, int> bfs(vector<string> &grid, vector<vector<bool>> &visited, int i,
                   int j, const vector<vector<int>> &dirs,
                   vector<vector<pair<int, int>>> &bounds) {
  queue<pair<int, int>> q;
  q.push({i, j});
  visited[i][j] = true;
  int area = 1;
  int perimeter = 0;
  int n = grid.size();
  int m = grid[0].size();

  while (!q.empty()) {
    auto [i, j] = q.front();
    q.pop();

    for (int d = 0; d < dirs.size(); d++) {
      int ni = i + dirs[d][0];
      int nj = j + dirs[d][1];

      if (inBounds(ni, nj, n, m) && grid[ni][nj] == grid[i][j]) {
        if (!visited[ni][nj]) {
          visited[ni][nj] = true;
          q.push({ni, nj});
          area++;
        }
      } else {
        pair<int, int> edge = {i, j};
        bounds[d].push_back(edge);
        perimeter++;
      }
    }
  }

  return {area, perimeter};
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<string> grid;
  string line;
  while (cin >> line) {
    grid.push_back(line);
  }

  int n = grid.size();
  int m = grid[0].size();
  int total = 0;
  vector<vector<bool>> visited(n, vector<bool>(m, false));

  vector<vector<int>> dirs = {
      {-1, 0},  // Top
      {0, 1},   // Right
      {1, 0},   // Bottom
      {0, -1}   // Left
  };

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!visited[i][j]) {
        vector<vector<pair<int, int>>> bounds(4);
        auto [area, perimieter] = bfs(grid, visited, i, j, dirs, bounds);
        int uniqueSides = countUniqueSides(bounds);
        cout << "Region: " << grid[i][j] << " Area: " << area
             << " Sides: " << uniqueSides << endl;
        total += area * uniqueSides;
      }
    }
  }

  cout << total << endl;
  return 0;
}
