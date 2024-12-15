#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

bool ProcessPages(vector<int>& v, unordered_map<int, unordered_set<int>>& mp) {
  unordered_set<int> badpages;
  for (int i = v.size() - 1; i >= 0; i--) {
    if (badpages.count(v[i])) {
      return false;
    }
    // cout << v[i] << " ";
    // for (int i : mp[v[i]]) {
    //   cout << i << " ";
    // }
    // cout << endl;
    badpages.insert(mp[v[i]].begin(), mp[v[i]].end());
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  unordered_map<int, unordered_set<int>> mp;
  string line;
  int total = 0;
  while (getline(cin, line)) {
    if (line.find("|") != string::npos) {
      //   cout << line.substr(0, 2) << endl;
      //   cout << line.substr(3, 2) << endl;
      int a = stoi(line.substr(0, 2));
      int b = stoi(line.substr(3, 2));
      //   cout << a << " | " << b << endl;
      mp[a].insert(b);
    }

    if (line.find(",") != string::npos) {
      vector<int> v;

      for (int i = 0; i < line.size(); i += 3) {
        v.push_back(stoi(line.substr(i, 2)));
      }
      if (!ProcessPages(v, mp)) {
        sort(v.begin(), v.end(),
             [&mp](int a, int b) { return mp[b].find(a) != mp[b].end(); });

        int mid = v.size() / 2;
        total += v[mid];
      }
    }
  }
  cout << total << endl;
}