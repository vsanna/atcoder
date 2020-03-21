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
  string reverseVowels(string s) {
    queue<char> chars;
    stack<int> pos;
    const set<char> vowels{
        'a', 'i', 'u', 'e', 'o', 'A', 'I', 'U', 'E', 'O',
    };

    for (int i = 0; i < s.length(); i++) {
      if (vowels.count(s[i])) {
        chars.push(s[i]);
        pos.push(i);
      }
    }
    while (chars.size() > 0) {
      char c = chars.front();
      chars.pop();
      int p = pos.top();
      pos.pop();
      s[p] = c;
    }
    return s;
  }
};

int main() {
  Solution s = Solution();
  cout << s.reverseVowels("leetcode") << endl;
  cout << s.reverseVowels("hello") << endl;
  cout << s.reverseVowels("nmsk") << endl;
  cout << s.reverseVowels("oae") << endl;
  cout << s.reverseVowels("oe") << endl;
  cout << s.reverseVowels("o") << endl;
}