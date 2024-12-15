#include <bits/stdc++.h>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>

#include <iostream>
#include <thread>
typedef long long ll;
using namespace std;

void waitForKeyPress() {
  struct termios oldt, newt;
  tcgetattr(STDIN_FILENO, &oldt);  // Get current terminal settings
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);         // Disable canonical mode and echo
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);  // Apply new terminal settings

  int tty_fd = open("/dev/tty", O_RDONLY);  // Open terminal device
  if (tty_fd < 0) {
    perror("open");
    return;
  }

  cout << "Press any key to continue..." << endl;
  char ch;
  read(tty_fd, &ch, 1);  // Wait for a key press

  close(tty_fd);                            // Close terminal device
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);  // Restore old terminal settings
}

bool moveBox(int x, int y, vector<string>& grid, char dir) {
  bool moved = true;
  int b1_x = x, b1_y = y;
  int b2_x, b2_y;
  if (grid[x][y] == '[') {
    b2_x = x;
    b2_y = y + 1;
  } else {
    b2_x = x;
    b2_y = y - 1;
  }

  int new_b1_x = b1_x, new_b1_y = b1_y;
  int new_b2_x = b2_x, new_b2_y = b2_y;
  if (dir == '^') {
    new_b1_x = b1_x - 1;
    new_b2_x = b2_x - 1;
  } else {
    new_b1_x = b1_x + 1;
    new_b2_x = b2_x + 1;
  }
  if (grid[new_b1_x][new_b1_y] == grid[b1_x][b1_y] &&
      grid[new_b2_x][new_b2_y] == grid[b2_x][b2_y]) {
    moveBox(new_b1_x, new_b1_y, grid, dir);
  }
  if (grid[new_b1_x][new_b1_y] == grid[b2_x][b2_y]) {
    moveBox(new_b1_x, new_b1_y, grid, dir);
  }
  if (grid[new_b2_x][new_b2_y] == grid[b1_x][b1_y]) {
    moveBox(new_b2_x, new_b2_y, grid, dir);
  }
  if (grid[new_b1_x][new_b1_y] == '.' && grid[new_b2_x][new_b2_y] == '.') {
    char temp = grid[b1_x][b1_y];
    grid[b1_x][b1_y] = grid[new_b1_x][new_b1_y];
    grid[new_b1_x][new_b1_y] = temp;

    temp = grid[b2_x][b2_y];
    grid[b2_x][b2_y] = grid[new_b2_x][new_b2_y];
    grid[new_b2_x][new_b2_y] = temp;
    return true;
  }
  return false;
}

pair<int, int> moveVert(int& x, int& y, vector<string>& grid, char dir) {
  int new_x = x, new_y = y;
  if (dir == '^') {
    new_x = x - 1;
  } else if (dir == 'v') {
    new_x = x + 1;
  }
  vector<string> temp = grid;
  if (grid[new_x][new_y] == '[' || grid[new_x][new_y] == ']') {
    // moveBox(new_x, new_y, grid, dir);
    if (moveBox(new_x, new_y, temp, dir)) {
      grid = temp;
    }
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

pair<int, int> moveHorz(int& x, int& y, vector<string>& grid, char dir) {
  int new_x = x, new_y = y;
  if (dir == '<') {
    new_y = y - 1;
  } else if (dir == '>') {
    new_y = y + 1;
  }

  if (grid[new_x][new_y] == '[' || grid[new_x][new_y] == ']') {
    moveHorz(new_x, new_y, grid, dir);
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
  cout << "Start" << endl;
  while (cin >> line) {
    if (line[0] == '#') {
      string temp = "";
      for (char c : line) {
        if (c == 'O') {
          temp.push_back('[');
          temp.push_back(']');
        } else if (c == '@') {
          temp.push_back('@');
          temp.push_back('.');
        } else {
          temp.push_back(c);
          temp.push_back(c);
        }
      }
      grid.push_back(temp);
      cout << grid.back() << endl;
    } else {
      moves.push_back(line);
    }
  }
  // for added dleay when visualizing
  // sleep(2);
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
      if (c == '>' || c == '<') {
        auto [new_x, new_y] = moveHorz(botx, boty, grid, c);
        botx = new_x;
        boty = new_y;
      } else {
        auto [new_x, new_y] = moveVert(botx, boty, grid, c);
        botx = new_x;
        boty = new_y;
      }
      // Uncomment below for visulization either using waitForKeyPress or
      // sleep_for waitForKeyPress();
      // this_thread::sleep_for(chrono::milliseconds(100));
      // cout << c << endl;
      // for (string s : grid) {
      //   cout << s << endl;
      // }
    }
  }
  // for (string s : grid) {
  //   cout << s << endl;
  // }
  ll total = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == '[') {
        total += (100 * i + j);
      }
    }
  }
  cout << total << endl;
}