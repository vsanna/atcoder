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
  int N;
  int P;
  int len_p = to_string(P).length();
  string S;
  cin >> N >> P >> S;
  vector<vector<bool>> dp = vector<vector<bool>>(N, vector<bool>(N, false));

  for (int i = 0; i < N; i++) {
    for (int j = i; j < N; j++) {
      if (j == i) {
        dp[i][j] = stoi(string{S[i]}) % P == 0;
      } else {
        if (j - len_p >= i) {
          dp[i][j] =
              dp[i][j - len_p] && stoi(S.substr(j - len_p, len_p)) % P == 0;
        }
      }
    }
  }

  cout << cnt << endl;
}