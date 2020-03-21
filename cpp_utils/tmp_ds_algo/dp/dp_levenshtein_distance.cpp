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
const ll INF = numeric_limits<ll>::max();
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

ll levenshtein_distance(string S, string T) {
  // dp[i][j]: Sのi番目まででTのj番目を再現する最小手数()
  vector<vector<ll>> dp =
      vector<vector<ll>>(S.length() + 1, vector<ll>(T.length() + 1, 0));

  // i番目までを用いて0文字目までを再現する手数はi(rmをi回)
  for (int i = 0; i <= S.length(); i++) {
    dp[i][0] = i;
  }
  // 0番目までを用いてj文字目までを再現する手数はj(insertをj回)
  for (int j = 0; j <= T.length(); j++) {
    dp[0][j] = j;
  }

  for (int i = 1; i <= S.length(); i++) {
    for (int j = 1; j <= T.length(); j++) {
      // S[i]をT[j]に置換する
      ll costForEdit = dp[i - 1][j - 1] + 1;
      // S[i]を除外する = すなわちS[i]はもう使ったとみなす
      ll costForRemove = dp[i][j - 1] + 1;
      // S[i]の手前にT[i]を挿入する = すなわちT[i]はもう実現しているとみなす
      ll costForInsert = dp[i - 1][j] + 1;
      dp[i][j] = min(costForEdit, min(costForRemove, costForInsert));
    }
  }

  for (int i = 1; i <= S.length(); i++) {
    for (int j = 1; j <= T.length(); j++) {
      cout << dp[i][j] << " ";
    }
    cout << endl;
  }

  return dp[S.length()][T.length()];
}

int main() {
  string S, T;
  cin >> S >> T;

  cout << levenshtein_distance(S, T) << endl;
}
