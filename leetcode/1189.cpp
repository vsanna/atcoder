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
  int maxNumberOfBalloons(string text) {
    unordered_map<char, int> freq;
    for (char c : text) {
      freq[c]++;
    }
    return min({freq['b'], freq['a'], freq['l'] / 2, freq['o'] / 2, freq['n']});
  }
};

int main() {
  Solution s = Solution();
  cout << s.maxNumberOfBalloons("nlaebolko") << endl;
  cout << s.maxNumberOfBalloons("loonbalxballpoon") << endl;
  cout << s.maxNumberOfBalloons("leetcode") << endl;
}