#include <bits/stdc++.h>

#include <iostream>
typedef long long ll;
using namespace std;

pair<ll, ll> transform(string num) {
  pair<ll, ll> res;
  if (num == "0") {
    res.first = 1;
    res.second = -1;
  } else if (num.size() % 2 == 0) {
    res.first = stoll(num.substr(0, num.size() / 2));
    res.second = stoll(num.substr(num.size() / 2));

  } else {
    res.first = stoll(num) * 2024;
    res.second = -1;
  }
  return res;
}

void blink(unordered_map<string, ll>& nums,
           unordered_map<string, pair<ll, ll>>& memo) {
  unordered_map<string, ll> new_nums;
  for (auto [num, count] : nums) {
    if (memo.find(num) == memo.end()) {
      memo[num] = transform(num);
    }
    auto [num1, num2] = memo[num];

    new_nums[to_string(num1)] += count;
    if (num2 != -1) new_nums[to_string(num2)] += count;
  }
  nums = move(new_nums);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  unordered_map<string, ll> nums;
  string num;
  while (cin >> num) {
    // cout << num << " ";
    nums[num]++;
  }
  // cout << endl;
  unordered_map<string, pair<ll, ll>> memo;
  for (int i = 0; i < 75; i++) {
    blink(nums, memo);
  }
  ll total = 0;
  // for (auto it = nums.begin(); it != nums.end(); it++) {
  //   cout << (*it).first << " ";
  // }
  for (auto [num, count] : nums) {
    total += count;
  }
  cout << total << endl;
}