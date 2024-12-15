#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
class solution {};

bool inBounds(int x, int y, int n, int m) {
  return x >= 0 && x < n && y >= 0 && y < m;
}

int check_dirs(int x, int y, vector<string>& grid, vector<vector<int>>& dirs) {
  string match = "XMAS";
  int total = 0;
  for (vector<int> v : dirs) {
    int i = 1;
    int new_x = x;
    int new_y = y;
    for (i; i < match.size(); i++) {
      new_x += v[0];
      new_y += v[1];
      if (!inBounds(new_x, new_y, grid.size(), grid[0].size()) ||
          grid[new_x][new_y] != match[i]) {
        break;
      }
    }
    if (i == match.size()) total++;
  }
  return total;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);

  vector<string> v;
  string line;
  while (cin >> line) {
    v.push_back(line);
  }
  vector<vector<int>> dirs = {{1, 0}, {0, 1},  {-1, 0},  {0, -1},
                              {1, 1}, {-1, 1}, {-1, -1}, {1, -1}};
  int total = 0;
  for (int i = 0; i < v.size(); i++) {
    for (int j = 0; j < v[i].size(); j++) {
      if (v[i][j] == 'X') {
        total += check_dirs(i, j, v, dirs);
      }
    }
  }
  cout << total << endl;
}