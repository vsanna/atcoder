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
  // 分割統治
  int largestRectangleArea(vector<int> &heights) {
    if (heights.size() == 0) {
      return 0;
    }

    return rec(heights, 0, heights.size() - 1);
  }

  int rec(vector<int> &heights, int low, int high) {
    if (low == high) {
      return heights[low];
    }
    if (low > high) {
      return 0;
    }

    int mid = (low + high) / 2;

    ll leftans = rec(heights, low, mid - 1);
    ll rightans = rec(heights, mid + 1, high);

    vector<int> mountain = vector<int>(high - (low - 1), 0);
    for (int i = mid; i >= low; i--) {
      if (i == mid) {
        mountain[i - low] = heights[mid];
      } else {
        mountain[i - low] = (mountain[i - low + 1] > heights[i])
                                ? heights[i]
                                : mountain[i - low + 1];
      }
    }
    for (int i = mid + 1; i <= high; i++) {
      mountain[i - low] = (heights[i] < mountain[i - low - 1])
                              ? heights[i]
                              : mountain[i - low - 1];
    }

    int i = 0;
    int j = mountain.size() - 1;
    ll centerarea = 0;

    // TODO: 閾値判定が先! しかしこれが通るのがg++なのか...
    // while (mountain[i] == 0 && i < mountain.size()) {
    while (i < mountain.size() && mountain[i] == 0) {
      i++;
    }
    while (j >= 0 && mountain[j] == 0) {
      j--;
    }
    while (i <= j && i >= 0 && i < mountain.size() && j >= 0 &&
           j < mountain.size()) {
      // cout << "i:" << i << ", j:" << j << endl;
      // for (int n : mountain) {
      //   cout << n << ",";
      // }
      // cout << endl;

      chmax(centerarea, (j - (i - 1)) * min(mountain[i], mountain[j]));
      if (mountain[i] < mountain[j]) {
        int currentval = mountain[i];
        while (currentval == mountain[i] && i < mountain.size()) {
          i++;
        }
      } else if (mountain[i] > mountain[j]) {
        int currentval = mountain[j];
        while (currentval == mountain[j] && j >= 0) {
          j--;
        }
      } else {
        i++;
      }
    }

    // dump(low);
    // dump(high);
    // dump(mid);
    // cout << "left ans:" << leftans << endl;
    // cout << "center ans:" << centerarea << endl;
    // cout << "right ans:" << rightans << endl;

    ll ans = 0;
    chmax(ans, leftans);
    chmax(ans, rightans);
    chmax(ans, centerarea);

    return ans;
  }

  // N**2 MLE
  // int largestRectangleArea(vector<int> &heights) {
  //   if (heights.size() == 0) {
  //     return 0;
  //   }
  //   vector<vector<int>> minheight =
  //       vector<vector<int>>(heights.size(), vector<int>(heights.size(), 0));
  //   for (int i = 0; i < heights.size(); i++) {
  //     for (int j = i; j < heights.size(); j++) {
  //       if (i == j) {
  //         minheight[i][j] = heights[i];
  //       } else {
  //         minheight[i][j] =
  //             (minheight[i][j - 1] > heights[j] ? heights[j]
  //                                               : minheight[i][j - 1]);
  //       }
  //     }
  //   }

  //   ll maxarea = -INF;
  //   vector<vector<int>> area =
  //       vector<vector<int>>(heights.size(), vector<int>(heights.size(), 0));
  //   for (int i = 0; i < heights.size(); i++) {
  //     for (int j = i; j < heights.size(); j++) {
  //       area[i][j] = (j - (i - 1)) * minheight[i][j];
  //       chmax(maxarea, area[i][j]);
  //     }
  //   }

  //   return maxarea;
  // }
};

int main() {
  Solution s = Solution();

  vector<int> heights{2, 1, 5, 6, 2, 3};
  // cout << s.largestRectangleArea(heights) << endl;
  // heights = vector<int>{0, 0, 0, 0, 0, 0};
  // cout << s.largestRectangleArea(heights) << endl;
  // heights = vector<int>{0};
  heights = vector<int>{0, 0};
  cout << s.largestRectangleArea(heights) << endl;
  // heights = vector<int>{4};
  // cout << s.largestRectangleArea(heights) << endl;
  // heights = vector<int>{5, 4, 3, 2, 1};
  // cout << s.largestRectangleArea(heights) << endl;
  // heights = vector<int>{1, 2, 3, 4, 5};
  // cout << s.largestRectangleArea(heights) << endl;
  // heights = vector<int>{1, 2, 3, 4, 5, 4, 3, 2, 1};
  // cout << s.largestRectangleArea(heights) << endl;
}