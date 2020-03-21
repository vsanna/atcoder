#include <algorithm>
#include <bitset>
#include <cmath>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
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
  int findDuplicate(vector<int> &nums) {
    int low = 1;
    int high = nums.size() - 1;
    return rec(nums, low, high);
  }

  // その値の範囲の中にdupがあればその値を、なければ-1を返す
  int rec(vector<int> &nums, int low, int high) {
    if (low == high) {
      // int cnt = 0;
      // for (auto num : nums) {
      //   if (num == low) {
      //     cnt++;
      //   }
      //   if (cnt > 1) {
      //     break;
      //   }
      // }

      // return (cnt == 1) ? low : -1;
      return low;
    }

    int mid = (low + high) / 2;

    int expectedCnt = (mid - low + 1);
    int actualCnt = 0;
    int expectedSum = (low + mid) * (mid - low + 1) / 2;
    int actualSum = 0;

    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] >= low && nums[i] <= mid) {
        actualCnt++;
        actualSum += nums[i];
      }
    }

    if (actualCnt > expectedCnt) {
      // ポジション奪っている
      return rec(nums, low, mid);
    } else if (actualCnt < expectedCnt) {
      // 他方にdupいる(ポジションを奪われている)
      return rec(nums, mid + 1, high);
    } else {
      if (actualSum == expectedSum) {
        // 他方にdupいる
        return rec(nums, mid + 1, high);
      } else {
        // cntが同じでsumが違う = dupを抱え込んでいる
        return rec(nums, low, mid);
      }
    }
  }
};

int main() {
  Solution s = Solution();
  vector<int> nums{1, 3, 4, 2, 2};
  cout << s.findDuplicate(nums) << endl;
  nums = vector<int>{3, 1, 3, 4, 2};
  cout << s.findDuplicate(nums) << endl;
  nums = vector<int>{1, 2, 3, 5, 6, 6, 6, 7, 8};
  cout << s.findDuplicate(nums) << endl;
}