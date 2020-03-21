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

void chmin(ll& a, ll b) {
  if (a > b) {
    a = b;
  }
}
void chmax(ll& a, ll b) {
  if (a < b) {
    a = b;
  }
}

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class ListNode {
 public:
  int val;
  ListNode* next;
  ListNode(int val) { this->val = val; }
};

class TreeGenerator {
 public:
  static void trimLeftTrailingSpaces(string& input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(),
                                       [](int ch) { return !isspace(ch); }));
  }

  static void trimRightTrailingSpaces(string& input) {
    input.erase(find_if(input.rbegin(), input.rend(),
                        [](int ch) { return !isspace(ch); })
                    .base(),
                input.end());
  }

  static TreeNode* stringToTreeNode(string input) {
    input = input.substr(1, input.length() - 2);
    if (!input.size()) {
      return nullptr;
    }

    string item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    TreeNode* root = new TreeNode(stoi(item));
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    while (true) {
      TreeNode* node = nodeQueue.front();
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

  static vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
      output.push_back(stoi(item));
    }
    return output;
  }

  static ListNode* stringToListNode(string input) {
    // Generate list from the input
    vector<int> list = stringToIntegerVector(input);

    // Now convert that list into linked list
    ListNode* dummyRoot = new ListNode(0);
    ListNode* ptr = dummyRoot;
    for (int item : list) {
      ptr->next = new ListNode(item);
      ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
  }

  static string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
      length = list.size();
    }

    if (length == 0) {
      return "[]";
    }

    string result;
    for (int index = 0; index < length; index++) {
      int number = list[index];
      result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
  }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    list<TreeNode*> path = list<TreeNode*>{};
    path.push_back(root);
    list<TreeNode*> pathToP = rec(root, p, path);
    path = list<TreeNode*>{};
    path.push_back(root);
    list<TreeNode*> pathToQ = rec(root, q, path);

    reverse(pathToP.begin(), pathToP.end());
    reverse(pathToQ.begin(), pathToQ.end());

    return findLCA(pathToP, pathToQ);
  }

  list<TreeNode*> rec(TreeNode* root, TreeNode* target, list<TreeNode*>& path) {
    if (root->val == target->val) {
      return path;
    }
    if (root->left != nullptr) {
      path.push_back(root->left);
      list<TreeNode*> result = rec(root->left, target, path);
      if (result.size() > 0) return result;
      path.pop_back();
    }
    if (root->right != nullptr) {
      path.push_back(root->right);
      list<TreeNode*> result = rec(root->right, target, path);
      if (result.size() > 0) return result;
      path.pop_back();
    }

    return list<TreeNode*>{};
  }

  TreeNode* findLCA(list<TreeNode*>& pathA, list<TreeNode*>& pathB) {
    int lenA = pathA.size();
    int lenB = pathB.size();
    if (lenA < lenB) {
      for (int i = 0; i < abs(lenA - lenB); i++) {
        pathB.pop_front();
      }
    } else if (lenA > lenB) {
      for (int i = 0; i < abs(lenA - lenB); i++) {
        pathA.pop_front();
      }
    }

    while (true) {
      if (pathA.front()->val == pathB.front()->val) {
        return pathA.front();
      }
      pathA.pop_front();
      pathB.pop_front();
    }
    return nullptr;
  }
};

int main() {
  Solution s = Solution();
  TreeNode* root =
      TreeGenerator::stringToTreeNode("[3,5,1,6,2,0,8,null,null,7,4]");
  TreeNode* p = new TreeNode(5);
  TreeNode* q = new TreeNode(1);
  cout << s.lowestCommonAncestor(root, p, q)->val << endl;
}