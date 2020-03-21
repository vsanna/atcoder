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
  int minimumDeleteSum(string s1, string s2) {
    int i = 0;
    int j = 0;
    ll sum = 0;
    vector<char> to_delete;
    while (i < s1.length() || j < s2.length()) {
      if (i == s1.length()) {
        sum += int(s2[j]);
        to_delete.push_back(s2[j]);
        j++;
        continue;
      }
      if (j == s2.length()) {
        sum += int(s1[i]);
        to_delete.push_back(s1[i]);
        i++;
        continue;
      }

      if (s1[i] == s2[j]) {
        i++;
        j++;
        continue;
      } else {
        if (s1[i] < s2[j]) {
          sum += int(s1[i]);
          to_delete.push_back(s1[i]);
          i++;
        } else {
          sum += int(s2[j]);
          to_delete.push_back(s2[j]);
          j++;
        }
      }
    }

    for (char c : to_delete) {
      cout << c << ", ";
    }
    cout << endl;

    return sum;
  }
};

int main() {
  Solution s = Solution();
  cout << s.minimumDeleteSum("sea", "eat") << endl;
}