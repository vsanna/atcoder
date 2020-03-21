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
  unsigned long long a, b, c;
  cin >> a >> b >> c;

  if (c < (a + b)) {
    cout << "No" << endl;
    return 0;
  }
  unsigned long long a_b = a + b;

  if (4 * a * b + 2 * c * a_b < c * c + a_b * a_b) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}