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

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
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
  bool isSubPath(ListNode* head, TreeNode* root) {
    vector<pair<TreeNode*, stack<TreeNode*>>> ends{};

    ListNode* target = head;
    while (target->next != NULL) {
      target = target->next;
    }

    stack<TreeNode*> path;
    path.push(root);
    if (root->val == target->val) {
      ends.push_back(make_pair(root, path));
    }

    rec(root, target, path, ends);

    ListNode* revlist = reverse(head);

    // while (revlist) {
    //   dump(revlist->val);
    //   revlist = revlist->next;
    // }

    for (pair<TreeNode*, stack<TreeNode*>> endcandidate : ends) {
      stack<TreeNode*> path = endcandidate.second;
      ListNode* head = revlist;
      while (head != nullptr && path.size() > 0) {
        TreeNode* tn = path.top();
        path.pop();
        // dump(head->val);
        // dump(tn->val);

        if (head->val == tn->val) {
          head = head->next;
          continue;
        } else {
          break;
        }
      }
      if (head == nullptr) {
        return true;
      }
    }

    return false;
  }

  void rec(TreeNode* current, ListNode* target, stack<TreeNode*>& path,
           vector<pair<TreeNode*, stack<TreeNode*>>>& ends) {
    if (target->val == current->val) {
      ends.push_back(make_pair(current, path));
    }

    if (current->left != nullptr) {
      path.push(current->left);
      rec(current->left, target, path, ends);
      path.pop();
    }
    if (current->right != nullptr) {
      path.push(current->right);
      rec(current->right, target, path, ends);
      path.pop();
    }
  }

  ListNode* reverse(ListNode* head) {
    ListNode* prev = head;
    ListNode* current = head->next;
    if (current == nullptr) {
      return head;
    }

    ListNode* next = current->next;
    if (next == nullptr) {
      prev->next = nullptr;
      current->next = prev;
      return current;
    }

    prev->next = nullptr;

    while (current != nullptr) {
      current->next = prev;
      prev = current;
      current = next;
      next = (next != NULL) ? next->next : NULL;
    }

    return prev;
  }
};

int main() {
  Solution s = Solution();
  TreeNode* root = TreeGenerator::stringToTreeNode(
      "[1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]");
  for (ListNode* list : vector<ListNode*>{
           //  TreeGenerator::stringToListNode("[4,2,8]"),
           //  TreeGenerator::stringToListNode("[4,2,6]"),
           //  TreeGenerator::stringToListNode("[4,2,4]"),
           //  TreeGenerator::stringToListNode("[1,4,2,6]"),
           TreeGenerator::stringToListNode("[1,4,2,1]"),
           TreeGenerator::stringToListNode("[1,4,4,1]"),
           TreeGenerator::stringToListNode("[1,4,1,1]"),
           TreeGenerator::stringToListNode("[8,1]"),
           TreeGenerator::stringToListNode("[8,9]"),
           TreeGenerator::stringToListNode("[8,3]"),
           TreeGenerator::stringToListNode("[4,2,8]"),
       }) {
    dump(list);
    cout << s.isSubPath(list, root) << endl;
  }
}