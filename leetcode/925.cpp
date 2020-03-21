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
  bool isLongPressedName(string name, string typed) {
    int idx = 0;
    for (int i = 0; i < typed.length(); i++) {
      cout << "i: " << i << ", idx: " << idx << endl;
      if (typed[i] == name[idx]) {
        idx++;
      } else if (idx > 0 && typed[i] == name[idx - 1]) {
        // long prress
        continue;
      } else {
        return false;
      }
    }
    return (idx == (name.length()));
  }
};

int main() {
  Solution s = Solution();
  cout << s.isLongPressedName("alex", "aaleex") << endl;
}