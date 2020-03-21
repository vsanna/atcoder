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
  int N, T;
  cin >> N >> T;

  ll ans = 0;
  vector<int> as = vector<int>(N, 0);
  vector<int> bs = vector<int>(N, 0);
  vector<int> cost = vector<int>(N, 0);
  vector<bool> used = vector<bool>(N, false);

  for (int i = 0; i < N; i++) {
    int a, b;
    cin >> a >> b;
    as[i] = a;
    bs[i] = b;
    cost[i] = b;
  }

  unordered_set<int> canvisit = unordered_set<int>();
  for (int i = 0; i < N; i++) {
    canvisit.insert(i);
  }

  ll passed = 0;
  while (passed <= T) {
    // 残りの店が全てai = 0 なら小さい順に足す
    int j = 0;
    for (int pos1 : canvisit) {
      if (as[pos1] > 0) {
        break;
      }
      j++;
      if (j == canvisit.size()) {
        // val, pos
        vector<int> bs_copy;
        for (int pos : canvisit) {
          bs_copy.push_back(bs[pos]);
        }
        sort(bs_copy.begin(), bs_copy.end());
        for (int k = 0; k < bs_copy.size(); k++) {
          int cost = bs_copy[k];
          passed++;
          if (passed > T) {
            cout << ans << endl;
            return 0;
          }
          passed += cost;
          if (passed > T) {
            cout << ans << endl;
            return 0;
          }
          ans++;
        }
        cout << ans << endl;
        return 0;
      }
    }

    passed++;
    if (passed > T) {
      break;
    }
    // update and find min
    ll mincost = INF;
    ll minI = -1;
    for (int i : canvisit) {
      cost[i] += as[i];
      if (mincost > cost[i]) {
        mincost = cost[i];
        minI = i;
      }
    }
    canvisit.erase(minI);
    passed += mincost;
    // used[minI] = true;

    if (passed > T) {
      break;
    }

    ans++;

    if (ans == N) {
      break;
    }
  }

  cout << ans << endl;
}