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

// 2 pointer
class Solution {
 public:
  vector<int> sortArrayByParity(vector<int> &A) {
    int i = 0;
    int j = A.size() - 1;
    while (i < j) {
      if (A[i] % 2 == 0) {
        i++;
      }
      if (A[j] % 2 == 1) {
        j--;
      }
      if (i >= j) {
        break;
      }

      if (A[i] % 2 == 1 && A[j] % 2 == 0) {
        swap(A[i], A[j]);
      }
    }
    return A;
  }
};

int main() {
  Solution s = Solution();

  vector<int> A = vector<int>{3, 1, 2, 4};
  auto result = s.sortArrayByParity(A);
  for (int i = 0; i < result.size(); i++) {
    cout << result[i] << ",";
  }
  cout << endl;

  A = vector<int>{12, 34, 21, 420, 203, 120, 32};
  result = s.sortArrayByParity(A);
  for (int i = 0; i < result.size(); i++) {
    cout << result[i] << ",";
  }
  cout << endl;

  A = vector<int>{0, 0, 0, 0, 0};
  result = s.sortArrayByParity(A);
  for (int i = 0; i < result.size(); i++) {
    cout << result[i] << ",";
  }
  cout << endl;
}