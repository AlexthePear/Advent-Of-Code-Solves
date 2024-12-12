#include <bits/stdc++.h>

#include <iostream>
typedef long long ll;
using namespace std;

bool inBounds(int x, int y, int n, int m) {
  return x >= 0 && x < n && y >= 0 && y < m;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  vector<string> grid;
  string line;
  while (cin >> line) {
    grid.push_back(line);
  }

  unordered_map<char, vector<pair<int, int>>> antennas;
  int n = grid.size();     // rows
  int m = grid[0].size();  // cols
  for (int i = 0; i < grid.size(); i++) {
    for (int j = 0; j < grid[i].size(); j++) {
      if (isalnum(grid[i][j])) {
        antennas[grid[i][j]].push_back({i, j});
      }
    }
  }

  int ans = 0;
  set<pair<int, int>> visited;
  for (auto [c, pos] : antennas) {
    for (int i = 0; i < pos.size(); i++) {
      for (int j = i + 1; j < pos.size(); j++) {
        pair<int, int> p1 = pos[i];
        pair<int, int> p2 = pos[j];
        int y_diff = p1.first - p2.first;
        int x_diff = p1.second - p2.second;
        pair<int, int> anti_node_1 = {p2.first - y_diff, p2.second - x_diff};
        pair<int, int> anti_node_2 = {p1.first + y_diff, p1.second + x_diff};
        // Handle anti_node_1
        if (inBounds(anti_node_1.first, anti_node_1.second, n, m) &&
            grid[anti_node_1.first][anti_node_1.second] != c &&
            grid[anti_node_1.first][anti_node_1.second] != '#' &&
            !visited.count(anti_node_1)) {
          visited.insert(anti_node_1);
          ans++;
          //   grid[anti_node_1.first][anti_node_1.second] = '#';
        }

        // Handle anti_node_2
        if (inBounds(anti_node_2.first, anti_node_2.second, n, m) &&
            grid[anti_node_2.first][anti_node_2.second] != c &&
            grid[anti_node_2.first][anti_node_2.second] != '#' &&
            !visited.count(anti_node_2)) {
          visited.insert(anti_node_2);
          ans++;
          //   grid[anti_node_2.first][anti_node_2.second] = '#';
        }
      }
    }
  }
  for (string s : grid) {
    cout << s << endl;
  }
  cout << ans << endl;
}