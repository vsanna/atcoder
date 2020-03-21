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
  bool checkValidString(string s) { return solve(s); }

  bool solve(string s) {
    if (s.length() == 0) {
      return true;
    }

    // NOTE: カッコ問題はcloseの数が多くなった時点でinvalid
    set<int> candidate;
    for (int i = 0; i < s.length(); i++) {
      if (i == 0) {
        if (s[i] == '(') {
          candidate.insert(1);
        } else if (s[i] == ')') {
          return false;
        } else {
          candidate.insert(-1);
          candidate.insert(0);
          candidate.insert(1);
        }
        continue;
      }

      if (s[i] == '(') {
        set<int> tmp;
        for (auto n : candidate) {
          tmp.insert(n + 1);
        }
        candidate = tmp;
      } else if (s[i] == ')') {
        set<int> tmp;
        int hasNonNegative = false;
        for (auto n : candidate) {
          if (n - 1 >= 0) {
            tmp.insert(n - 1);
          }
        }
        if (tmp.size() == 0) return false;
        candidate = tmp;
      } else {
        set<int> tmp;
        for (auto n : candidate) {
          if (n - 1 >= 0) tmp.insert(n - 1);
          tmp.insert(n);
          tmp.insert(n + 1);
        }
        if (tmp.size() == 0) return false;
        candidate = tmp;
      }
    }

    // cout << "s: " << s << endl;
    // for (auto n : candidate) {
    //   cout << n << ", ";
    // }
    // cout << endl;

    return candidate.count(0) > 0;
  }

  // NG: TLE. 想定通り
  // bool rec(string s, int pos, int stack) {
  //   if (pos == s.length()) {
  //     return stack == 0;
  //   }

  //   if (s[pos] == '(') {
  //     return rec(s, pos + 1, stack + 1);
  //   } else if (s[pos] == ')') {
  //     if (stack == 0) {
  //       return false;
  //     } else {
  //       return rec(s, pos + 1, stack - 1);
  //     }
  //   } else {
  //     if (stack == 0) {
  //       // close不可なので二マタ
  //       return rec(s, pos + 1, stack + 1) || rec(s, pos + 1, stack);
  //     } else {
  //       // 3マタ
  //       return rec(s, pos + 1, stack + 1) || rec(s, pos + 1, stack - 1) ||
  //              rec(s, pos + 1, stack);
  //     }
  //   }
  // }
};

int main() {
  Solution s = Solution();
  cout << s.checkValidString("(*))") << endl;
  cout << s.checkValidString("(*)") << endl;
  cout << s.checkValidString("(*)))") << endl;
  cout << s.checkValidString("((*))") << endl;
  cout << s.checkValidString("(((*))") << endl;
  cout << s.checkValidString("((*))(()))") << endl;
  cout << s.checkValidString(
              "(((((*(()((((*((**(((()()*)()()()*((((**)())*)*)))))))(())(()))("
              "))((*()()(((()((()*(())*(()**)()(())")
       << endl;
}