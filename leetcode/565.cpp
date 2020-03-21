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
void dumpvec(vector<T> vec) {
  for (T cnt : vec) {
    cout << cnt << ", ";
  }
  cout << endl;
}

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

int root(vector<int> &unionfind, int a) {
  if (unionfind[a] < 0) {
    return a;
  }
  int _root = root(unionfind, unionfind[a]);
  unionfind[a] = _root;
  return _root;
}

bool isConnected(vector<int> &unionfind, int a, int b) {
  return root(unionfind, a) == root(unionfind, b);
}

int size(vector<int> &unionfind, int a) {
  return -1 * unionfind[root(unionfind, a)];
}

void connect(vector<int> &unionfind, int a, int b) {
  int root_of_a = root(unionfind, a);
  int root_of_b = root(unionfind, b);

  // aがbを併合する
  unionfind[root_of_a] += unionfind[root_of_b];
  unionfind[root_of_b] = root_of_a;
}

class Solution {
 public:
  int arrayNesting(vector<int> &nums) {
    vector<int> unionfind(nums.size(), -1);
    for (int i = 0; i < nums.size(); i++) {
      // まだ通ってない
      if (size(unionfind, i) == 1) {
        int pos = i;
        while (true) {
          dump(pos);
          dumpvec(unionfind);
          if (isConnected(unionfind, pos, nums[pos])) {
            break;
          } else {
            connect(unionfind, pos, nums[pos]);
            pos = nums[pos];
          }
        }
      }
    }

    ll ans = -INF;
    for (int i = 0; i < nums.size(); i++) {
      chmax(ans, size(unionfind, i));
    }

    return ans;
  }
  // MLE
  // int arrayNesting(vector<int> &nums) {
  //   vector<vector<int>> dp =
  //       vector<vector<int>>(nums.size(), vector<int>(nums.size(), 0));
  //   ll ans = -INF;
  //   for (int i = 0; i < nums.size(); i++) {
  //     int current = i;
  //     int len = 0;
  //     while (true) {
  //       cout << "i:" << i << ", current: " << current << ", len: " << len
  //            << endl;
  //       if (dp[current][i] > 0) {
  //         chmax(ans, len + dp[current][i] - 1);
  //         break;
  //       } else {
  //         if (dp[i][current] > 0) {
  //           chmax(ans, len);
  //           break;
  //         }
  //         len++;
  //         dp[i][current] = len;
  //         current = nums[current];
  //       }
  //     }
  //     cout << "ans: " << ans << endl;
  //   }
  //   return ans;
  // }

  // TLE
  // int arrayNesting(vector<int> &nums) {
  //   // idx, <len, idx-len>
  //   map<int, pair<int, map<int, int>>> dp =
  //       map<int, pair<int, map<int, int>>>();

  //   for (int i = 0; i < nums.size(); i++) {
  //     pair<int, map<int, int>> result;
  //     map<int, int> newDistances;
  //     newDistances[i] = 1;

  //     if (dp.count(nums[i])) {
  //       pair<int, map<int, int>> lenAndDistances = dp[nums[i]];
  //       int len = lenAndDistances.first;
  //       map<int, int> distances = lenAndDistances.second;

  //       for (auto kv : distances) {
  //         if (kv.first == i || distances[i] < distances[kv.first]) continue;
  //         newDistances[kv.first] = kv.second + 1;
  //       }

  //       if (distances[i] > 0) {
  //         result = make_pair(distances[i], newDistances);
  //       } else {
  //         result = make_pair(len + 1, newDistances);
  //       }
  //     } else {
  //       // cout << "i:" << i << endl;
  //       int len = 1;
  //       int current = i;
  //       while (true) {
  //         current = nums[current];
  //         // cout << "current:" << current << endl;
  //         if (newDistances.count(current) > 0) break;
  //         len++;
  //         newDistances[current] = len;
  //       }
  //       result = make_pair(len, newDistances);
  //     }

  //     dp[i] = result;
  //   }

  //   // for (auto kv : dp) {
  //   //   cout << kv.first << "(" << kv.second.first << ") => ";
  //   //   for (auto kv2 : kv.second.second) {
  //   //     cout << kv2.first << "(" << kv2.second << ")";
  //   //   }
  //   //   cout << endl;
  //   // }

  //   ll maxlen = -INF;
  //   for (auto kv : dp) {
  //     chmax(maxlen, kv.second.first);
  //   }
  //   return maxlen;
  // }
};

int main() {
  Solution s = Solution();
  vector<int> nums1 = vector<int>{5, 4, 0, 3, 1, 6, 2};
  cout << s.arrayNesting(nums1) << endl;
  nums1 = vector<int>{7, 6, 5, 4, 3, 2, 1, 0};
  cout << s.arrayNesting(nums1) << endl;
  nums1 = vector<int>{0, 1, 2, 3, 4, 5, 6, 7};
  cout << s.arrayNesting(nums1) << endl;
  nums1 = vector<int>{1, 2, 3, 4, 5, 6, 7, 0};
  cout << s.arrayNesting(nums1) << endl;
}