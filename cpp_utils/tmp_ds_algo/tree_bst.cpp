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
const ll INF = numeric_limits<ll>::max();
const int MOD = 1000000007;

template <typename T>
class BinarySearchTreeNode {
 public:
  T val;
  BinarySearchTreeNode<T>* left = nullptr;
  BinarySearchTreeNode<T>* right = nullptr;

  BinarySearchTreeNode(T& v) { this->val = v; }
};

template <typename T>
class BinarySearchTreeI {
  using Node = BinarySearchTreeNode<T>;

 public:
  virtual void add(T val) = 0;
  virtual void remove(T val) = 0;
  virtual Node* find(T val) = 0;
  virtual Node* findMin(Node* start) = 0;
  // virtual Node* findMax() = 0;
  virtual Node* findKthMin() = 0;
  virtual vector<T> bfs(Node* start) = 0;
  virtual vector<T> recursiveDfsInorder(Node* start) = 0;
  // virtual vector<T> dfsPreorder() = 0;
  // virtual vector<T> dfsPostorder() = 0;
  // virtual int height() = 0;
  // LCA
  // diameter
  virtual Node* parentOf(Node* target) = 0;
  virtual Node* nextOf(Node* target) = 0;
  // ancesstors
  //
};

template <typename T>
class BinarySearchTree : BinarySearchTreeI<T> {
  using Node = BinarySearchTreeNode<T>;

  Node* root = nullptr;

 public:
  BinarySearchTree(){};

  void add(T val) override {
    Node* node = new Node(val);  // NOTE: ポインタ変数の初期化はnew使う

    if (this->root == nullptr) {
      this->root = node;
      return;
    }

    Node* current = this->root;
    while (true) {
      if (val < current->val) {
        if (current->left == nullptr) {
          current->left = node;
          break;
        } else {
          current = current->left;
          continue;
        }
      } else {
        if (current->right == nullptr) {
          current->right = node;
          break;
        } else {
          current = current->right;
          continue;
        }
      }
    }

    return;
  }

  void remove(T val) override {
    Node* targetNode = find(val);
    Node* parentNode = parentOf(targetNode);

    // 1. no child
    if (targetNode->left == nullptr && targetNode->right == nullptr) {
      if (targetNode == this->root) {
        this->root = nullptr;
      }
      if (parentNode->left == targetNode) {
        parentNode->left = nullptr;
      }
      if (parentNode->right == targetNode) {
        parentNode->right = nullptr;
      }
      return;
    }

    // 1. has one side child
    if ((targetNode->left != nullptr && targetNode->right == nullptr) ||
        (targetNode->left == nullptr && targetNode->right != nullptr)) {
      Node* childNode =
          targetNode->left == nullptr ? targetNode->right : targetNode->left;
      if (targetNode == this->root) {
        this->root = childNode;
        return;
      }
      if (parentNode->left == targetNode) {
        parentNode->left = childNode;
      }
      if (parentNode->right == targetNode) {
        parentNode->right = childNode;
      }
      return;
    }

    // 3. has both side children
    // TODO: findMinがlogic固定的
    Node* nextNode = findMin(targetNode->right);
    T tmp = nextNode->val;
    remove(tmp);
    targetNode->val = tmp;
  }

  Node* find(T val) override {
    Node* current = this->root;
    while (current) {
      if (val < current->val) {
        current = current->left;
      } else if (val > current->val) {
        current = current->right;
      } else {
        return current;
      }
    }
  }

  // bfs is only iterative with queue
  vector<T> bfs(Node* start) override {
    if (start == nullptr) {
      start = this->root;
    }

    vector<T> result = vector<T>();
    queue<Node*> remainings = queue<Node*>();
    remainings.push(start);

    while (!remainings.empty()) {
      Node* current = remainings.front();
      remainings.pop();
      if (current->left != nullptr) {
        remainings.push(current->left);
      }
      if (current->right != nullptr) {
        remainings.push(current->right);
      }
      result.push_back(current->val);
    }

    return result;
  }

  vector<T> iterativeDfsInorder(Node* start) {
    vector<T> result = vector<T>();

    if (start == nullptr) {
      if (root == nullptr) {
        return result;
      }
      start = root;
    }

    stack<Node*> remainings = stack<Node*>();
    remainings.push_back(start);

    while (!remainings.empty()) {
      Node* current = remainings.top();
      remainings.pop();
      if (current->left != nullptr) {
        remainings.push(current->left);
      }
      if (current->right != nullptr) {
        remainings.push(current->right);
      }
      result.push_back(current->val);
    }

    return result;
  }

  // dfs is iterative with stack || recursive
  void recursiveDfsInorderHelper(Node* current, vector<T>& results) {
    if (current->left != nullptr) {
      recursiveDfsInorderHelper(current->left, results);
    }
    results.push_back(current->val);
    if (current->right != nullptr) {
      recursiveDfsInorderHelper(current->right, results);
    }
  }

  vector<T> recursiveDfsInorder(Node* start) override {
    vector<T> results = vector<T>();
    if (start == nullptr) {
      start = this->root;
    }

    recursiveDfsInorderHelper(start, results);

    return results;
  }

  Node* findKthMin() override { int count = 0; }

  Node* parentOf(Node* target) override {
    if (target == nullptr) {
      return nullptr;
    }

    if (target == this->root) {
      return nullptr;
    }

    Node* current = this->root;
    while (current) {
      if (current->left == target || current->right == target) {
        return current;
      }
      if (target->val < current->val) {
        if (current->left == nullptr) {
          return nullptr;
        }
        current = current->left;
        continue;
      }
      if (target->val > current->val) {
        if (current->right == nullptr) {
          return nullptr;
        }
        current = current->right;
        continue;
      }
    }
  }

  Node* nextOf(Node* target) override {
    if (target->right == nullptr) {
      return this->parentOf(target);
    }

    return this->findMin(target->right);
  }

  Node* findMin(Node* start) override {
    Node* current = start;
    while (current->left) {
      current = current->left;
    }
    return current;
  }
};

int main() {
  BinarySearchTree<int> bts = BinarySearchTree<int>();
  bts.add(100);
  bts.add(210);
  bts.add(90);
  bts.add(130);
  bts.add(120);
  bts.add(170);
  bts.add(180);
  bts.add(140);
  cout << "====" << endl;
  auto result = bts.bfs(nullptr);
  for (auto item : result) {
    cout << item << endl;
  }
  cout << "=========" << endl;
  result = bts.recursiveDfsInorder(nullptr);
  for (auto item : result) {
    cout << item << endl;
  }

  cout << "=========" << endl;
  result = bts.recursiveDfsInorder(nullptr);
  for (auto item : result) {
    cout << item << endl;
  }

  cout << "=========" << endl;
  bts.remove(90);
  bts.remove(100);
  bts.remove(180);
  result = bts.recursiveDfsInorder(nullptr);
  for (auto item : result) {
    cout << item << endl;
  }
}