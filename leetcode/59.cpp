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
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> matrix = vector<vector<int>>(n, vector<int>(n, 0));
    rec(matrix, 0, 1);
    return matrix;
  }

  void rec(vector<vector<int>> &matrix, int layer, ll startnum) {
    if (startnum > matrix.size() * matrix.size()) {
      return;
    }

    int edgelen = matrix.size() - 2 * layer;
    int lastnum = startnum + (edgelen - 1) * 4 - 1;

    for (int i = layer; i < matrix.size() - layer; i++) {
      for (int j = layer; j < matrix.size() - layer; j++) {
        if (i == layer) {
          if (j == layer) {
            matrix[i][j] = startnum;
          } else {
            matrix[i][j] = matrix[i][j - 1] + 1;
          }
        } else if (i == matrix.size() - layer - 1) {
          if (j == layer) {
            int base = startnum + edgelen * 3 - 3;
            matrix[i][j] = base;
          } else {
            matrix[i][j] = matrix[i][j - 1] - 1;
          }
        } else {
          if (j == layer) {
            matrix[i][j] = lastnum - (i - 1 - layer);
          } else if (j == matrix.size() - layer - 1) {
            matrix[i][j] = matrix[i - 1][j] + 1;
          }
        }
      }
    }
    rec(matrix, layer + 1, lastnum + 1);
  }
};

int main() {
  Solution s = Solution();
  auto result = s.generateMatrix(1);
  for (int i = 0; i < result.size(); i++) {
    for (int j = 0; j < result.size(); j++) {
      cout << result[i][j] << " ";
    }
    cout << endl;
  }
  cout << "=======" << endl;
  result = s.generateMatrix(3);
  for (int i = 0; i < result.size(); i++) {
    for (int j = 0; j < result.size(); j++) {
      cout << result[i][j] << " ";
    }
    cout << endl;
  }
  cout << "=======" << endl;
  result = s.generateMatrix(4);
  for (int i = 0; i < result.size(); i++) {
    for (int j = 0; j < result.size(); j++) {
      cout << result[i][j] << " ";
    }
    cout << endl;
  }
  cout << "=======" << endl;
  result = s.generateMatrix(10);
  for (int i = 0; i < result.size(); i++) {
    for (int j = 0; j < result.size(); j++) {
      cout << result[i][j] << " ";
    }
    cout << endl;
  }
}