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
  cin >> N;

  vector<vector<string>> result =
      vector<vector<string>>(N + 1, vector<string>());

  // 文字列の長さi
  for (int i = 1; i <= N; i++) {
    if (i == 1) {
      result[i].push_back("a");
    } else {
      // いくつのaを用いるかj
      for (int j = 1; j <= i; j++) {
        if (j == i) {
          string candidate = "";
          for (int m = 0; m < i; m++) {
            candidate += 'a';
          }
          result[i].push_back(candidate);
        } else {
          int blocklen = (i - j);
          for (string filler : result[i]) {
            vector<char> tmpstr = vector<char>(i, 'a');
          }
        }
      }
    }
  }

  vector<string> ans;
  for (int i = 0; i < result.size(); i++) {
    for (string candidate : result[i]) {
      ans.push_back(candidate);
    }
  }

  sort(ans.begin(), ans.end());

  // cout << "====" << endl;
  for (int i = 0; i < ans.size(); i++) {
    // if (ans[i].length() == N) {
    cout << ans[i] << endl;
    // }
  }
}