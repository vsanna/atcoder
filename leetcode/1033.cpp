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
void dumpvec(vector<T> vec) {
  for (T cnt : vec) {
    cout << cnt << ", ";
  }
  cout << endl;
}

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
  vector<int> numMovesStones(int a, int b, int c) {
    vector<int> pos{a, b, c};
    sort(pos.begin(), pos.end());

    // min
    int mincnt = 0;
    int maxcnt = 0;
    // 1. 3つすでに連続 -> 0
    if (pos[2] - pos[1] == 1 && pos[2] - pos[1] == pos[1] - pos[0]) {
      mincnt = 0;
      maxcnt = 0;
    }
    // 2. 2つ連続
    if ((pos[2] - pos[1] == 1 && pos[1] - pos[0] > 1) ||
        (pos[1] - pos[0] == 1 && pos[2] - pos[1] > 1)) {
      mincnt = 1;
      maxcnt = max(pos[2] - pos[1] - 1, pos[1] - pos[0] - 1);
    }

    // 3. 3つバラバラ
    if (pos[2] - pos[1] > 1 && pos[1] - pos[0] > 1) {
      if (pos[2] - pos[1] == 2 || pos[1] - pos[0] == 2) {
        mincnt = 1;
      } else {
        mincnt = 2;
      }
      maxcnt = (pos[2] - pos[1] - 1) + (pos[1] - pos[0] - 1);
    }

    return vector<int>{mincnt, maxcnt};
  }
};

int main() {
  Solution s = Solution();

  dumpvec(s.numMovesStones(1, 2, 3));
  dumpvec(s.numMovesStones(1, 5, 2));
  dumpvec(s.numMovesStones(3, 10, 21));
}