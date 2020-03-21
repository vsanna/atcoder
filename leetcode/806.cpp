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
  vector<int> numberOfLines(vector<int> &widths, string S) {
    int linenum = 1;
    int currentlen = 0;
    for (char c : S) {
      if (currentlen + widths[c - 'a'] > 100) {
        currentlen = 0;
        linenum++;
      }
      currentlen += widths[c - 'a'];
    }

    return vector<int>{linenum, currentlen};
  }
};
int main() {
  Solution s = Solution();
  vector<int> widths =
      vector<int>{10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
                  10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
  string S = "abcdefghijklmnopqrstuvwxyz";
  auto result = s.numberOfLines(widths, S);
  cout << result[0] << ":" << result[1] << endl;

  widths = vector<int>{4,  10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
                       10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
  S = "bbbcccdddaaa";
  result = s.numberOfLines(widths, S);
  cout << result[0] << ":" << result[1] << endl;
}
