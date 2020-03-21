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
  vector<int> twoSum(vector<int> &nums, int target) {
    // NOTE: c++ではresultを最初に宣言するよう癖付ける
    vector<int> result = vector<int>();
    map<int, int> freq = map<int, int>();

    for (int i = 0; i < nums.size(); i++) {
      // NOTE: contain: map.count(key) > 0. map.find(key) != map.end()
      if (freq.find(target - nums[i]) == freq.end()) {
        freq[nums[i]] = i;
      } else {
        // NOTE: vectorの初期化
        result = vector<int>{i, freq[target - nums[i]]};
      }
    }
    return result;
  }
};

int main() {
  Solution s = Solution();
  auto nums = vector<int>{2, 7, 11, 15};
  s.twoSum(nums, 9);
}