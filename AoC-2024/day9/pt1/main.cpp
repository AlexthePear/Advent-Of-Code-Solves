#include <bits/stdc++.h>

#include <iostream>
typedef long long ll;
using namespace std;
bool inBounds(int x, int y, int n, int m) {
  return x >= 0 && x < n && y >= 0 && y < m;
}

void dfs(vector<string>& graph, vector<vector<int>>& dirs,
         vector<vector<bool>>& visited, int x, int y, int& score) {
  int height = graph[x][y] - '0';
  if (!visited[x][y] && height == 9) {
    visited[x][y] = true;
    score++;
  }
  for (vector<int> d : dirs) {
    int nx = x + d[0], ny = y + d[1];
    if (inBounds(nx, ny, graph.size(), graph[0].size())) {
      int new_height = graph[nx][ny] - '0';
      if (new_height == height + 1) {
        dfs(graph, dirs, visited, nx, ny, score);
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  string line;
  vector<string> graph;
  while (cin >> line) {
    graph.push_back(line);
  }

  // please make sure you paste in the input
  int n = graph.size(), m = graph[0].size();

  vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

  int score = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (graph[i][j] == '0') {
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        dfs(graph, dirs, visited, i, j, score);
      }
    }
  }
  cout << score << endl;
}