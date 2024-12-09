#include <bits/stdc++.h>
using namespace std;

void solve() {
  // code here
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int a = 0;
  int b = 0;
  priority_queue<int> pq;
  priority_queue<int> pq2;
  while (cin >> a >> b) {
    pq.push(a);
    pq2.push(b);
  }
  long long total_sum = 0;
  while (!pq.empty()) {
    int x = pq.top();
    pq.pop();
    int y = pq2.top();
    pq2.pop();
    total_sum += abs(x - y);
  }
  cout << total_sum << endl;
  return 0;
}
