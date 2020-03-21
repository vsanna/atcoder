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
  int firstUniqChar(string s) {
    map<char, pair<int, int>> freqAndPos;
    vector<char> shownOrder;

    for (int i = 0; i < s.length(); i++) {
      char c = s[i];

      if (freqAndPos.count(c) == 0) {
        freqAndPos[c] = make_pair(i, 1);
        shownOrder.push_back(c);
      } else {
        freqAndPos[c].second += 1;
      }
    }

    for (char c : shownOrder) {
      if (freqAndPos[c].second == 1) {
        return freqAndPos[c].first;
      }
    }

    return -1;
  }
};

int main() {
  Solution s = Solution();
  cout << s.firstUniqChar("leetcode") << endl;
  cout << s.firstUniqChar("loveleetcode") << endl;
  cout << s.firstUniqChar("") << endl;
  cout << s.firstUniqChar("abcdcba") << endl;
}