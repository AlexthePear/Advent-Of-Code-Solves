#include <bits/stdc++.h>

#include <iostream>
typedef long long ll;
using namespace std;

bool CheckSolution(int n, int m, pair<int, int> buttonA, pair<int, int> buttonB,
                   pair<int, int> prize) {
  return n * buttonA.first + m * buttonB.first == prize.first &&
         n * buttonA.second + m * buttonB.second == prize.second;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  regex re(R"((\d+).*?(\d+))");
  smatch match;
  string line;
  pair<int, int> buttonA, buttonB, prize;
  ll total_tokens = 0;
  do {
    getline(cin, line);
    regex_search(line, match, re);
    // cout << match[1] << " " << match[2] << endl;
    buttonA = {stoi(match[1]), stoi(match[2])};

    getline(cin, line);

    regex_search(line, match, re);
    // cout << match[1] << " " << match[2] << endl;
    buttonB = {stoi(match[1]), stoi(match[2])};

    getline(cin, line);
    regex_search(line, match, re);
    // cout << match[1] << " " << match[2] << endl;
    prize = {stoi(match[1]), stoi(match[2])};

    ll minx = -1, miny = -1;
    for (ll i = 0; i < 100; i++) {
      for (ll j = 0; j < 100; j++) {
        if (CheckSolution(i, j, buttonA, buttonB, prize)) {
          if (minx == -1 && miny == -1) {
            minx = i;
            miny = j;
          } else {
            minx = min(minx, i);
            miny = min(miny, j);
          }
        }
      }
    }
    if (minx != -1 && miny != -1) {
      total_tokens += (minx * 3) + (miny);
    }

    cout << minx << " " << miny << endl;
  } while (cin >> line);
  cout << total_tokens << endl;
}
