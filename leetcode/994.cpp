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
  static const int EMPTY = 0;
  static const int FRESH = 1;
  static const int ROTTEN = 2;

 public:
  int orangesRotting(vector<vector<int>> &grid) {
    /*
    maxd = -1
    hasFresh = false;
    for(cell: allcell) {
      if (cell == fresh) {
        hasFresh = true;
        // if cannot reach any rotten, return -1
        d = findMostNearbyRotten(cell);
        chmax(maxd, d);
      }
    }
    if(!hasFresh) return 0
    return maxd;
    */

    ll maxd = -1;
    bool hasFresh = false;

    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[i].size(); j++) {
        int cell = grid[i][j];

        if (cell == FRESH) {
          hasFresh = true;
          ll d = distanceToNearbyRotten(grid, i, j);
          // cout << "current(" << i << ", " << j << ") ->" << d << endl;
          if (d == -1) {
            return -1;
          }
          chmax(maxd, d);
        }
      }
    }

    if (!hasFresh) return 0;
    return (int)maxd;
  }

  // return -1 if this cell cannot reach to rotton one.
  ll distanceToNearbyRotten(vector<vector<int>> &grid, int i, int j) {
    queue<pair<int, int>> q = queue<pair<int, int>>();
    vector<vector<bool>> visited =
        vector<vector<bool>>(grid.size(), vector<bool>(grid[0].size(), false));

    q.push(make_pair(i, j));
    const pair<int, int> SEPARATOR = make_pair(-1, -1);
    q.push(SEPARATOR);

    ll d = 0;

    while (!q.empty()) {
      pair<int, int> current = q.front();
      q.pop();

      if (current == SEPARATOR) {
        if (q.empty()) {
          break;
        }

        d++;
        q.push(SEPARATOR);
        continue;
      }

      visited[current.first][current.second] = true;

      if (grid[current.first][current.second] == ROTTEN) {
        return d;
      }

      for (pair<int, int> nextcell : vector<pair<int, int>>{
               make_pair(current.first - 1, current.second),
               make_pair(current.first + 1, current.second),
               make_pair(current.first, current.second - 1),
               make_pair(current.first, current.second + 1)}) {
        if (nextcell.first >= 0 && nextcell.first < grid.size() &&
            nextcell.second >= 0 && nextcell.second < grid[0].size()) {
          if (visited[nextcell.first][nextcell.second]) {
            continue;
          }
          if (grid[nextcell.first][nextcell.second] != EMPTY) {
            // cout << "current(" << current.first << ", " << current.second
            //      << ") => to add(" << nextcell.first << ", " <<
            //      nextcell.second
            //      << ")" << endl;
            q.push(make_pair(nextcell.first, nextcell.second));
          }
        }
      }
    }

    return -1;
  }
};

int main() {
  Solution s = Solution();
  vector<vector<int>> tokens1 = vector<vector<int>>{
      vector<int>{2, 1, 1},
      vector<int>{1, 1, 0},
      vector<int>{0, 1, 1},
  };
  vector<vector<int>> tokens2 = vector<vector<int>>{
      vector<int>{2, 1, 1},
      vector<int>{0, 1, 1},
      vector<int>{1, 0, 1},
  };
  vector<vector<int>> tokens3 = vector<vector<int>>{vector<int>{0, 2}};
  cout << s.orangesRotting(tokens1) << endl;
  cout << s.orangesRotting(tokens2) << endl;
  cout << s.orangesRotting(tokens3) << endl;
}