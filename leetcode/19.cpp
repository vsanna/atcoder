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

class ListNode {
 public:
  int val;
  ListNode *next;
  ListNode(int val) { this->val = val; }
};

class Solution {
 public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode *first = head;
    ListNode *second = head;

    int len = listlen(head);

    if (len <= 1) {
      return nullptr;
    }

    if (n == len) {
      return head->next;
    }

    if (n == 1) {
      if (first->next->next == nullptr) {
        head->next = nullptr;
        return head;
      } else {
        while (first->next->next != nullptr) {
          first = first->next;
        }
        first->next = nullptr;
        return head;
      }
    }

    for (int i = 0; i < n; i++) {
      if (second->next != nullptr) {
        second = second->next;
      } else {
        while (first->next != second) {
          first = first->next;
        }
        first->next = nullptr;
        return head;
      }
    }

    while (second->next != nullptr) {
      first = first->next;
      second = second->next;
    }

    first->next = first->next->next;

    return head;
  }

  int listlen(ListNode *head) {
    if (head == nullptr) return 0;
    return listlen(head->next) + 1;
  }
};

int main() { Solution s = Solution(); }