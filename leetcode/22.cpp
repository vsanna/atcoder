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
  vector<string> generateParenthesis(int n) {
    vector<string> result;

    if (n <= 0) {
      return result;
    }

    rec(result, "", n, 0, 0);
    return result;
  }

  void rec(vector<string> &result, string current, int size, int opened,
           int opening) {
    if (opened == size && opening == 0) {
      result.push_back(current);
      return;
    }

    if (canOpen(size, opened)) {
      rec(result, current + "(", size, opened + 1, opening + 1);
    }

    if (canClose(opening)) {
      rec(result, current + ")", size, opened, opening - 1);
    }
  }

  bool canOpen(int size, int opened) { return opened < size; }

  bool canClose(int opening) { return opening > 0; }
};

int main() {
  Solution s = Solution();
  for (int i = 0; i < 5; i++) {
    for (auto parentheses : s.generateParenthesis(i)) {
      cout << parentheses << endl;
    }
    cout << "========" << endl;
  }
}