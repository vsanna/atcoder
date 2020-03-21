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

// 典型的なBFS. recだとstackoverflow言いやがる
//
class Solution {
 public:
  vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc,
                                int newColor) {
    // rec(image, sr, sc, image[sr][sc], newColor);
    iter(image, sr, sc, image[sr][sc], newColor);
    return image;
  }

  void iter(vector<vector<int>> &image, int sr, int sc, int originalColor,
            int newColor) {
    if (originalColor == newColor) {
      return;
    }

    queue<pair<int, int>> queue;
    queue.push(make_pair(sr, sc));

    while (queue.size() > 0) {
      pair<int, int> current = queue.front();
      queue.pop();
      int i = current.first;
      int j = current.second;

      image[i][j] = newColor;

      for (pair<int, int> next : vector<pair<int, int>>{
               make_pair(i - 1, j),
               make_pair(i + 1, j),
               make_pair(i, j + 1),
               make_pair(i, j - 1),
           }) {
        int nexti = next.first;
        int nextj = next.second;
        if (nexti >= 0 && nexti < image.size() && nextj >= 0 &&
            nextj < image[0].size()) {
          if (image[nexti][nextj] == originalColor) {
            queue.push(make_pair(nexti, nextj));
          }
        }
      }
    }
  }

  void rec(vector<vector<int>> &image, int i, int j, int originalColor,
           int newColor) {
    image[i][j] = newColor;

    for (pair<int, int> next : vector<pair<int, int>>{
             make_pair(i - 1, j),
             make_pair(i + 1, j),
             make_pair(i, j + 1),
             make_pair(i, j - 1),
         }) {
      int nexti = next.first;
      int nextj = next.second;
      if (nexti >= 0 && nexti < image.size() && nextj >= 0 &&
          nextj < image[0].size()) {
        if (image[nexti][nextj] == originalColor) {
          rec(image, nexti, nextj, originalColor, newColor);
        }
      }
    }
  };
};

int main() {
  Solution s = Solution();
  vector<vector<int>> image = vector<vector<int>>{
      vector<int>{1, 1, 1},
      vector<int>{1, 1, 0},
      vector<int>{1, 0, 1},
  };
  image = vector<vector<int>>{
      vector<int>{0, 0, 0},
      vector<int>{0, 1, 1},
  };
  for (auto row : s.floodFill(image, 1, 1, 1)) {
    for (auto n : row) {
      cout << n << ",";
    }
    cout << endl;
  }
}