
#include <bits/stdc++.h>

#include <iostream>
typedef long long ll;
using namespace std;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  string line;
  regex re(R"((-?\d+).*?(-?\d+).*?(-?\d+).*?(-?\d+))");
  smatch match;
  vector<vector<int>> grid(101, vector<int>(103, 0));
  int n = grid.size();
  int m = grid[0].size();
  vector<tuple<int, int, int, int>> robots;
  while (getline(cin, line)) {
    regex_search(line, match, re);
    // cout << match[1] << " " << match[2] << " " << match[3] << " " << match[4]
    //      << endl;
    robots.push_back(
        {stoi(match[1]), stoi(match[2]), stoi(match[3]), stoi(match[4])});
  }

  int time = 0;
  bool overlap = true;
  while (overlap) {
    vector<vector<int>> temp = grid;
    // cout << "time: " << time << endl;
    for (tuple<int, int, int, int> robot : robots) {
      auto [x, y, vx, vy] = robot;
      int new_x = (x + (vx * time)) % n;
      int new_y = (y + (vy * time)) % m;
      if (new_x < 0) new_x += n;
      if (new_y < 0) new_y += m;
      temp[new_x][new_y]++;
    }
    overlap = false;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (temp[i][j] > 1) {
          overlap = true;
          break;
        }
      }
      if (overlap) break;
    }
    if (overlap) {
      time++;
    } else {
      for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
          if (temp[j][i] == 0) {
            cout << ".";
          } else {
            cout << (temp[j][i]);
          }
          cout << " ";
        }
        cout << endl;
      }
    }
  }
  cout << time << endl;
}