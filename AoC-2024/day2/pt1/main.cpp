#include <bits/stdc++.h>

#include <iostream>
typedef long long ll;
using namespace std;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int total = 0;
  string s;
  while (getline(cin, s)) {
    stringstream ss(s);
    string s1;
    vector<string> v;
    while (ss >> s1) {
      v.push_back(s1);
    }
    bool increase = true;
    bool decrease = true;
    for (int i = 0; i < v.size() - 1; i++) {
      int diff = abs(stoi(v[i + 1]) - stoi(v[i]));
      if (stoi(v[i + 1]) < stoi(v[i])) {
        increase = false;
        break;
      } else if (diff < 1 || diff > 3) {
        increase = false;
        break;
      }
    }
    for (int i = 0; i < v.size() - 1; i++) {
      int diff = abs(stoi(v[i + 1]) - stoi(v[i]));
      if (stoi(v[i + 1]) > stoi(v[i])) {
        decrease = false;
        break;
      } else if (diff < 1 || diff > 3) {
        decrease = false;
        break;
      }
    }
    if (increase || decrease) {
      total++;
    }
  }
  cout << total << endl;
}