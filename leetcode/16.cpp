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
  int threeSumClosest(vector<int> &nums, int target) {
    // val, (pos1, pos2)
    unordered_map<int, vector<pair<int, int>>> candidates;
    vector<int> twosums;
    for (int i = 0; i < nums.size(); i++) {
      for (int j = i + 1; j < nums.size(); j++) {
        int twosum = nums[i] + nums[j];
        candidates[twosum].push_back(make_pair(i, j));
        twosums.push_back(twosum);
      }
    }

    sort(twosums.begin(), twosums.end());

    ll closestSum = -INF;
    for (int i = 0; i < nums.size(); i++) {
      int num = nums[i];
      vector<int> positions = findClosestBinarySearch(
          twosums, 0, twosums.size() - 1, (target - num));
      for (int pos : positions) {
        int candidateTwoSum = twosums[pos];
        for (pair<int, int> c : candidates[candidateTwoSum]) {
          // どちらもiではない
          if (c.first != i && c.second != i) {
            int sum = candidateTwoSum + num;
            if (abs(target - closestSum) > abs(target - sum)) {
              closestSum = sum;
            }
          }
        }
      }
    }

    return closestSum;
  }

  // return pos
  vector<int> findClosestBinarySearch(vector<int> &arr, int low, int high,
                                      int target) {
    vector<int> positions;
    if (low + 1 >= high) {
      // TODO: should return pair
      if (abs(target - arr[low]) < abs(target - arr[high])) {
        positions.push_back(low);
      } else if (abs(target - arr[low]) > abs(target - arr[high])) {
        positions.push_back(high);
      } else {
        positions.push_back(low);
        positions.push_back(high);
      }
      return positions;
    }

    int mid = (low + high) / 2;

    if (arr[mid] == target) {
      positions.push_back(mid);
      return positions;
    } else if (arr[mid] < target) {
      return findClosestBinarySearch(arr, mid, high, target);
    } else {
      return findClosestBinarySearch(arr, low, mid, target);
    }
  }
};

int main() {
  Solution s = Solution();
  vector<int> nums{-1, 2, 1, -4, 1000, -201, -300};
  cout << s.threeSumClosest(nums, 0) << endl;
}