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

/*
NOTE: map[i] はなければデフォルト値(intなら0)を"追加"してしまう
map.at(i)はkeyがなければ std::out_of_range: をthrowする
map.count(i)を使う
map.find(i) or c++20からはmap.contain(i)でもいい。
この場合の計算量はO(logN) なぜならmapの実装がBSTだから
unordered_map がいわゆるHashMapでO(1)
*/
class Solution {
 public:
  int lenLongestFibSubseq(vector<int> &A) {
    if (A.size() < 3) {
      return 0;
    }

    // i, jを最後とするfibの最長値　
    vector<vector<int>> dp = vector<vector<int>>();
  }

  int rec(vector<int> &A, vector<vector<int>> &dp, int pos) {
    int num = A[pos];
    unordered_map<int, int> shown{};

    ll maxlen = 1;
    for (int i = 0; i < pos; i++) {
      if (shown.count(num - A[i])) {
        // find pair
        chmax(maxlen, rec())
      } else {
        shown[A[i]] = i;
      }
    }
  }
};

int main() {
  Solution s = Solution();
  vector<int> nums = vector<int>{1, 2, 3, 4, 5, 6, 7, 8};
  // vector<int> nums = vector<int>{1, 3, 7, 11, 12, 14, 18};
  // vector<int> nums = vector<int>{1, 3, 4, 7, 10, 11, 12, 18, 23, 35};
  cout << s.lenLongestFibSubseq(nums) << endl;
}