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
  vector<vector<int>> diagonalSort(vector<vector<int>> &mat) {
    int height = mat.size();
    int width = mat[0].size();

    for (int i = (1 - height); i < width; i++) {
      vector<int> tmp;
      for (int j = 0; j < height; j++) {
        if ((i + j) >= 0 && (i + j) < width) {
          tmp.push_back(mat[j][j + i]);
        }
      }

      sort(tmp.begin(), tmp.end());
      for (int j = height - 1; j >= 0; j--) {
        if ((i + j) >= 0 && (i + j) < width) {
          mat[j][j + i] = tmp.back();
          tmp.pop_back();
        }
      }
    }

    return mat;
  }
};

int main() {
  Solution s = Solution();
  vector<vector<int>> mat = vector<vector<int>>{
      vector<int>{3, 3, 1, 1},
      vector<int>{2, 2, 1, 2},
      vector<int>{1, 1, 1, 2},
  };

  auto result = s.diagonalSort(mat);
  for (auto row : mat) {
    for (auto n : row) {
      cout << n << ", ";
    }
    cout << endl;
  }
}