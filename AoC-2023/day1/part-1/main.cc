#include <bits/stdc++.h>
int GetTwoDigitInLine(const std::string& s) {
  int result = 0;
  bool first = true;
  char first_digit;
  char second_digit;
  for (char c : s) {
    if (c - '0' >= 0 && c - '0' <= 9) {
      if (first) {
        first_digit = c;
        first = false;
      }
      second_digit = c;
    }
  }
  std::string result_string;
  result_string.push_back(first_digit);
  result_string.push_back(second_digit);
  result = std::stoi(result_string);
  return result;
}

int main() {
  std::vector<int> v;
  std::string line;
  int sum = 0;
  while (std::cin >> line) {
    v.push_back(GetTwoDigitInLine(line));
  }
  std::cout << "Size of vector: " << v.size() << std::endl;
  for (int i : v) {
    sum += i;
  }
  std::cout << sum << std::endl;
}
