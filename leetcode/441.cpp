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
  int arrangeCoins(ll n) {
    if (n <= 1) {
      return n;
    }
    // NOTE: signed 32-bitのサイズのarrayは作れない
    //
    // vector<ll> dp = vector<ll>(n + 1, 0);
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
      sum += i;
      if (sum > n) {
        return i - 1;
      }
    }
    return -1;
  }
};
int main() {
  Solution s = Solution();
  cout << s.arrangeCoins(2) << endl;
  cout << s.arrangeCoins(1804289383) << endl;
  cout << s.arrangeCoins(2147483648) << endl;
}
