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
  int longestIncreasingPath(vector<vector<int>> &matrix) {
    return solveByDfsDp(matrix);
  }

  int solveByDfsDp(vector<vector<int>> &matrix) {
    if (matrix.size() == 0) {
      return 0;
    }
    vector<vector<int>> longestPath =
        vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size(), 0));

    for (int i = 0; i < matrix.size(); i++) {
      for (int j = 0; j < matrix[0].size(); j++) {
        // cout << "base(" << i << ", " << j << ")" << endl;
        dfsDp(matrix, longestPath, i, j);
      }
    }

    ll maxLen = 1;
    for (int i = 0; i < matrix.size(); i++) {
      for (int j = 0; j < matrix[0].size(); j++) {
        chmax(maxLen, longestPath[i][j]);
      }
    }
    return maxLen;
  }

  int dfsDp(vector<vector<int>> &matrix, vector<vector<int>> &dp, int i,
            int j) {
    // cout << "current(" << i << ", " << j << ")" << endl;
    if (dp[i][j] > 0) {
      return dp[i][j];
    }

    vector<pair<int, int>> surroundings =
        vector<pair<int, int>>{make_pair(i - 1, j), make_pair(i, j - 1),
                               make_pair(i + 1, j), make_pair(i, j + 1)};
    ll maxLen = 1;

    for (pair<int, int> nextCell : surroundings) {
      if (nextCell.first >= 0 && nextCell.first < matrix.size() &&
          nextCell.second >= 0 && nextCell.second < matrix[0].size()) {
        if (matrix[nextCell.first][nextCell.second] > matrix[i][j]) {
          chmax(maxLen, 1 + dfsDp(matrix, dp, nextCell.first, nextCell.second));
        }
      }
    }
    dp[i][j] = maxLen;
    return maxLen;
  }

  int solveByOnlyDfs(vector<vector<int>> &matrix) {
    // NOTE: からのmatrixの可能性あり
    if (matrix.size() == 0) {
      return 0;
    }

    ll maxPath = 0;
    vector<vector<bool>> visited = vector<vector<bool>>(
        matrix.size(), vector<bool>(matrix[0].size(), false));

    for (int i = 0; i < matrix.size(); i++) {
      for (int j = 0; j < matrix[0].size(); j++) {
        // cout << "base(" << i << ", " << j << ")" << endl;
        chmax(maxPath, dfs(matrix, visited, i, j, 1));
      }
    }

    return maxPath;
  }

  int dfs(vector<vector<int>> &matrix, vector<vector<bool>> &visited, int i,
          int j, int currentLen) {
    // cout << "current(" << i << ", " << j << "), " << currentLen << endl;

    vector<pair<int, int>> surroundings =
        vector<pair<int, int>>{make_pair(i - 1, j), make_pair(i, j - 1),
                               make_pair(i + 1, j), make_pair(i, j + 1)};

    ll maxLen = currentLen;

    visited[i][j] = true;

    for (pair<int, int> nextCell : surroundings) {
      if (nextCell.first >= 0 && nextCell.first < matrix.size() &&
          nextCell.second >= 0 && nextCell.second < matrix[0].size()) {
        // cout << "matrix[nextCell.first][nextCell.second] > matrix[i][j]"
        //      << matrix[nextCell.first][nextCell.second] << endl;
        // cout << "matrix[nextCell.first][nextCell.second] > matrix[i][j]"
        //      << matrix[i][j] << endl;
        // cout << "!visited[i][j]" << !visited[i][j] << endl;
        if (matrix[nextCell.first][nextCell.second] > matrix[i][j] &&
            !visited[nextCell.first][nextCell.second]) {
          chmax(maxLen, dfs(matrix, visited, nextCell.first, nextCell.second,
                            currentLen + 1));
        }
      }
    }

    visited[i][j] = false;

    return maxLen;
  }
};

int main() {
  Solution s = Solution();
  vector<vector<int>> matrix1 = vector<vector<int>>{
      vector<int>{9, 9, 4}, vector<int>{6, 6, 8}, vector<int>{2, 1, 1},
      // vector<int>{3, 4, 5},
      // vector<int>{3, 2, 6},
      // vector<int>{2, 2, 1},
  };

  // [
  // [ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 ],
  // [ 19, 18, 17, 16, 15, 14, 13, 12, 11, 10 ],
  // [ 20, 21, 22, 23, 24, 25, 26, 27, 28, 29 ],
  // [ 39, 38, 37, 36, 35, 34, 33, 32, 31, 30 ],
  // [ 40, 41, 42, 43, 44, 45, 46, 47, 48, 49 ],
  // [ 59, 58, 57, 56, 55, 54, 53, 52, 51, 50 ],
  // [ 60, 61, 62, 63, 64, 65, 66, 67, 68, 69 ],
  // [ 79, 78, 77, 76, 75, 74, 73, 72, 71, 70 ],
  // [ 80, 81, 82, 83, 84, 85, 86, 87, 88, 89 ],
  // [ 99, 98, 97, 96, 95, 94, 93, 92, 91, 90 ],
  // [ 100, 101, 102, 103, 104, 105, 106, 107, 108, 109 ],
  // [ 119, 118, 117, 116, 115, 114, 113, 112, 111, 110 ],
  // [ 120, 121, 122, 123, 124, 125, 126, 127, 128, 129 ],
  // [ 139, 138, 137, 136, 135, 134, 133, 132, 131, 130 ],
  // [ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ]
  // ]

  cout << s.longestIncreasingPath(matrix1) << endl;
}