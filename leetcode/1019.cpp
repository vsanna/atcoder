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
void chmax(int& a, int b) {
  if (a < b) {
    a = b;
  }
}

class TreeNode {
 public:
  int val;
  TreeNode* left = nullptr;
  TreeNode* right = nullptr;
  TreeNode* parent = nullptr;
  TreeNode(int x) : val(x), left(NULL), right(NULL), parent(NULL) {}
};

// NOTE: misaligned error?
class TNode {
 public:
  int val;
  TNode* left = nullptr;
  TNode* right = nullptr;
  TNode* parent = nullptr;
  TNode(int x) : val(x), left(NULL), right(NULL), parent(NULL) {}
};

TNode* findMin(TNode* root) {
  if (root->left != nullptr) {
    return findMin(root->left);
  } else {
    return root;
  }
}

void insert(TNode* root, TNode* node) {
  TNode* current = root;
  while (true) {
    if (current->val == node->val) {
      node = current;
      return;
    }

    if (current->val < node->val) {
      if (current->right == nullptr) {
        current->right = node;
        node->parent = current;
        return;
      } else {
        current = current->right;
      }
    } else {
      if (current->left == nullptr) {
        current->left = node;
        node->parent = current;
        return;
      } else {
        current = current->left;
      }
    }
  }
}

TNode* next(TNode* start) {
  if (start->right != nullptr) {
    return findMin(start->right->left);
  }
  TNode* parent = start->parent;
  while (parent != nullptr && parent->val < start->val) {
    parent = parent->parent;
  }
  return parent;
}

class ListNode {
 public:
  int val;
  ListNode* next;
  ListNode(int val) { this->val = val; }
};

// NOTE: listのreverse
ListNode* reverseList(ListNode* node) {
  if (node->next == nullptr) {
    return node;
  }
  ListNode* prev = node;
  ListNode* current = node->next;
  ListNode* next = node->next->next;
  prev->next = nullptr;
  while (current != nullptr) {
    ListNode* tmp = prev;
    prev = current;
    current = next;
    if (next != nullptr) {
      next = next->next;
    }
    prev->next = tmp;
  }
  return prev;
}

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

class Solution {
 public:
  vector<int> nextLargerNodes(ListNode* head) { return solution2(head); }

  vector<int> solution2(ListNode* head) {
    vector<int> nextLarger;
    while (head != nullptr) {
      ListNode* next = head->next;
      bool found = false;
      while (next != nullptr) {
        if (head->val < next->val) {
          found = true;
          nextLarger.push_back(next->val);
          break;
        }
        next = next->next;
      }
      if (!found) {
        nextLarger.push_back(0);
      }
      head = head->next;
    }
    return nextLarger;
  }

  vector<int> solution1(ListNode* head) {
    vector<int> nextLarger;
    if (head == nullptr) {
      return nextLarger;
    }
    nextLarger.push_back(0);

    head = reverseList(head);

    TNode* root = new TNode(head->val);
    ListNode* current = head->next;
    while (current != nullptr) {
      TNode* node = new TNode(current->val);
      insert(root, node);
      TNode* nextnode = next(node);
      nextLarger.push_back((nextnode == nullptr ? 0 : nextnode->val));
      current = current->next;
    }
    reverse(nextLarger.begin(), nextLarger.end());

    return nextLarger;
  }
};

int main() {
  Solution s = Solution();

  ListNode* head = TreeGenerator::stringToListNode("[2,7,4,3,5]");
  for (auto n : s.nextLargerNodes(head)) {
    cout << n << ",";
  }
  cout << endl;

  head = TreeGenerator::stringToListNode("[1,7,5,1,9,2,5,1]");
  for (auto n : s.nextLargerNodes(head)) {
    cout << n << ",";
  }
  cout << endl;
}