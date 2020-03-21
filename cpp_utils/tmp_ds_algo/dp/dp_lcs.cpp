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
const ll INF = 100;  // numeric_limits<ll>::max();
const int MOD = 1000000007;

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

int main() {
  string s, t;
  cin >> s >> t;
  vector<vector<ll>> dp =
      vector<vector<ll>>(s.length() + 1, vector<ll>(t.length() + 1, 0));

  for (int j = 0; j <= t.length(); j++) {
    dp[0][j] = 0;
  }
  for (int i = 0; i <= s.length(); i++) {
    dp[i][0] = 0;
  }

  for (int i = 1; i <= s.length(); i++) {
    for (int j = 1; j <= t.length(); j++) {
      if (s[i - 1] == t[j - 1]) {
        if (i == 0 || j == 0) {
          dp[i][j] = 1;
        } else {
          dp[i][j] = dp[i - 1][j - 1] + 1;
        }
      } else {
        if (dp[i - 1][j] > dp[i][j - 1]) {
          dp[i][j] = dp[i - 1][j];
        } else {
          dp[i][j] = dp[i][j - 1];
        }
      }
    }
  }
  //   for (auto row : dp) {
  //     for (auto cell : row) {
  //       cout << (cell == "" ? "-" : cell) << " ";
  //     }
  //     cout << endl;
  //   }

  // 復元
  ll i = s.length();
  ll j = t.length();
  string res = "";
  while (i > 0 && j > 0) {
    if (dp[i][j] == dp[i - 1][j]) {
      i--;
      continue;
    }
    if (dp[i][j] == dp[i][j - 1]) {
      j--;
      continue;
    }
    res = s[i - 1] + res;
    i--;
    j--;
  }

  cout << res << endl;
}