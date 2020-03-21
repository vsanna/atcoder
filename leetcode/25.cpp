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

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode *parent;
  TreeNode(int x) : val(x), left(NULL), right(NULL), parent(NULL) {}
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

class Solution {
 public:
  ListNode *reverseKGroup(ListNode *head, int k) {
    if (k == 1) {
      return head;
    }

    ListNode *ans = nullptr;

    ListNode *initialHead = head;
    ListNode *initialTail = nullptr;
    ListNode *prevTail = nullptr;
    ListNode *nextHead = nullptr;
    ListNode *tail = nullptr;

    while (initialHead != nullptr) {
      // prepare
      tail = initialHead;
      for (int i = 1; i < k; i++) {
        if (tail->next == nullptr) {
          if (prevTail != nullptr) {
            prevTail->next = initialHead;
          }
          goto end;
        }
        tail = tail->next;
      }
      initialTail = tail;
      nextHead = initialTail->next;

      // reverse([head,tail])
      pair<ListNode *, ListNode *> result = reverse(initialHead, initialTail);

      if (prevTail != nullptr) {
        prevTail->next = result.first;
      }
      if (ans == nullptr) {
        ans = result.first;
      }

      // next loop
      initialHead = nextHead;
      prevTail = result.second;

      if (initialHead == nullptr) {
        prevTail->next = nullptr;
        break;
      }
    }

  end:
    if (ans == nullptr) {
      ans = head;
    }
    return ans;
  }

  pair<ListNode *, ListNode *> reverse(ListNode *head, ListNode *tail) {
    if (head == tail) {
      return make_pair(tail, head);
    }
    if (head->next == tail) {
      tail->next = head;
      return make_pair(tail, head);
    }
    ListNode *prev = head;
    ListNode *current = head->next;
    ListNode *next = head->next->next;
    while (current != tail) {
      current->next = prev;
      prev = current;
      current = next;
      next = next->next;
    }
    current->next = prev;

    return make_pair(tail, head);
  }
};

int main() {
  Solution s = Solution();
  for (int i = 1; i <= 9; i++) {
    ListNode *base = TreeGenerator::stringToListNode("[1,2,3,4,5,6,7,8,9]");
    ListNode *head = s.reverseKGroup(base, i);
    while (head != nullptr) {
      cout << head->val << ",";
      head = head->next;
    }
    cout << endl;
  }
}