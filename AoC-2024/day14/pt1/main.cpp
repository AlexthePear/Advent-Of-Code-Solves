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
  int time = 100;
  while (getline(cin, line)) {
    regex_search(line, match, re);
    cout << match[1] << " " << match[2] << " " << match[3] << " " << match[4]
         << endl;
    pair<int, int> pos = {stoi(match[1]), stoi(match[2])};
    pair<int, int> vel = {stoi(match[3]), stoi(match[4])};
    pos.first = (pos.first + (vel.first * time)) % n;
    pos.second = (pos.second + (vel.second * time)) % m;
    if (pos.first < 0) pos.first += n;
    if (pos.second < 0) pos.second += m;
    grid[pos.first][pos.second]++;
  }
  int q1, q2, q3, q4;
  for (int i = 0; i < n / 2; i++) {
    for (int j = 0; j < m / 2; j++) {
      q1 += grid[i][j];
    }
  }
  for (int i = 0; i < n / 2; i++) {
    for (int j = (m / 2) + 1; j < m; j++) {
      q2 += grid[i][j];
    }
  }
  for (int i = (n / 2) + 1; i < n; i++) {
    for (int j = 0; j < m / 2; j++) {
      q3 += grid[i][j];
    }
  }
  for (int i = (n / 2) + 1; i < n; i++) {
    for (int j = (m / 2) + 1; j < m; j++) {
      q4 += grid[i][j];
    }
  }
  cout << q1 * q2 * q3 * q4 << endl;
}