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
  TreeNode *parent;
  TreeNode(int x) : val(x), left(NULL), right(NULL), parent(NULL) {}
};

class ListNode {
 public:
  int val;
  ListNode *next;
  ListNode(int val) { this->val = val; }
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

  static ListNode *stringToListNode(string input) {
    // Generate list from the input
    vector<int> list = stringToIntegerVector(input);

    // Now convert that list into linked list
    ListNode *dummyRoot = new ListNode(0);
    ListNode *ptr = dummyRoot;
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

void dfs(TreeNode *node) {
  if (node == nullptr) {
    cout << "null" << endl;
    return;
  }
  cout << node->val << endl;
  dfs(node->left);
  dfs(node->right);
}

int main() {
  string input = "[3,1,2]";
  TreeNode *root = TreeGenerator::stringToTreeNode(input);
  dfs(root);
}