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
  vector<int> flipMatchVoyage(TreeNode *root, vector<int> &voyage) {}

  vector<int> rec(TreeNode *current, vector<TreeNode *> &flipped,
                  int currentIdx, vector<int> &voyage) {
    if (voyage[currentIdx + 1] != current->left->val) {
      TreeNode *tmp = currernt->left;
      current->left = current->right;
      current->right = tmp;
      flipped.push_back(current);
      if (voyage[currentIdx + 1] != current->left->val) {
        return vector<int>{-1};
      }
    }
  }
};
int main() {
  string input = "[3,1,2]";
  TreeNode *root = TreeGenerator::stringToTreeNode(input);
  vector<int> voyage = vector<int>{1, 2, 3};

  cout << s.flipMatchVoyage(root, voyage).size() << endl;
}