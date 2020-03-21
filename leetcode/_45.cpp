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
  int jump(vector<int> &nums) {}
  // NOTE: numsのlengthに関する言及がないのでGraph使うと死ぬ...
  int jumpGraph(vector<int> &nums) {
    vector<vector<int>> graph = vector<vector<int>>(nums.size(), vector<int>{});
    for (int i = 0; i < nums.size(); i++) {
      int maxJ = min(max(i, (int)(nums.size() - 1 - i)), nums[i]);
      for (int j = 1; j <= maxJ; j++) {
        if (i - j >= 0) {
          graph[i].push_back(i - j);
        }
        if (i + j < nums.size()) {
          graph[i].push_back(i + j);
        }
      }
    }

    // for (int i = 0; i < graph.size(); i++) {
    //   cout << i << " -> [";
    //   for (int j = 0; j < graph[i].size(); j++) {
    //     cout << graph[i][j] << ",";
    //   }
    //   cout << "]" << endl;
    // }

    // bfs
    int goal = nums.size() - 1;
    vector<int> distances = vector<int>(nums.size(), IINF);
    distances[0] = 0;
    vector<bool> visited = vector<bool>(nums.size(), false);
    // prevは不要
    queue<int> queue;
    queue.push(0);
    while (queue.size() > 0) {
      int current = queue.front();
      queue.pop();

      // cout << "current: " << current
      //      << ", distanto to here: " << distances[current] << endl;

      if (current == goal) {
        return distances[goal];
      }

      visited[current] = true;

      for (int neighboar : graph[current]) {
        if (visited[neighboar]) {
          continue;
        }
        // cout << neighboar << ":" << distances[neighboar] << ":"
        //      << distances[current] + 1 << endl;
        if (distances[neighboar] >= distances[current] + 1) {
          distances[neighboar] = distances[current] + 1;
          queue.push(neighboar);
        }
      }
    }

    return -1;
  }
};

/*
[2,3,1,1,4]
0 -> [1,2]
1 -> [0,2,3,4]
2 -> [1,3]
3 -> [2,4]
4 -> [0,1,2,3]

// no greedy
[2,100000000000,1,1,1,1,1,1,1,4]

*/
int main() {
  Solution s = Solution();
  vector<int> nums1 = vector<int>{2, 3, 1, 1, 4};
  vector<int> nums2 = vector<int>{0};
  vector<int> nums3 = vector<int>{2, 3, 1, 1, 4};
  cout << s.jump(nums1) << endl;
}