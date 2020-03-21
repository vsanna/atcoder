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

// // NOTE: C++のslice, subvector
// int start = 0;
// int size = i + 1;
// vector<int> leftpart(A.cbegin() + start, A.cbegin() + size + 1);

class Solution {
 public:
  vector<int> threeEqualParts(vector<int> &A) {
    if (A.size() <= 2) return vector<int>{-1, 1};
    for (int i = 0; i <= A.size() - 3; i++) {
      int j = rec(A, i, i + 1, A.size() - 1);
      if (j >= 0) {
        return vector<int>{i, j};
      }
    }
    return vector<int>{-1, -1};
  }

  // 対象期間から二分した二分した各領域が等しい値になるiを返す
  int rec(vector<int> &A, int lefthigh, int low, int high) {
    if (low == high) {
      return -1;
    }
    if (low + 1 == high) {
      if (A[low] == A[high]) {
        return high;
      }
    }

    int mid = (low + high) / 2;
    int comp = compBitArr(A, 0, lefthigh, mid + 1, high);
    if (comp == 0) {
      // leftとrightが一致。leftとmiddleを比較する
    } else if (comp < 0) {
      // leftよりもrightのほうが大きい. rightの幅を狭めて探索
      return rec(A, lefthigh, mid, high);
    } else {
      // leftよりもrightのほうが小さい. middleの幅を狭めて探索
      return rec(A, lefthigh, low, mid);
    }
  }

  // left == right -> 0
  // left > right -> 1
  // left < right -> -1
  int compBitArr(vector<int> &A, int leftlow, int lefthigh, int rightlow,
                 int righthigh) {
    while (leftlow <= lefthigh && A[leftlow] == 0) {
      leftlow++;
    }
    while (rightlow <= righthigh && A[rightlow] == 0) {
      rightlow++;
    }

    if ((lefthigh - leftlow) > (righthigh - rightlow)) {
      return 1;
    } else if ((lefthigh - leftlow) < (righthigh - rightlow)) {
      return -1;
    }

    while (leftlow <= lefthigh && rightlow <= righthigh) {
      if (A[leftlow] > A[rightlow]) {
        return 1;
      } else if (A[leftlow] < A[rightlow]) {
        return -1;
      }

      leftlow++;
      rightlow++;
    }

    return 0;
  }
};
int main() {
  Solution s = Solution();
  vector<int> A = vector<int>{1, 0, 1, 0, 1};
  cout << s.threeEqualParts(A) << endl;
}