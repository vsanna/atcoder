#include <algorithm>
#include <bitset>
#include <cmath>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;
const int IINF = 1e9;
const ll INF = 1e18;
const int MOD = 1e9 + 7;

#define dump(x) cout << #x << " = " << (x) << endl;
#define YES(n) cout << ((n) ? "YES" : "NO") << endl

template <typename T>
class ResultObject {
 public:
  T result;
  bool err;  // TODO error object
  ResultObject(T result, bool err) {
    this->result = result;
    this->err = err;
  }
};

void chmin(ll &a, ll b) {
  if (a > b) {
    a = b;
  }
}
void chmax(ll &a, ll b) {
  if (a < b) {
    a = b;
  }
}

class Solution {
 public:
  int minMoves(vector<int> &nums) { return byCalc(nums); }

  int byCalc(vector<int> &nums) {
    ll count = 0;
    sort(nums.begin(), nums.end());

    for (int i = nums.size() - 1; i > 0; i--) {
      if (nums[i] == nums[i - 1]) {
        continue;
      }
      ll dif = nums[i] - nums[i - 1];
      count += dif * (nums.size() - i);
    }

    return count;
  }

  int bySort(vector<int> &nums) {
    ll count = 0;
    ll size = nums.size();

    while (true) {
      sort(nums.begin(), nums.end());

      for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << ", ";
      }
      cout << endl;

      int current = nums[0];
      if (nums[0] == nums[nums.size() - 1]) {
        break;
      }

      count++;
      for (int i = 0; i < size - 1; i++) {
        nums[i]++;
      }
    }
    return count;
  }
};

int main() {
  Solution s = Solution();
  auto nums = vector<int>{1, 2, 3};
  // auto nums = vector<int>{1, 2147483647};
  // auto nums = vector<int>{1, 2147483647};
  cout << s.minMoves(nums) << endl;
}