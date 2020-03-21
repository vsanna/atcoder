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
  int widthOfBinaryTree(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }

    ll maxWidth = -INF;
    ll currentWidth = 0;
    ll nullWidth = 0;
    queue<TreeNode *> que;
    TreeNode *separator = new TreeNode(-1);
    TreeNode *nullnode = new TreeNode(-1);
    que.push(root);
    que.push(separator);

    while (que.size() > 0) {
      TreeNode *current = que.front();
      que.pop();

      if (current == separator) {
        // cout << endl;
        // cout << "currentwidth: " << currentWidth << endl;
        chmax(maxWidth, currentWidth);
        if (currentWidth == 0) {
          return maxWidth;
        }
        currentWidth = 0;
        nullWidth = 0;
        que.push(separator);
        continue;
      }

      if (current == nullnode) {
        // cout << "N,";
        nullWidth++;
      } else {
        // cout << current->val << ",";
        currentWidth += (nullWidth + 1);
        nullWidth = 0;
      }

      if (current->left != nullptr) {
        que.push(current->left);
      } else {
        if (que.back() != separator) {
          que.push(nullnode);
        }
      }

      if (current->right != nullptr) {
        que.push(current->right);
      } else {
        if (que.back() != separator) {
          que.push(nullnode);
        }
      }
    }

    return -1;
  }
};

int main() {
  Solution s = Solution();
  TreeNode *root1 = TreeGenerator::stringToTreeNode("[5,3,null,9]");
  TreeNode *root2 = TreeGenerator::stringToTreeNode("[1,3,2,5,3,null,9]");
  TreeNode *root3 = TreeGenerator::stringToTreeNode(
      "[0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,"
      "0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,null,0,"
      "null,0,null,0,0]");
  cout << s.widthOfBinaryTree(root1) << endl;
  cout << s.widthOfBinaryTree(root3) << endl;
}