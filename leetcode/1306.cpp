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
  bool canReach(vector<int> &arr, int start) {
    vector<bool> visited = vector<bool>(arr.size(), false);
    queue<int> to_visit;
    to_visit.push(start);

    while (to_visit.size() > 0) {
      int current = to_visit.front();
      to_visit.pop();

      visited[current] = true;

      if (arr[current] == 0) {
        return true;
      }
      for (int neighboar :
           vector<int>{current - arr[current], current + arr[current]}) {
        if (neighboar >= 0 && neighboar < arr.size() && !visited[neighboar]) {
          to_visit.push(neighboar);
        }
      }
    }

    return false;
  }
};

int main() {
  Solution s = Solution();
  vector<int> A = vector<int>{4, 2, 3, 0, 3, 1, 2};
  cout << s.canReach(A, 5) << endl;

  A = vector<int>{4, 2, 3, 0, 3, 1, 2};
  cout << s.canReach(A, 0) << endl;

  A = vector<int>{3, 0, 2, 1, 2};
  cout << s.canReach(A, 2) << endl;
}