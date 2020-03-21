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

// NOTE: 木の対象.
class Solution {
 public:
  bool isSymmetric(TreeNode *root) {
    if (root == nullptr) {
      return true;
    }
    return symetric(root->left, root->right);
  }

  bool symetric(TreeNode *left, TreeNode *right) {
    if (left == nullptr && right == nullptr) {
      return true;
    }
    if (left == nullptr || right == nullptr) {
      return false;
    }

    return (left->val == right->val) && symetric(left->left, right->right) &&
           symetric(left->right, right->left);
  }
};
int main() {}