#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
class solution {};

bool inBounds(int x, int y, int n, int m) {
  return x >= 0 && x < n && y >= 0 && y < m;
}

int check_xmas(int x, int y, vector<string>& grid) {
  vector<vector<int>> dirs = {{1, 1}, {-1, 1}, {-1, -1}, {1, -1}};
  int m_count = 0;
  int s_count = 0;
  for (vector<int> v : dirs) {
    int new_x = x + v[0];
    int new_y = y + v[1];
    if (!inBounds(new_x, new_y, grid.size(), grid[0].size())) {
      return 0;
    }
    m_count += (grid[new_x][new_y] == 'M');
    s_count += (grid[new_x][new_y] == 'S');
  }
  if (m_count != 2 || s_count != 2 ||
      grid[x - 1][y - 1] == grid[x + 1][y + 1]) {
    return 0;
  }
  return 1;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);

  vector<string> v;
  string line;
  while (cin >> line) {
    v.push_back(line);
  }

  int total = 0;
  for (int i = 0; i < v.size(); i++) {
    for (int j = 0; j < v[i].size(); j++) {
      if (v[i][j] == 'A') {
        total += check_xmas(i, j, v);
      }
    }
  }
  cout << total << endl;
}