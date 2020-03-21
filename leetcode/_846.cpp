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
  bool isNStraightHand(vector<int> &hand, int W) {
    if (hand.size() != W * W) {
      return false;
    }

    sort(hand.begin(), hand.end());

    // build freq, nums
    vector<ll> freq = vector<ll>();
    vector<ll> nums = vector<ll>();
    // val, pos
    map<ll, int> shown = map<ll, int>();

    for (int i = 0; i < hand.size(); i++) {
      int val = hand[i];
      int pos = shown[val];
      if (pos < 0) {
        freq[pos]++;
      } else {
        nums.push_back(val);
        shown[val] = nums.size() - 1;
        freq[val] = 1;
      }
    }

    // calc TODO: Wの考慮
    for (int i = 0; i < freq.size(); i++) {
    }
  }
};
int main() {
  Solution s = Solution();
  vector<pair<vector<int>, int>> testcases = vector<pair<vector<int>, int>>{
      make_pair(vector<int>{1, 2, 3, 6, 2, 3, 4, 7, 8}, 3),
      make_pair(vector<int>{1, 2, 3, 4, 5}, 4),
  };

  for (auto test : testcases) {
    cout << s.isNStraightHand(test.first, test.second) << endl;
  }
}