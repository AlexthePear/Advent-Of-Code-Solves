#include <bits/stdc++.h>

#include <iostream>
typedef long long ll;
using namespace std;

bool is_valid(vector<int> v) {
  bool increase = true;
  bool decrease = true;
  for (int i = 0; i < v.size() - 1; i++) {
    int diff = abs(v[i + 1] - v[i]);
    if (v[i + 1] < v[i]) {
      increase = false;
      break;
    } else if (diff < 1 || diff > 3) {
      increase = false;
      break;
    }
  }
  for (int i = 0; i < v.size() - 1; i++) {
    int diff = abs(v[i + 1] - v[i]);
    if (v[i + 1] > v[i]) {
      decrease = false;
      break;
    } else if (diff < 1 || diff > 3) {
      decrease = false;
      break;
    }
  }
  return increase || decrease;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int total = 0;
  string s;
  while (getline(cin, s)) {
    stringstream ss(s);
    string s1;
    vector<int> v;
    while (ss >> s1) {
      cout << s1 << " ";
      v.push_back(stoi(s1));
    }
    cout << endl;
    bool increase = false;
    bool decrease = false;
    for (int i = 0; i < v.size(); i++) {
      vector<int> temp;
      for (int j = 0; j < v.size(); j++) {
        if (i == j) {
          continue;
        }
        temp.push_back(v[j]);
      }
      increase = increase || is_valid(temp);
      decrease = decrease || is_valid(temp);
    }
    // cout << (increase || decrease) << endl;
    if (increase || decrease) {
      total++;
    }
  }
  cout << total << endl;
}