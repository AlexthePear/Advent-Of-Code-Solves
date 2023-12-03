#include <bits/stdc++.h>
std::string FindFirstDigitInLineReversedString(const std::string& s) {
  std::map<std::string, std::string> word_int_map{
      {"orez", "0"},  {"eno", "1"},  {"owt", "2"}, {"eerht", "3"},
      {"ruof", "4"},  {"evif", "5"}, {"xis", "6"}, {"neves", "7"},
      {"thgie", "8"}, {"enin", "9"}};
  std::set<int> soonestposition;
  for (std::pair<std::string, std::string> pair : word_int_map) {
    if (s.find(pair.first) != std::string::npos) {
      int pos = s.find(pair.first);
      soonestposition.insert(pos);
    }
    if (s.find(pair.second) != std::string::npos) {
      int pos = s.find(pair.second);
      soonestposition.insert(pos);
    }
  }

  int min_pos = *(soonestposition.begin());
  int max_pos = *(soonestposition.end()--);
  // std::cout << min_pos << std::endl;
  for (std::pair<std::string, std::string> pair : word_int_map) {
    if (s.find(pair.first) != std::string::npos) {
      int pos = s.find(pair.first);
      // std::cout << pos << std::endl;
      if (pos == min_pos) {
        // std::cout << "returned: " << pair.second << " from pos " << pos
        //           << " string: " << pair.first << std::endl;
        return pair.second;
      }
    }
    if (s.find(pair.second) != std::string::npos) {
      int pos = s.find(pair.second);
      if (pos == min_pos) {
        // std::cout << "returned: " << pair.second << " from pos " << pos
        //           << " string: " << pair.second << std::endl;
        return pair.second;
      }
    }
  }
  return "";
}
std::string FindFirstDigitInLine(const std::string& s) {
  std::map<std::string, std::string> word_int_map{
      {"zero", "0"},  {"one", "1"},  {"two", "2"}, {"three", "3"},
      {"four", "4"},  {"five", "5"}, {"six", "6"}, {"seven", "7"},
      {"eight", "8"}, {"nine", "9"}};
  std::set<int> soonestposition;
  for (std::pair<std::string, std::string> pair : word_int_map) {
    if (s.find(pair.first) != std::string::npos) {
      int pos = s.find(pair.first);
      soonestposition.insert(pos);
    }
    if (s.find(pair.second) != std::string::npos) {
      int pos = s.find(pair.second);
      soonestposition.insert(pos);
    }
  }

  int min_pos = *(soonestposition.begin());
  // std::cout << min_pos << std::endl;
  for (std::pair<std::string, std::string> pair : word_int_map) {
    if (s.find(pair.first) != std::string::npos) {
      int pos = s.find(pair.first);
      // std::cout << pos << std::endl;
      if (pos == min_pos) {
        // std::cout << "returned: " << pair.second << " from pos " << pos
        //           << " string: " << pair.first << std::endl;
        return pair.second;
      }
    }
    if (s.find(pair.second) != std::string::npos) {
      int pos = s.find(pair.second);
      if (pos == min_pos) {
        // std::cout << "returned: " << pair.second << " from pos " << pos
        //           << " string: " << pair.second << std::endl;
        return pair.second;
      }
    }
  }
  return "";
}
int GetTwoDigitInLine(const std::string& s) {
  std::string reverse_string = s;
  std::reverse(reverse_string.begin(), reverse_string.end());
  int result = 0;

  std::string result_string;

  std::string first_digit = FindFirstDigitInLine(s);
  std::string second_digit = FindFirstDigitInLineReversedString(reverse_string);
  result_string = first_digit + second_digit;
  result = std::stoi(result_string);
  if (result < 10) {
    result *= 11;
  }
  std::cout << result << std::endl;
  return result;
}

int main() {
  std::vector<int> v;
  std::string line;
  int sum = 0;
  while (std::cin >> line) {
    v.push_back(GetTwoDigitInLine(line));
  }
  for (int i : v) {
    sum += i;
  }
  std::cout << "sum: " << sum << std::endl;
}
