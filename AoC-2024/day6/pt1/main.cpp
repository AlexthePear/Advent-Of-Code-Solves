#include <bits/stdc++.h>

#include <iostream>
typedef long long ll;
using namespace std;

bool inBounds(int x, int y, int n, int m) {
  return x >= 0 && x < n && y >= 0 && y < m;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  vector<string> v;
  string line;
  while (cin >> line) {
    v.push_back(line);
  }
  int n = v.size(), m = v[0].size();
  vector<vector<bool>> visited(n, vector<bool>(m, false));
  int ans = 0;

  int gaurd_x, gaurd_y;
  // find the gaurd indicated by ^
  for (int i = 0; i < v.size(); i++) {
    for (int j = 0; j < v[i].size(); j++) {
      if (v[i][j] == '^') {
        gaurd_x = i;
        gaurd_y = j;
        visited[i][j] = true;
        ans++;
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
      if (v[new_x][new_y] == '#') {
        dir_ptr = (dir_ptr + 1) % 4;
        continue;
      } else {
        ans += !visited[new_x][new_y];
        visited[new_x][new_y] = true;
      }
    }
    gaurd_x = new_x;
    gaurd_y = new_y;
  }
  cout << ans << endl;
}