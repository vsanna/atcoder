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
  bool search(vector<int> &nums, int target) {
    if (nums.size() == 0) return false;
    return rotatedBinarySearch(nums, 0, nums.size() - 1, target);
  }

  bool rotatedBinarySearch(vector<int> &nums, int low, int high, int target) {
    if (low > high) return false;
    int mid = (low + high) / 2;

    if (nums[mid] == target) return true;

    bool a = false;
    bool b = false;
    bool c = false;
    bool d = false;

    // check right part
    if (nums[mid] < nums[high] &&
        (nums[mid] <= target && target <= nums[high])) {
      a = binarySearch(nums, mid + 1, high, target);
    }
    if (nums[mid] >= nums[high]) {
      b = rotatedBinarySearch(nums, mid + 1, high, target);
    }

    // check left part
    if (nums[mid] > nums[low] && (nums[mid] >= target && target >= nums[low])) {
      c = binarySearch(nums, low, mid - 1, target);
    }
    if (nums[mid] <= nums[low]) {
      d = rotatedBinarySearch(nums, low, mid - 1, target);
    }
    return a || b || c || d;
  }

  bool binarySearch(vector<int> &nums, int low, int high, int target) {
    if (low > high) return false;
    int mid = (low + high) / 2;

    if (nums[mid] == target) {
      return true;
    } else if (nums[mid] < target) {
      return binarySearch(nums, mid + 1, high, target);
    } else {
      return binarySearch(nums, low, mid - 1, target);
    }
  }
};

int main() {
  Solution s = Solution();
  auto nums = vector<int>{1, 1, 3, 1};
  cout << s.search(nums, 0) << endl;
  cout << s.search(nums, 1) << endl;
  cout << s.search(nums, 2) << endl;
  cout << s.search(nums, 3) << endl;
  cout << s.search(nums, 4) << endl;
  cout << s.search(nums, 5) << endl;
  cout << s.search(nums, 6) << endl;
  cout << s.search(nums, 7) << endl;
  cout << s.search(nums, 8) << endl;
  cout << s.search(nums, 9) << endl;
}