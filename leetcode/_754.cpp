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
  int reachNumber(int target) {
    unordered_set<ll> candidate{0};
    ll n = 0;

    while (true) {
      if (candidate.count(target) > 0) {
        break;
      }

      n++;

      unordered_set<ll> tmp;
      for (ll c : candidate) {
        tmp.insert(c + n);
        tmp.insert(c - n);
      }
      candidate = tmp;

      // for (ll n : tmp) {
      //   cout << n << ",";
      // }
      // cout << endl;
    }

    return n;
  }
  // int reachNumber(int target) {
  //   if (target < 0) {
  //     target = target * -1;
  //   }

  //   int n = 0;
  //   ll sum = 0;

  //   while (sum + n < target) {
  //     sum += n;
  //     n++;
  //   }

  //   if (sum + n == target) {
  //     return n++;
  //   }

  //   if (abs(target - sum) <= abs(sum + n - target)) {
  //     // ここから調整
  //   } else {
  //     // もう一度stepしてから調整
  //     sum += n;
  //     n++;
  //   }
  //   return (n - 1) + abs(target - sum) * 2;
  // }
};

int main() {
  Solution s = Solution();
  for (int i = 0; i < 10; i++) {
    cout << "target: " << i << ", step: " << s.reachNumber(i) << endl;
  }
  cout << "target: " << 100 << ", step: " << s.reachNumber(100) << endl;
  cout << "target: " << 1000 << ", step: " << s.reachNumber(1000) << endl;
  cout << "target: " << 1000000000 << ", step: " << s.reachNumber(1000000000)
       << endl;
  cout << "target: " << -1000000000 << ", step: " << s.reachNumber(-1000000000)
       << endl;
}