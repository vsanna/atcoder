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
  int findMin(vector<int> &nums) {
    // no rotation
    if (nums[0] < nums[nums.size() - 1]) {
      return nums[0];
    }

    return rec(nums, 0, nums.size() - 1);
  }

  int rec(vector<int> &nums, int low, int high) {
    // len <= 2 担ったらlinear search
    if (low + 2 > high) {
      ll min = INF;
      for (int i = low; i <= high; i++) {
        chmin(min, nums[i]);
      }
      return min;
    }

    int mid = (low + high) / 2;

    if (nums[low] > nums[mid]) {
      return rec(nums, low, mid);
    } else {
      return rec(nums, mid, high);
    }
  }
};

int main() {
  Solution s = Solution();
  // vector<int> nums = vector<int>{7, 8, 1, 2, 3, 4, 5, 6};
  vector<int> nums = vector<int>{1, 2, 3, 4, 5, 6, 7, 8};
  cout << s.findMin(nums) << endl;
}