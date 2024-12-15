#include <bits/stdc++.h>

#include <iostream>
typedef long long ll;
using namespace std;

pair<int, int> moveDir(int& x, int& y, vector<string>& grid, char dir) {
  int new_x = x, new_y = y;
  if (dir == '^') {
    new_x = x - 1;
  } else if (dir == 'v') {
    new_x = x + 1;
  } else if (dir == '<') {
    new_y = y - 1;
  } else if (dir == '>') {
    new_y = y + 1;
  }

  if (grid[new_x][new_y] == 'O') {
    moveDir(new_x, new_y, grid, dir);
  }
  if (grid[new_x][new_y] == '.') {
    // cout << "moving " << new_x << " " << new_y << " with " << x << " " << y
    //      << endl;
    char temp = grid[x][y];
    grid[x][y] = grid[new_x][new_y];
    grid[new_x][new_y] = temp;
  }
  if (grid[new_x][new_y] == '@') {
    return {new_x, new_y};
  }
  return {x, y};
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  string line;
  vector<string> grid;
  vector<string> moves;
  while (cin >> line) {
    if (line[0] != '#') {
      moves.push_back(line);
    } else {
      grid.push_back(line);
      //   cout << line << endl;
    }
  }
  int n = grid.size(), m = grid[0].size();
  int botx, boty;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == '@') {
        // cout << i << " " << j << endl;
        botx = i;
        boty = j;
      }
    }
  }

  for (string move : moves) {
    // cout << move << endl;
    for (char c : move) {
      //   cout << c << endl;
      auto [new_x, new_y] = moveDir(botx, boty, grid, c);
      botx = new_x;
      boty = new_y;
      //   for (string s : grid) {
      //     cout << s << endl;
      //   }
    }
  }
  for (string s : grid) {
    cout << s << endl;
  }
  ll total = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == 'O') {
        total += ((100 * i) + j);
      }
    }
  }
  cout << total << endl;
}