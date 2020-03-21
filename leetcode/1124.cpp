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
void dumpvec(vector<T> vec) {
  for (T cnt : vec) {
    cout << cnt << ", ";
  }
  cout << endl;
}

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
  int longestWPI(vector<int> &hours) {
    if (hours.size() == 0) return 0;

    vector<int> rangesum;
    rangesum.resize(hours.size() + 1);
    rangesum[0] = 0;
    for (int i = 1; i <= hours.size(); i++) {
      int tiring = hours[i - 1] > 8 ? 1 : -1;
      rangesum[i] = rangesum[i - 1] + tiring;
    }

    // dumpvec(rangesum);

    ll maxlen = 0;
    for (int i = 0; i <= hours.size(); i++) {
      for (int j = 0; j < i; j++) {
        if (rangesum[j] < rangesum[i]) {
          // cout << "i = " << i << ", j = " << j << endl;
          chmax(maxlen, (i - j));
          break;
        }
      }
    }

    return maxlen;
  }

  // あるタイミングでtiring<=nontiringとなっても、その後tiringが盛り返せることを考慮していない回答
  int solve1(vector<int> &hours) {
    int tiringDaysNum = 0;
    int nonTiringDayNum = 0;

    ll maxLen = -INF;
    int len = 0;

    for (int i = 0; i < hours.size(); i++) {
      if (hours[i] > 8) {
        tiringDaysNum++;
        len++;
      } else {
        nonTiringDayNum++;
        if (nonTiringDayNum >= tiringDaysNum) {
          chmax(maxLen, len);
          len = 0;
        } else {
          len++;
        }
      }
      // dump(tiringDaysNum);
      // dump(nonTiringDayNum);
      // dump(len);
      // dump(maxLen);
    }

    chmax(maxLen, len);
    return maxLen;
  }
};

int main() {
  Solution s = Solution();
  vector<int> hours1{9, 9, 6, 0, 6, 6, 9};
  cout << s.longestWPI(hours1) << endl;
  vector<int> hours2_1{9, 9, 6, 0, 6, 6, 9, 9, 9};
  cout << s.longestWPI(hours2_1) << endl;
  // vector<int> hours2{9, 9, 6, 0, 6,  6,  9,  8, 8,  6,  9, 10, 10,
  //                    3, 3, 3, 3, 10, 10, 10, 3, 10, 10, 3, 10};
  // cout << s.longestWPI(hours2) << endl;
  vector<int> hours3{};
  cout << s.longestWPI(hours3) << endl;
  vector<int> hours4{5};
  cout << s.longestWPI(hours4) << endl;
}