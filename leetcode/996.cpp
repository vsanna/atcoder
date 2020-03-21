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
  int numSquarefulPerms(vector<int> &A) { return solve1(A); }

  int solve1(vector<int> &A) {
    set<ll> frac;
    for (ll i = 0; i * i < 1000000000; i++) {
      frac.insert(i * i);
    }

    if (A.size() == 1) {
      return frac.count(A[0]) == 0 ? 0 : 1;
    }

    map<int, int> freq;
    for (int i = 0; i < A.size(); i++) {
      freq[A[i]]++;
    }

    ll maxVal = -INF;
    for (int i = 0; i < A.size(); i++) {
      chmax(maxVal, A[i]);
    }
    ll availableMaxFrac = maxVal * 2 + 1;

    int count = 0;

    for (auto kv : freq) {
      int val = kv.first;
      freq[val]--;
      rec(count, val, 1, A, frac, freq, availableMaxFrac);
      freq[val]++;
    }

    return count;
  }
  void rec(int &count, int current, int len, vector<int> &A, set<ll> &frac,
           map<int, int> freq, ll availableMaxFrac) {
    if (len == A.size()) {
      count++;
      return;
    }

    for (auto kv : freq) {
      if (kv.second == 0) {
        continue;
      }

      if (frac.count(kv.first + current)) {
        int next = kv.first;
        freq[next]--;
        rec(count, next, len + 1, A, frac, freq, availableMaxFrac);
        freq[next]++;
      }
    }
  }
};

int main() {
  Solution s = Solution();
  // vector<int> A1{0};
  // vector<int> A2{0, 0};
  // vector<int> A3{1, 17, 8};
  vector<int> A4{2, 2, 2};
  // vector<int> A5{1, 2, 3, 4, 5, 6};
  // vector<int> A6{1, 3, 1, 3, 1, 3, 1, 3};
  // vector<int> A7{1, 3, 6, 19, 17};
  vector<int> A8{0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1};
  vector<int> A9{0, 0, 900000001, 0, 0, 0, 1000000000, 900000000, 1, 1, 1, 1};
  // cout << s.numSquarefulPerms(A1) << endl;
  // cout << s.numSquarefulPerms(A2) << endl;
  // cout << s.numSquarefulPerms(A3) << endl;
  cout << s.numSquarefulPerms(A4) << endl;
  // cout << s.numSquarefulPerms(A5) << endl;
  // cout << s.numSquarefulPerms(A6) << endl;
  // cout << s.numSquarefulPerms(A7) << endl;
  cout << s.numSquarefulPerms(A8) << endl;
  cout << s.numSquarefulPerms(A9) << endl;
}