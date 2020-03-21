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
  string breakPalindrome(string palindrome) {
    int mid = (palindrome.size() - 1) / 2;

    for (int i = 0; i <= mid; i++) {
      if (i < mid) {
        if (palindrome[i] == 'a') {
          continue;
        } else {
          palindrome[i] = 'a';
          return palindrome;
        }
      } else {
        if (palindrome.size() % 2 == 1) {
          continue;  // 後ろからcheck
        } else {
          if (palindrome[i] == 'a') {
            continue;
          } else {
            palindrome[i] = 'a';
            return palindrome;
          }
        }
      }
    }

    int lattermid = palindrome.size() % 2 == 0 ? mid : mid;
    for (int i = palindrome.size() - 1; i >= lattermid; i--) {
      if (i > lattermid) {
        if (palindrome[i] == 'x') {
          continue;
        } else {
          palindrome[i] = palindrome[i] + 1;
          return palindrome;
        }
      } else {
        if (palindrome.size() % 2 == 1) {
          return "";  // 後ろから見てもだめならだめ
        } else {
          if (palindrome[i] == 'x') {
            continue;
          } else {
            palindrome[i] = palindrome[i] + 1;
            return palindrome;
          };
        }
      }
    }

    return "";
  }
};

int main() {
  Solution s = Solution();
  vector<string> testcases = vector<string>{"abccba", "a",
                                            "aa",   // ab
                                            "aaa",  // aab
                                            "aba",  // abb
                                            "cbabc",  "bb", "b", "bbb",
                                            "cc",  // ca
                                            "dd",  // da
                                            "bbb"};

  for (string test : testcases) {
    cout << test << " => " << s.breakPalindrome(test) << endl;
  }
}