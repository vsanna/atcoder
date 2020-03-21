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

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  vector<TreeNode *> allPossibleFBT(int N) {
    if (N % 2 == 0) {
      return vector<TreeNode *>();
    }

    vector<vector<TreeNode *>> dp =
        vector<vector<TreeNode *>>(N + 1, vector<TreeNode *>());
    return rec(dp, N);
  }

  vector<TreeNode *> rec(vector<vector<TreeNode *>> &dp, int N) {
    if (dp[N].size() != 0) {
      return dp[N];
    }

    vector<TreeNode *> result;

    if (N == 1) {
      TreeNode *root = new TreeNode(0);
      result.push_back(root);
      dp[N] = result;
      return dp[N];
    }

    for (int i = 1; i <= (N - 1) / 2; i += 2) {
      int j = (N - 1) - i;
      for (TreeNode *tree1 : rec(dp, i)) {
        for (TreeNode *tree2 : rec(dp, j)) {
          TreeNode *root = new TreeNode(0);
          root->left = tree1;
          root->right = tree2;
          result.push_back(root);
          if (i != j) {
            TreeNode *root2 = new TreeNode(0);
            root2->right = tree1;
            root2->left = tree2;
            result.push_back(root2);
          }
        }
      }
    }

    dp[N] = result;
    return dp[N];
  }
};

vector<int> treeToArray(TreeNode *root) {
  queue<TreeNode *> q;
  q.push(root);
  vector<int> result;
  while (q.size() > 0) {
    TreeNode *c = q.front();
    q.pop();
    result.push_back(c->val);
    if (c->val == NULL) {
      continue;
    }

    if (c->left != nullptr) {
      q.push(c->left);
    } else {
      q.push(new TreeNode(NULL));
    }
    if (c->right != nullptr) {
      q.push(c->right);
    } else {
      q.push(new TreeNode(NULL));
    }
  }

  return result;
}

int main() {
  Solution s = Solution();
  for (int i = 1; i <= 20; i++) {
    cout << s.allPossibleFBT(i).size() << ", ";
    // cout <<  << endl;
  }
}