#include <bits/stdc++.h>

#include <iostream>
typedef long long ll;
using namespace std;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  string line;
  cin >> line;
  //   cout << line << endl;
  vector<string> new_line;
  int file_idx = 0;
  for (int i = 0; i < line.size(); i++) {
    if (i % 2 == 0) {
      for (int j = 0; j < line[i] - '0'; j++) {
        new_line.push_back(to_string(file_idx));
      }
      file_idx++;
    } else {
      for (int j = 0; j < line[i] - '0'; j++) {
        new_line.push_back(".");
      }
    }
  }

  int left = 0, right = new_line.size() - 1;
  while (left < right) {
    while (right > left && new_line[right] == ".") right--;
    while (left < right && new_line[left] != ".") left++;
    swap(new_line[left], new_line[right]);
    left++;
    right--;
  }
  ll sum = 0;
  for (int i = 0; i < new_line.size(); i++) {
    cout << new_line[i];
    if (new_line[i] == ".") {
      continue;
    }
    sum += (stoi(new_line[i])) * i;
  }

  cout << sum << endl;
}