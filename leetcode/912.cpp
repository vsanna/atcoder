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
  vector<int> sortArray(vector<int> &nums) { return sort(nums); }

  vector<int> sort(vector<int> &nums) {
    vector<int> bucket = vector<int>(100010, 0);
    vector<int> result = vector<int>();
    for (int n : nums) {
      bucket[n + 50000]++;
    }

    for (int i = 0; i < bucket.size(); i++) {
      if (bucket[i] > 0) {
        for (int j = 0; j < bucket[i]; j++) {
          result.push_back(i - 50000);
        }
      }
    }

    return result;
  }
};
int main() {
  Solution s = Solution();
  vector<int> A = vector<int>{5, 1, 1, 2, 0, 0};

  for (auto n : s.sortArray(A)) {
    cout << n << ", ";
  }
  cout << endl;
}