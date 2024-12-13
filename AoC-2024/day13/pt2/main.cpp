#include <bits/stdc++.h>

#include <iostream>
typedef long long ll;
using namespace std;

pair<ll, ll> findIntersection(pair<ll, ll> buttonA, pair<ll, ll> buttonB,
                              pair<ll, ll> prize) {
  auto [a1, a2] = buttonA;
  auto [b1, b2] = buttonB;
  auto [p1, p2] = prize;

  cout << "Button A: " << a1 << " " << b1 << endl;
  cout << "Button B: " << a2 << " " << b2 << endl;
  cout << "Prize: " << p1 << " " << p2 << endl;

  ll det = a1 * b2 - a2 * b1;
  if (det == 0) {
    return {-1, -1};
  }
  if ((p1 * b2 - p2 * b1) % det != 0 || (a1 * p2 - a2 * p1) % det != 0) {
    return {-1, -1};
  }
  ll x = (p1 * b2 - p2 * b1) / det;
  ll y = (a1 * p2 - a2 * p1) / det;
  return {x, y};
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  regex re(R"((\d+).*?(\d+))");
  smatch match;
  string line;
  pair<ll, ll> buttonA, buttonB, prize;
  long long total_tokens = 0;
  do {
    getline(cin, line);
    regex_search(line, match, re);
    // cout << match[1] << " " << match[2] << endl;
    buttonA = {stoll(match[1]), stoll(match[2])};

    getline(cin, line);

    regex_search(line, match, re);
    // cout << match[1] << " " << match[2] << endl;
    buttonB = {stoll(match[1]), stoll(match[2])};

    getline(cin, line);
    regex_search(line, match, re);
    // cout << match[1] << " " << match[2] << endl;
    prize = {stoll(match[1]) + 10000000000000,
             stoll(match[2]) + 10000000000000};

    pair<ll, ll> intersection = findIntersection(buttonA, buttonB, prize);
    cout << "Intersection: " << intersection.first << " " << intersection.second
         << endl;

    if (intersection.first != -1) {
      if (intersection.first < 0 || intersection.second < 0) {
        cout << "Invalid intersection\n";
        continue;
      }
      total_tokens += intersection.first * 3 + intersection.second;
    }
  } while (cin >> line);
  cout << total_tokens << endl;
}
