#include <bits/stdc++.h>
using namespace std;

void solve() {
  // code here
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int a = 0;
  int b = 0;
  vector<int> v;
  unordered_map<int, int> m;
  while (cin >> a >> b) {
    v.push_back(a);
    m[b]++;
  }
  int total_sum = 0;
  for (int x : v) {
    if (m.count(x)) {
      total_sum += m[x] * x;
    }
  }
  cout << total_sum << endl;
  return 0;
}
