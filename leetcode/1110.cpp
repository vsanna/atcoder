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
void chmax(int &a, int b) {
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
  vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete) {
    vector<TreeNode *> roots;
    sort(to_delete.begin(), to_delete.end());
    roots.push_back(root);
    rec(roots, to_delete, root, NULL);
    return roots;
  }

  /*
  bool binary_search(itr, itr, val)
  itr find(itr, itr, val)
  */
  void rec(vector<TreeNode *> &roots, vector<int> &to_delete, TreeNode *current,
           TreeNode *parent) {
    if (current == nullptr) {
      return;
    }

    if (binary_search(to_delete.begin(), to_delete.end(), current->val)) {
      auto itr = find(roots.begin(), roots.end(), current);
      if (itr != roots.end()) {
        roots.erase(itr);
      }
      if (current->left != nullptr) {
        roots.push_back(current->left);
      }
      if (current->right != nullptr) {
        roots.push_back(current->right);
      }

      if (parent != nullptr) {
        if (parent->left == current) {
          parent->left = nullptr;
        } else {
          parent->right = nullptr;
        }
      }
    }

    rec(roots, to_delete, current->left, current);
    rec(roots, to_delete, current->right, current);
  }
};

int main() {
  Solution s = Solution();
  TreeNode *root = TreeGenerator::stringToTreeNode("[1,2,3,4,5,6,7]");
  vector<int> to_delete = vector<int>{3, 5};
  vector<TreeNode *> roots = s.delNodes(root, to_delete);
  for (auto node : roots) {
    cout << node->val << ", ";
  }
  cout << endl;
}