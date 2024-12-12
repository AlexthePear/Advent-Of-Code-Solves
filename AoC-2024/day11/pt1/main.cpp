#include <bits/stdc++.h>

#include <iostream>
typedef long long ll;
using namespace std;

void blink(list<string> &nums) {
  auto it = nums.begin();
  // while (it != nums.end()) {
  //   cout << *it << " ";
  //   it++;
  // }
  // cout << endl;
  // it = nums.begin();

  while (it != nums.end()) {
    string num = *it;
    if (num == "0") {
      *it = "1";
    } else if (num.size() % 2 == 0) {
      string num1 = to_string(stoll(num.substr(0, num.size() / 2)));
      string num2 = to_string(stoll(num.substr(num.size() / 2)));
      *it = num1;
      it++;
      nums.insert(it, num2);
      it--;
    } else {
      *it = to_string(stoll(num) * 2024);
    }
    it++;
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  list<string> nums;
  string num;
  while (cin >> num) {
    // cout << num << " ";
    nums.push_back(num);
  }
  // cout << endl;
  for (int i = 0; i < 25; i++) {
    blink(nums);
  }
  int total = 0;
  // for (auto it = nums.begin(); it != nums.end(); it++) {
  //   cout << *it << " ";
  // }
  cout << nums.size() << endl;
}