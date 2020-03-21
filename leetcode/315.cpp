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
void dumpvec(vector<T> vec) {
  for (T cnt : vec) {
    cout << cnt << ", ";
  }
  cout << endl;
}

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

vector<string> split(string s, string delimiter) {
  int first = 0;
  int last = s.find_first_of(delimiter);
  vector<string> result;

  while (first < s.size()) {
    string sub = s.substr(first, last - first);
    result.push_back(sub);
    first = last + 1;
    last = s.find_first_of(delimiter, first);

    if (last == string::npos) {
      last = s.size();
    }
  }

  return result;
}

string join(vector<string> strings, string delimiter) {
  string result = "";
  for (int i = 0; i < strings.size(); i++) {
    if (result != "") result += delimiter;
    result += strings[i];
  }
  return result;
}

class TNode {
 public:
  TNode *left;
  TNode *right;
  int val;
  vector<int> pos;
  TNode(int val)
      : left(nullptr), right(nullptr), val(val), pos(vector<int>{}) {}
};

void insert(TNode *root, int val, int pos) {
  if (root == nullptr) {
    return;
  }
  if (root->val == val) {
    root->pos.push_back(pos);
    sort(root->pos.begin(), root->pos.end());
    return;
  }
  if (root->val < val) {
    if (root->right != nullptr) {
      insert(root->right, val, pos);
    } else {
      root->right = new TNode(val);
      root->right->pos.push_back(pos);
    }
  } else {
    if (root->left != nullptr) {
      insert(root->left, val, pos);
    } else {
      root->left = new TNode(val);
      root->left->pos.push_back(pos);
    }
  }
}

TNode *findMax(TNode *root) {
  if (root->right == nullptr) {
    return root;
  }
  return findMax(root->right);
}
TNode *findMin(TNode *root) {
  if (root->left == nullptr) {
    return root;
  }
  return findMax(root->left);
}

TNode *findLessThan(TNode *root, int val) {
  if (root == nullptr) {
    return nullptr;
  }
  if (root->val == val) {
    if (root->left == nullptr) {
      return nullptr;
    }
    return findMax(root->left);
  }
  if (root->val < val) {
    // root->val < valの場合、rootが候補の可能性がある
    if (root->right != nullptr) {
      TNode *result = findLessThan(root->right, val);
      if (result == nullptr) {
        return root;
      } else {
        return result;
      }
    } else {
      // rightなければrootがvalを超えない最大値
      return root;
    }
  } else {
    // root->val > valの場合rootより右は一切使えない
    if (root->left != nullptr) {
      return findLessThan(root->left, val);
    } else {
      // leftなければvalを下回る要素なし
      return nullptr;
    }
  }
}

class Solution {
 public:
  vector<int> countSmaller(vector<int> &nums) {
    vector<int> ans;
    ans.resize(nums.size());

    if (nums.size() == 0) {
      return ans;
    } else if (nums.size() == 1) {
      ans[nums.size() - 1] = 0;
      return ans;
    }

    TNode *root = new TNode(nums[nums.size() - 1]);
    root->pos.push_back(nums.size() - 1);
    ans[nums.size() - 1] = 0;

    for (int i = nums.size() - 2; i >= 0; i--) {
      int num = nums[i];
      // 1. num「未満」の値が直近登場したposを求める.
      TNode *target = findLessThan(root, num);
      if (target == nullptr) {
        // 2-1. 自分未満がなければ0で更新
        ans[i] = 0;
      } else {
        cout << "i = " << i;
        cout << ", target->val = " << target->val;
        cout << ", target->pos[0] = " << target->pos[0] << endl;
        // int pos = target->pos[target->pos.size() - 1];
        int pos = target->pos[0];
        // 2-2. ansを更新

        int additional = 0;
        for (int j = i + 1; j <= pos; j++) {
          if (nums[j] < nums[i]) additional++;
        }
        ans[i] = ans[pos] + additional + target->pos.size() - 1;
      }
      // 3. insert
      insert(root, nums[i], i);
    }

    return ans;
  }
};

int main() {
  Solution s{};
  vector<int> nums{5, 2, 6, 1};
  // dumpvec(s.countSmaller(nums));
  // nums = vector<int>{1,2,3,4,5};
  // dumpvec(s.countSmaller(nums));
  // nums = vector<int>{5,4,3,2,1};
  // dumpvec(s.countSmaller(nums));
  // nums = vector<int>{0,0,0,0,0};
  // dumpvec(s.countSmaller(nums));

  // wrong answer
  // nums = vector<int>{1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4};
  nums = vector<int>{1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 2, 4};
  dumpvec(s.countSmaller(nums));
  // nums = vector<int>{4,3,2,1,4,3,2,1,4,3,2,1,4,3,2,1};
  // dumpvec(s.countSmaller(nums));
}