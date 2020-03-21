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
  int A, B, M;
  cin >> A >> B >> M;
  vector<int> as = vector<int>(A + 1, 0);
  vector<int> bs = vector<int>(B + 1, 0);

  ll minA = INF;
  for (int i = 1; i <= A; i++) {
    int a;
    cin >> a;
    chmin(minA, a);
    as[i] = a;
  }

  ll minB = INF;
  for (int i = 1; i <= B; i++) {
    int b;
    cin >> b;
    chmin(minB, b);
    bs[i] = b;
  }

  ll min = INF;
  for (int i = 0; i < M; i++) {
    int x, y, c;
    cin >> x >> y >> c;
    ll sum = as[x] + bs[y] - c;
    chmin(min, sum);
  }

  chmin(min, (minA + minB));

  cout << min << endl;
}