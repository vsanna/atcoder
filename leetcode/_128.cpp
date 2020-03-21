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
  int longestConsecutive(vector<int> &nums) {
    // intの最大幅は4byte = 2^32 =
    bitset<10000000000> shown = bitset<10000000000>();

    for (int n : nums) {
      shown |= bitset<10000000000>((1 << n));
    }

    ll maxlen = 0;
    ll len = 0;
    while (!shown.none()) {
      if (shown[shown.size() - 1] == 0) {
        chmax(maxlen, len);
        len = 0;
      } else {
        len++;
      }
    }

    return maxlen;
  }
};
int main() {
  Solution s = Solution();
  vector<int> nums = vector<int>{9, 4,8, 1, 3, 2};
  cout << sizeof(int) << endl;
  cout << s.longestConsecutive(nums) << endl;
}