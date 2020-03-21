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
  vector<int> postorderTraversal(TreeNode *root) {
    vector<int> result = vector<int>();
    dfs(root, result);
    return result;
  }

  // recursive
  void dfs(TreeNode *current, vector<int> &result) {
    dfs(current->left, result);
    dfs(current->right, result);
    result.push_back(current->val);
  }

  TreeNode *arrayToTree(vector<int> values) {
    if (values.size() == 0) {
      return nullptr;
    }

    TreeNode *root = new TreeNode(values[0]);
    queue<TreeNode *> q = queue<TreeNode *>();
    q.push(root);
    int currentIdx = 1;

    if (values.size() == 1) {
      return root;
    }

    while (q.size() > 0 && currentIdx < values.size()) {
      TreeNode *current = q.front();
      q.pop();
      cout << "currentIdx: " << currentIdx << endl;

      if (currentIdx < values.size() && values[currentIdx] != NULL) {
        cout << "idx: " << currentIdx << " is added as children" << endl;
        current->left = new TreeNode(values[currentIdx]);
        q.push(current->left);
      }
      if (currentIdx + 1 < values.size() && values[currentIdx + 1] != NULL) {
        cout << "idx: " << currentIdx + 1 << " is added as children" << endl;
        current->right = new TreeNode(values[currentIdx + 1]);
        q.push(current->right);
      }

      currentIdx += 2;
    }

    return root;
  }

  void arrayToTreeHelper(const vector<int> &values, const int idx,
                         TreeNode *node) {
    cout << "----" << endl;
    cout << "idx: " << idx << ", val: " << node->val << endl;
    node->val = values[idx];
    cout << values[2 * idx + 1] << endl;
    cout << values[2 * idx + 2] << endl;
    cout << "(2 * idx + 1) < values.size() && values[2 * idx + 1] != NULL : "
         << ((2 * idx + 1) < values.size() && values[2 * idx + 1] != NULL)
         << endl;
    cout << "(2 * idx + 2) < values.size() && values[2 * idx + 2] != NULL : "
         << ((2 * idx + 2) < values.size() && values[2 * idx + 2] != NULL)
         << endl;

    if ((2 * idx + 1) < values.size() && values[2 * idx + 1] != NULL) {
      node->left = new TreeNode(NULL);
      cout << "2*idx+1: " << (2 * idx + 1) << endl;
      arrayToTreeHelper(values, 2 * idx + 1, node->left);
    }
    if ((2 * idx + 2) < values.size() && values[2 * idx + 2] != NULL) {
      node->right = new TreeNode(NULL);
      cout << "2*idx+2: " << (2 * idx + 2) << endl;
      arrayToTreeHelper(values, 2 * idx + 2, node->right);
    }
  }
};

int main() {
  Solution s = Solution();
  vector<int> values = vector<int>{1, NULL, 2, 3};
  TreeNode *root = s.arrayToTree(values);

  vector<int> postorderTraversal = s.postorderTraversal(root);
}