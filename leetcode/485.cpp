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
  int findMaxConsecutiveOnes(vector<int> &nums) {
    ll maxlen = 0;
    ll len = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == 1) {
        len++;
      } else {
        chmax(maxlen, len);
        len = 0;
      }
    }
    chmax(maxlen, len);
    return maxlen;
  }
};

int main() {
  Solution s = Solution();
  vector<int> bits = vector<int>{1, 1, 0, 1, 1, 1};
  cout << s.findMaxConsecutiveOnes(words1) << endl;
}