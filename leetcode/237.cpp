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

// 混乱する
// よくわからんかった
class Solution {
 public:
  void deleteNode(ListNode *node) {
    // pointerのpointer
    *node = *node->next;
    return;
  }
};

int main() {
  Solution s = Solution();
  ListNode *node = new ListNode(1);
  node->next = new ListNode(2);
  node->next->next = new ListNode(3);
  node->next->next->next = new ListNode(4);
  node->next->next->next->next = new ListNode(5);

  ListNode *current = node;
  while (current != nullptr) {
    cout << current->val << ",";
    current = current->next;
  }
  cout << endl;

  current = node;
  s.deleteNode(current->next);
  while (current != nullptr) {
    cout << current->val << ",";
    current = current->next;
  }
  cout << endl;
}