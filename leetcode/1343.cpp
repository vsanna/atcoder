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
  int numOfSubarrays(vector<int> &arr, int k, int threshold) {
    if (arr.size() < k) {
      return 0;
    }

    int ans = 0;
    int sum = 0;
    for (int i = 0; i < k; i++) {
      sum += arr[i];
    }
    if (sum >= k * threshold) ans++;

    for (int i = k; i < arr.size(); i++) {
      sum = sum - arr[i - k] + arr[i];
      if (sum >= k * threshold) ans++;
    }

    return ans;
  }
};

int main() {
  Solution s = Solution();
  vector<int> A = vector<int>{2, 2, 2, 2, 5, 5, 5, 8};
  cout << s.numOfSubarrays(A, 3, 4) << endl;

  cout << "=====" << endl;
  A = vector<int>{11, 13, 17, 23, 29, 31, 7, 5, 2, 3};
  cout << s.numOfSubarrays(A, 3, 5) << endl;

  A = vector<int>{1, 1, 1, 1, 1};
  cout << s.numOfSubarrays(A, 1, 0) << endl;
}