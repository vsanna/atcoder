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

void chmin(ll& a, ll b) {
  if (a > b) {
    a = b;
  }
}
void chmax(ll& a, ll b) {
  if (a < b) {
    a = b;
  }
}

class Solution {
 public:
  int minFlips(vector<vector<int>>& mat) {
    int len = mat.size() * mat[0].size();
    int size = (1 << len);
    int start = 0;
    for (int i = 0; i < mat.size(); i++) {
      for (int j = 0; j < mat[0].size(); j++) {
        start += mat[i][j];
        if (i != mat.size() - 1 || j != mat[0].size() - 1) {
          start = start << 1;
        }
      }
    }
    return bfs(start, size, len, mat);
  }

  // NOTE: 状態遷移のGraphで最短距離探す。edgeが常に1なのでbfsでoK
  int bfs(int start, int size, int len, vector<vector<int>>& mat) {
    int goal = 0;
    vector<bool> visited = vector<bool>(size, false);
    vector<int> distances = vector<int>(size, IINF);
    vector<int> previous = vector<int>(size, -1);
    distances[start] = 0;
    queue<int> queue;
    queue.push(start);

    while (queue.size() > 0) {
      int key = queue.front();
      queue.pop();
      int distanceToHere = distances[key];

      if (key == goal) {
        return distanceToHere;
      }

      visited[key] = true;

      // neighboarを見て更新して
      for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat[0].size(); j++) {
          int maskInt = 0;
          for (int k = 0; k < mat.size(); k++) {
            for (int l = 0; l < mat[0].size(); l++) {
              if ((k == i && l == j) || (k == i - 1 && l == j) ||
                  (k == i + 1 && l == j) || (k == i && l == j + 1) ||
                  (k == i && l == j - 1)) {
                maskInt += 1;
              } else {
                maskInt += 0;
              }
              if (k != mat.size() - 1 || l != mat[0].size() - 1) {
                maskInt = maskInt << 1;
              }
            }
          }
          int next = key ^ maskInt;
          // cout << "next: " << next << ", key: " << key
          //      << ", maskInt: " << maskInt << endl;
          if (!visited[next]) {
            distances[next] = distanceToHere + 1;
            queue.push(next);
          }
        }
      }
    }

    return -1;
  }
};

int main() {
  vector<vector<int>> mat = vector<vector<int>>{
      vector<int>{0, 0},
      vector<int>{0, 1},
  };

  vector<vector<int>> mat2 = vector<vector<int>>{
      vector<int>{1, 1, 1},
      vector<int>{1, 0, 1},
      vector<int>{0, 0, 0},
  };

  vector<vector<int>> mat3 = vector<vector<int>>{
      vector<int>{1, 0, 0},
      vector<int>{1, 0, 0},
  };
  Solution s = Solution();

  cout << s.minFlips(mat) << endl;
  cout << s.minFlips(mat2) << endl;
  cout << s.minFlips(mat3) << endl;
}