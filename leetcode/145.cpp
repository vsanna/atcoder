#include <algorithm>
#include <bitset>
#include <cmath>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
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

class TreeGenerator {
 public:
  static void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(),
                                       [](int ch) { return !isspace(ch); }));
  }

  static void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(),
                        [](int ch) { return !isspace(ch); })
                    .base(),
                input.end());
  }

  static TreeNode *stringToTreeNode(string input) {
    input = input.substr(1, input.length() - 2);
    if (!input.size()) {
      return nullptr;
    }

    string item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    TreeNode *root = new TreeNode(stoi(item));
    queue<TreeNode *> nodeQueue;
    nodeQueue.push(root);

    while (true) {
      TreeNode *node = nodeQueue.front();
      nodeQueue.pop();

      if (!getline(ss, item, ',')) {
        break;
      }

      trimLeftTrailingSpaces(item);
      if (item != "null") {
        int leftNumber = stoi(item);
        node->left = new TreeNode(leftNumber);
        nodeQueue.push(node->left);
      }

      if (!getline(ss, item, ',')) {
        break;
      }

      trimLeftTrailingSpaces(item);
      if (item != "null") {
        int rightNumber = stoi(item);
        node->right = new TreeNode(rightNumber);
        nodeQueue.push(node->right);
      }
    }
    return root;
  }
};

class Solution {
 public:
  vector<int> postorderTraversal(TreeNode *root) {
    vector<int> result = vector<int>();
    if (root == NULL) {
      return result;
    }

    // dfs(root, result);
    iterativeDfsPostOrder(root, result);
    return result;
  }

  // recursive
  void dfs(TreeNode *current, vector<int> &result) {
    if (current->left != NULL) dfs(current->left, result);
    if (current->right != NULL) dfs(current->right, result);
    result.push_back(current->val);
  }

  // iterative: 表示用stackを持つ
  void iterativeDfsPostOrder(TreeNode *root, vector<int> &result) {
    stack<TreeNode *> visited = stack<TreeNode *>();
    stack<TreeNode *> s = stack<TreeNode *>();
    s.push(root);

    while (s.size()) {
      TreeNode *current = s.top();
      s.pop();
      visited.push(current);

      if (current->right != NULL) s.push(current->right);
      if (current->left != NULL) s.push(current->left);

      // has no children
      if (current->left == NULL && current->right == NULL) {
        // has next node
        if (s.size()) {
          TreeNode *nextNode = s.top();
          while (true) {
            if (visited.size() == 0) {
              break;
            }
            // postOrderは分岐点ノードをpopせずに終わる
            if (visited.top()->right != NULL &&
                visited.top()->right == nextNode) {
              break;
            }

            result.push_back(visited.top()->val);
            visited.pop();
          }
        }
      }
    }
    while (visited.size()) {
      result.push_back(visited.top()->val);
      visited.pop();
    }
  }

  void iterativeDfsInOrder(TreeNode *root, vector<int> &result) {
    stack<TreeNode *> visited = stack<TreeNode *>();
    stack<TreeNode *> s = stack<TreeNode *>();
    s.push(root);

    while (s.size()) {
      TreeNode *current = s.top();
      s.pop();
      visited.push(current);

      if (current->left != NULL) s.push(current->left);
      if (current->right != NULL) s.push(current->right);

      // has no children
      if (current->left == NULL && current->right == NULL) {
        // has next node
        if (s.size()) {
          TreeNode *nextNode = s.top();
          while (true) {
            if (visited.size() == 0) {
              break;
            }

            result.push_back(visited.top()->val);
            visited.pop();

            if (visited.top()->right != NULL &&
                visited.top()->right == nextNode) {
              break;
            }
          }
        }
      }
    }
    while (visited.size()) {
      result.push_back(visited.top()->val);
      visited.pop();
    }
  }

  // preorderは簡単
  void iterativeDfsPreOrder(TreeNode *root, vector<int> &result) {
    stack<TreeNode *> s = stack<TreeNode *>();
    s.push(root);

    while (s.size()) {
      TreeNode *current = s.top();
      s.pop();

      result.push_back(current->val);
      if (current->left != NULL) s.push(current->left);
      if (current->right != NULL) s.push(current->right);
    }
  }
};

int main() {
  Solution s = Solution();
  // vector<int> values = vector<int>{1, NULL, 2, 3};
  string input = "[1,null,2,3]";
  TreeNode *root = TreeGenerator::stringToTreeNode(input);

  vector<int> postorderTraversal = s.postorderTraversal(root);

  for (int n : postorderTraversal) {
    cout << n << ",";
  }
  cout << endl;
}