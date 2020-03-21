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
class ResultObject {
 public:
  T result;
  bool err;  // TODO error object
  ResultObject(T result, bool err) {
    this->result = result;
    this->err = err;
  }
};

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
  int bitwiseComplement(int N) {
    if (N == 0) return 1;

    int result = 0;
    vector<int> bits = vector<int>();

    // bitシフト演算子は非破壊
    while (N) {
      bits.push_back(!(N & 1));
      N = N >> 1;
    }

    reverse(bits.begin(), bits.end());

    for (int i = 0; i < bits.size(); i++) {
      int bit = bits[i];
      result = result | bit;
      if (i != bits.size() - 1) {
        result = result << 1;
      }
    }

    return result;
  }
};

int main() {
  Solution s = Solution();
  for (int i = 0; i < 10; i++) {
    cout << "i: " << i << ", result: " << s.bitwiseComplement(i) << endl;
    // cout << "i: " << i << ", " << (i >> 1) << endl;
  }
}