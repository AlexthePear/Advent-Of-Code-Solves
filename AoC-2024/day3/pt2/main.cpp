#include <bits/stdc++.h>

#include <iostream>
#include <regex>
typedef long long ll;
using namespace std;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  string s, line;
  while (getline(cin, line)) {
    s += line;
  }

  std::regex mulPattern(R"(mul\((\d{1,3}),(\d{1,3})\))");
  std::regex doPattern(R"(do\(\))");
  std::regex dontPattern(R"(don't\(\))");

  bool isEnabled = true;
  int totalSum = 0;

  std::regex combinedPattern(R"(mul\((\d{1,3}),(\d{1,3})\)|do\(\)|don't\(\))");
  std::sregex_iterator iter(s.cbegin(), s.cend(), combinedPattern);
  std::sregex_iterator end;

  while (iter != end) {
    std::smatch match = *iter;

    if (match[0].matched) {
      if (std::regex_match(match[0].str(), doPattern)) {
        isEnabled = true;  // Enable future mul instructions
      } else if (std::regex_match(match[0].str(), dontPattern)) {
        isEnabled = false;  // Disable future mul instructions
      } else if (std::regex_match(match[0].str(), mulPattern) && isEnabled) {
        int x = std::stoi(match[1]);
        int y = std::stoi(match[2]);
        totalSum += x * y;
      }
    }

    ++iter;
  }

  std::cout << "Total sum of valid mul instructions: " << totalSum << std::endl;
  return 0;
}