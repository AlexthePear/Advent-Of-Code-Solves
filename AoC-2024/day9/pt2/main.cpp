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
  unordered_set<string> swapped;
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

  for (int j = 0; j < new_line.size(); j++) {
    cout << new_line[j] << " ";
  }

  cout << endl;

  for (int i = new_line.size() - 1; i >= 0;) {
    while (i >= 0 && new_line[i] == "." && swapped.count(new_line[i]) == 0) {
      i--;
    }
    if (i < 0) {
      break;
    }
    string start = new_line[i];
    int num_size = 0;
    cout << start << " length:  ";
    while (i >= 0 && new_line[i] == start) {
      i--;
      num_size++;
    }
    cout << num_size << endl;

    int j = i;
    int free_space = 0;
    int idx_min = new_line.size();
    while (j >= 0) {
      if (new_line[j] == ".") {
        free_space++;
      } else {
        if (free_space >= num_size) {
          idx_min = j + 1;
        }
        free_space = 0;
      }
      j--;
    }

    if (idx_min < new_line.size()) {
      idx_min;
      i++;
      // swapped.insert(new_line[i]);
      for (int k = 0; k < num_size; k++) {
        cout << "swapping " << new_line[idx_min + k] << " with "
             << new_line[i + k] << endl;
        swap(new_line[idx_min + k], new_line[i + k]);
      }
      // for (int j = 0; j < new_line.size(); j++) {
      //   cout << new_line[j] << " ";
      // }

      // cout << endl;
    }
  }

  ll sum = 0;
  for (int i = 0; i < new_line.size(); i++) {
    cout << new_line[i];
    if (new_line[i] == ".") {
      continue;
    }
    sum += (stoi(new_line[i])) * i;
  }
  cout << endl;
  cout << sum << endl;
}