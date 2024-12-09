#include <bits/stdc++.h>

#include <iostream>
typedef long long ll;
using namespace std;

bool inBounds(int x, int y, int n, int m) {
  return x >= 0 && x < n && y >= 0 && y < m;
}

bool CheckGrid(vector<string>& v, int i, int j) {
  int n = v.size(), m = v[0].size();
  set<tuple<int, int, int>> visited_states;
  int gaurd_x, gaurd_y;
  // find the guard indicated by '^'
  for (int x = 0; x < v.size(); x++) {
    for (int y = 0; y < v[x].size(); y++) {
      if (v[x][y] == '^') {
        gaurd_x = x;
        gaurd_y = y;
        break;
      }
    }
  }
  vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
  int dir_ptr = 0;
  while (inBounds(gaurd_x, gaurd_y, n, m)) {
    int new_x = gaurd_x + dirs[dir_ptr][0];
    int new_y = gaurd_y + dirs[dir_ptr][1];
    if (inBounds(new_x, new_y, n, m)) {
      if (v[new_x][new_y] == '#' || (new_x == i && new_y == j)) {
        dir_ptr = (dir_ptr + 1) % 4;
        continue;
      } else {
        auto state = make_tuple(new_x, new_y, dir_ptr);
        if (visited_states.count(state)) {
          return false;
        }
        visited_states.insert(state);
      }
    }
    gaurd_x = new_x;
    gaurd_y = new_y;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  vector<string> v;
  string line;
  while (cin >> line) {
    v.push_back(line);
  }
  int n = v.size(), m = v[0].size();
  vector<vector<pair<bool, int>>> visited(
      n, vector<pair<bool, int>>(m, {false, 0}));
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (v[i][j] == '.') {
        ans += !CheckGrid(v, i, j);
      }
    }
  }
  cout << ans << endl;
}