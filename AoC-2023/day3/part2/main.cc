#include <bits/stdc++.h>

bool IsAsteriks(char c) { return c == '*'; }

bool IsANumber(char c) { return (c >= '0' && c <= '9'); }

bool IsAPeriod(char c) { return c == '.'; }

bool CheckIfSpecialCharacter(char c) {
  return ((c <= '@' && c >= '=') || (c >= '!' && c <= '/') && !IsAPeriod(c));
}

// The 2d array is a 140 by 140 size,
bool CheckIfInBounds(int index) {
  if (index < 0) {
    return false;
  }
  // cant index 140
  if (index >= 140) {
    return false;
  }
  return true;
}

int main() {
  std::vector<int> nums_in_line;
  std::vector<std::string> all_lines;
  // Technaically a 2d array ^
  std::string line;

  std::string current_num;
  std::vector<int> all_correct_nums;

  int gear_x_pos;
  int gear_y_pos;
  // x and y pos , numbers attached to gear;
  std::map<std::pair<int, int>, std::vector<int>> gear_map;
  bool current_num_is_valid;
  while (std::cin >> line) {
    all_lines.push_back(line);
  }
  for (int i = 0; i < 140; i++) {
    for (int j = 0; j < 140; j++) {
      char current_char = all_lines[i][j];

      if (IsAPeriod(current_char) || CheckIfSpecialCharacter(current_char)) {
        if (current_num_is_valid) {
          std::cout << "Valid Number: " << current_num << " ";
          gear_map[std::make_pair(gear_x_pos, gear_y_pos)].push_back(
              stoi(current_num));
        }
        if (!current_num.empty()) {
          current_num.clear();
        }
        current_num_is_valid = false;
      }

      if (IsANumber(current_char)) {
        current_num.push_back(current_char);
        for (int x = i - 1; x <= i + 1; x++) {
          for (int y = j - 1; y <= j + 1; y++) {
            // std::cout << "In Bounds " << x << " , " << y << " : "
            //           << (CheckIfInBounds(x) && CheckIfInBounds(y))
            //           << std::endl;
            if (CheckIfInBounds(x) && CheckIfInBounds(y)) {
              if (IsAsteriks(all_lines[x][y])) {
                gear_x_pos = x;
                gear_y_pos = y;
                current_num_is_valid = true;
              }
            }
          }
        }
      }
    }
    std::cout << std::endl;
  }
  int sum = 0;
  for (std::pair<std::pair<int, int>, std::vector<int>> pair : gear_map) {
    int product = 0;
    if (pair.second.size() == 2) {
      product = pair.second[0] * pair.second[1];
    }
    sum += product;
  }
  std::cout << "Sum: " << sum << std::endl;
}