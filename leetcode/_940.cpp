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
  int distinctSubseqII(string S) {
    if (S.length() <= 1) {
      return S.length();
    }

    // iまでで終わる(iで終わらなくてもいい)末尾kで終わるパターン数
    vector<vector<ll>> dp = vector<vector<ll>>(S.length(), vector<ll>(26, 0));
    vector<ll> increasing = vector<ll>(S.length());

    dp[0][S[0] - 'a'] = 1;
    increasing[0] = 1;

    for (int i = 1; i < S.length(); i++) {
      for (char c = 'a'; c <= 'z'; c++) {
        if (S[i] == c) {
          if (S[i - 1] == 0) {
            // new char.
            ll sum = 1L;
            // TODO: c++のreduce
            for (char c2 = 'a'; c2 <= 'z'; c2++) {
              sum += (dp[i - 1][c2 - 'a'] % MOD);
              sum = sum % MOD;
            }
            increasing[i] = sum;
            cout << S.substr(0, i + 1) << ":" << sum << endl;
            dp[i][c - 'a'] = sum;
          } else {
            // exisiting char.
            int lastShownIdx = 0;
            for (int j = i - 1; j > 0; j--) {
              if (dp[j][c - 'a'] > dp[j - 1][c - 'a']) {
                lastShownIdx = j;
                break;
              }
            }
            ll sum = 0L;
            for (int k = lastShownIdx; k < i; k++) {
              sum += increasing[k];
              sum = sum % MOD;
            }
            increasing[i] = sum;
            cout << S.substr(0, i + 1) << ":" << sum << endl;
            dp[i][c - 'a'] = sum;
          }
        } else {
          dp[i][c - 'a'] = dp[i - 1][c - 'a'];
        }
      }
    }

    ll sum = 0L;
    for (char c = 'a'; c <= 'z'; c++) {
      sum += (dp[S.length() - 1][c - 'a'] % MOD);
      sum = sum % MOD;
    }

    for (char c = 'a'; c <= 'z'; c++) {
      for (int i = 0; i < S.length(); i++) {
        // TODO: debug
      }
    }
    return sum;
  }

  void rec(vector<vector<int>> &dp, int i, string &S) {}
};
int main() {
  Solution s = Solution();

  // cout << s.distinctSubseqII("aaa") << endl;
  // cout << s.distinctSubseqII("abc") << endl;
  cout << s.distinctSubseqII("abb") << endl;
}