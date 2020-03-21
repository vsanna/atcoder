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

/*
characters of Rotate(Pivot)
(p < q, p: low, q:mid)
1. nums[p] < nums[q]: [p, q] is ascending
  - pivot is the most left side or right part.
2. nums[p] == nums[q]: [p,q] is constant or [p, q] has a pivot
  - ex
    - 2,2,2,1,2
    - 2,1,2,2,2
  - pivot can exist in both parts.
3. nums[p] > nums[q]: [p, q] has pivot
  - in only this case, pivot can be identified.
*/

class Solution {
 public:
  int findMin(vector<int> &nums) {
    return binaryMinSearch(nums, 0, nums.size() - 1);
  }

  int binaryMinSearch(vector<int> &nums, int low, int high) {
    // 要素数2以下でlinear search
    if ((high - low) <= 2) {
      ll min = INF;
      for (int i = low; i <= high; i++) {
        chmin(min, nums[i]);
      }
      return min;
    }

    int mid = (low + high) / 2;

    if (nums[low] < nums[mid]) {
      // [low, mid] ascending

      if (nums[mid] < nums[high]) {
        // [mid, high] ascending
        return nums[low];
        // return binaryMinSearch(nums, low, mid - 1);
      } else {
        // right part has pivot.
        // comapre left terminal value with min in right part
        ll min = nums[low];
        chmin(min, binaryMinSearch(nums, mid, high));
        return min;
      }
    } else if (nums[low] > nums[mid]) {
      // left part has pivot, and so left part includes min value
      return binaryMinSearch(nums, low, mid);
    } else {
      // binarysearch
      ll min = binaryMinSearch(nums, low, mid);
      chmin(min, binaryMinSearch(nums, mid + 1, high));
      return min;
    }
  }
};

int main() {
  Solution s = Solution();
  vector<int> nums1 = vector<int>{1, 3, 5};
  vector<int> nums2 = vector<int>{2, 2, 2, 0, 1};
  vector<int> nums3 = vector<int>{3, 3, 1, 3};
  vector<int> nums4 = vector<int>{1, 3, 3, 3};
  vector<int> nums5 = vector<int>{3, 1, 1, 1};
  cout << s.findMin(nums1) << endl;
  cout << s.findMin(nums2) << endl;
  cout << s.findMin(nums3) << endl;
  cout << s.findMin(nums4) << endl;
  cout << s.findMin(nums5) << endl;
}