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
  int numberOfArithmeticSlices(vector<int> &A) {
    if (A.size() < 3) return 0;

    vector<int> diffs{};
    for (int i = 1; i < A.size(); i++) {
      diffs.push_back(A[i] - A[i - 1]);
    }

    int ans = 0;
    int pos = 0;
    int len = 0;
    int currentd = diffs[pos];
    while (pos < diffs.size()) {
      if (diffs[pos] == currentd) {
        pos++;
        len++;
        continue;
      }
      // dump(len);
      if (len >= 2) {
        // (len-1)までの和
        ans += ((len - 1) * (len - 1 + 1)) / 2;
      }

      currentd = diffs[pos];
      len = 1;
      pos++;
    }
    if (len >= 2) {
      // (len-1)までの和
      ans += ((len - 1) * (len - 1 + 1)) / 2;
    }
    // dump(len);

    return ans;
  }
};

int main() {
  Solution s = Solution();
  vector<int> A{1, 2, 3, 4, 8, 9, 10};
  cout << s.numberOfArithmeticSlices(A) << endl;
}