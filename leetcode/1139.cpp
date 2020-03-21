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

*/
class Solution {
 public:
  int largest1BorderedSquare(vector<vector<int>> &grid) {
    int height = grid.size();
    int width = grid[0].size();

    vector<vector<int>> horizon =
        vector<vector<int>>(height, vector<int>(width, 0));
    vector<vector<int>> vertical =
        vector<vector<int>>(height, vector<int>(width, 0));

    for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
        if (grid[i][j] == 1) {
          horizon[i][j] = (j == 0 ? 0 : horizon[i][j - 1]) + 1;
          vertical[i][j] = (i == 0 ? 0 : vertical[i - 1][j]) + 1;
        }
      }
    }

    int maxLen = 0;
    for (int i = height - 1; i >= 0; i--) {
      for (int j = width - 1; j >= 0; j--) {
        int availableMaxLen = min(horizon[i][j], vertical[i][j]);
        while (availableMaxLen > maxLen) {
          if (horizon[i - availableMaxLen + 1][j] >= availableMaxLen &&
              vertical[i][j - availableMaxLen + 1] >= availableMaxLen) {
            maxLen = availableMaxLen;
          } else {
            availableMaxLen--;
          }
        }
      }
    }

    return maxLen * maxLen;
  }
};

int main() {
  Solution s = Solution();
  vector<vector<int>> grid1 = vector<vector<int>>{
      vector<int>{1, 1, 1},
      vector<int>{1, 0, 1},
      vector<int>{1, 1, 1},
  };
  vector<vector<int>> grid2 = vector<vector<int>>{
      vector<int>{1, 1, 0, 0},
  };
  vector<vector<int>> grid3 = vector<vector<int>>{
      vector<int>{1, 1, 0, 1},
      vector<int>{1, 1, 1, 1},
      vector<int>{0, 1, 0, 1},
      vector<int>{1, 1, 1, 1},
  };
  vector<vector<int>> grid4 = vector<vector<int>>{
      vector<int>{0, 0, 0, 1},
  };
  vector<vector<int>> grid5 = vector<vector<int>>{
      vector<int>{1, 1, 1, 1, 1, 1, 1, 1},
      vector<int>{0, 1, 0, 1, 1, 1, 1, 0},
      vector<int>{1, 1, 0, 1, 0, 1, 1, 1},
      vector<int>{1, 1, 1, 1, 1, 1, 0, 0},
  };
  cout << s.largest1BorderedSquare(grid1) << endl;
  cout << s.largest1BorderedSquare(grid2) << endl;
  cout << s.largest1BorderedSquare(grid3) << endl;
  cout << s.largest1BorderedSquare(grid4) << endl;
  cout << s.largest1BorderedSquare(grid5) << endl;
}