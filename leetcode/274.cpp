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
  int hIndex(vector<int> &citations) {
    sort(citations.begin(), citations.end(), greater<int>());

    if (citations.size() == 0 || citations[0] == 0) {
      return 0;
    }

    ll maxhindex = 0;

    for (int i = 0; i < citations.size() - 1; i++) {
      // if paperNum > citations in next pair,
      // current pair is hindex
      ll nextPaperNum = i + 2;
      if (nextPaperNum > citations[i + 1]) {
        maxhindex = i + 1;
        break;
      }
    }

    if (citations[citations.size() - 1] > citations.size()) {
      maxhindex = citations.size();
    }
    return maxhindex;
  }
};

int main() {
  Solution s = Solution();
  vector<int> citations = vector<int>{3, 0, 6, 1, 5};
  cout << s.hIndex(citations) << endl;
}