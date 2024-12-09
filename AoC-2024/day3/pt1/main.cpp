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

  regex pattern(R"(mul\((\d{1,3}),(\d{1,3})\))");
  smatch match;
  int total = 0;

  auto it = s.cbegin();
  while (regex_search(it, s.cend(), match, pattern)) {
    int num1 = stoi(match[1].str());
    int num2 = stoi(match[2].str());
    total += num1 * num2;
    it = match.suffix().first;
  }

  cout << total << endl;
  return 0;
}