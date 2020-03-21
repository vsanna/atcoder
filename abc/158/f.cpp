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
const ll MOD = 998244353;

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

  // pos, dis
  vector<pair<int, int>> robots;
  for (int i = 0; i < N; i++) {
    int x, d;
    cin >> x >> d;
    robots.push_back(make_pair(x, d));
  }

  // TODO: check
  sort(robots.begin(), robots.end(), [](pair<int, int> a, pair<int, int> b) {
    return a.first < b.first ? 1 : (a.first > b.first ? -1 : 0);
  });
}