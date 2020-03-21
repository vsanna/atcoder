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
  int flipLights(int n, int m) {
    if (m == 0) {
      return 1;
    }

    if (n == 0) {
      return 1;
    } else if (n == 1) {
      // oddThree
      bitset<2> shown = bitset<2>();
      for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= (m - i); j++) {
          for (int k = 0; k <= (m - i - j); k++) {
            int l = m - i - j - k;
            int oddThree = (i + k + l + 1) % 2;
            int mask = oddThree;
            shown.set(mask, 1);
            if (shown.all()) {
              goto end1;
            }
          }
        }
      }
    end1:
      return shown.count();
    } else if (n == 2) {
      // oddThree, evenNonThreeのみ
      bitset<4> shown = bitset<4>();
      for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= (m - i); j++) {
          for (int k = 0; k <= (m - i - j); k++) {
            int l = m - i - j - k;
            int oddThree = (i + k + l + 1) % 2;
            int evenNonThree = (i + j + 1) % 2;
            int mask = (oddThree << 1) + evenNonThree;
            shown.set(mask, 1);
            if (shown.all()) {
              goto end2;
            }
          }
        }
      }
    end2:
      return shown.count();
    } else if (n == 3) {
      bitset<8> shown = bitset<8>();
      for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= (m - i); j++) {
          for (int k = 0; k <= (m - i - j); k++) {
            int l = m - i - j - k;
            int oddThree = (i + k + l + 1) % 2;
            int oddNonThree = (i + k + 1) % 2;
            int evenNonThree = (i + j + 1) % 2;
            int mask = (oddThree << 2) + (oddNonThree << 1) + evenNonThree;
            shown.set(mask, 1);
            if (shown.all()) {
              goto end3;
            }
          }
        }
      }
    end3:
      return shown.count();
    }

    // i: op1 flip all
    // j: op2 flip even
    // k: op3 flip odd
    // l: op4 flip 3K+1
    // NOTE: op1をm1回やる = m1%2回やると同じ効果。
    bitset<16> shown = bitset<16>();
    for (int i = 0; i <= m; i++) {
      for (int j = 0; j <= (m - i); j++) {
        for (int k = 0; k <= (m - i - j); k++) {
          int l = m - i - j - k;
          int oddThree = (i + k + l + 1) % 2;
          int evenThree = (i + j + l + 1) % 2;
          int oddNonThree = (i + k + 1) % 2;
          int evenNonThree = (i + j + 1) % 2;
          int mask = (oddThree << 3) + (evenThree << 2) + (oddNonThree << 1) +
                     evenNonThree;
          shown.set(mask, 1);

          // TODO: proof
          if (shown.count() >= 8) {
            goto end;
          }

          cout << shown << endl;
        }
      }
    }

  end:
    return shown.count();
  }
};

int main() {
  Solution s = Solution();
  cout << s.flipLights(1000, 10) << endl;
  // cout << s.flipLights(100, 100) << endl;
}