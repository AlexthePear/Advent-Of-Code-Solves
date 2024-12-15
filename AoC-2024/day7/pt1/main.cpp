#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

bool Calculate(vector<ll> &nums, ll total, ll i) {
  if (i == nums.size()) {
    // cout << total << endl;
    return total == nums[0];
  }
  return Calculate(nums, total + nums[i], i + 1) ||
         Calculate(nums, total * nums[i], i + 1);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  string line;
  ll ans = 0;
  while (getline(cin, line)) {
    vector<ll> nums;
    string num = "";
    for (int i = 0; i < line.size(); i++) {
      if (isdigit(line[i])) {
        num += line[i];
      } else if (num != "") {
        nums.push_back(stoll(num));
        num = "";
      }
    }
    nums.push_back(stoll(num));
    // cout << "size: " << nums.size() << endl;
    if (Calculate(nums, nums[1], 2)) {
      ans += nums[0];
    }
  }
  cout << ans << endl;
}