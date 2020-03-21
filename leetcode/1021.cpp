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
  string removeOuterParentheses(string S) {
    string ans = "";
    int layer = 0;
    for (int i = 0; i < S.length(); i++) {
      if (S[i] == '(') {
        layer++;
        if (layer != 1) {
          ans += S[i];
        }
      } else {
        layer--;

        if (layer != 0) {
          ans += S[i];
        }
      }
    }

    return ans;
  }
};

int main() {
  Solution s = Solution();
  cout << s.removeOuterParentheses("(()())(())(()(()))") << endl;
  cout << s.removeOuterParentheses("") << endl;
  cout << s.removeOuterParentheses("()()()()()()()()") << endl;
}