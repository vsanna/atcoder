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
class CircularLinkedListI {
  virtual CircularLinkedListI* unshift(T val) = 0;
  virtual CircularLinkedListI* push(T val) = 0;
  virtual CircularLinkedListI* shift() = 0;
  virtual CircularLinkedListI* pop() = 0;
  virtual vector<T> traverse() = 0;
};

template <typename T>
class CircularLinkedListNode : CircularLinkedListI<T> {
  using Node = CircularLinkedListNode;

 public:
  Node* next = nullptr;
  T val;

  CircularLinkedListNode(T val) {
    this->val = val;
    this->next = this;
  };

  // NOTE: not working
  // Node* tail() {
  //   Node* head = this;
  //   Node* current = this;
  //   while (current->next != head) {
  //     current = current->next;
  //   }
  //   return current;
  // }

  Node* unshift(T val) override {
    Node* newHead = new Node(val);
    newHead->next = this;
    Node* lastNode = this;
    while (lastNode->next != this) {
      lastNode = lastNode->next;
    }
    lastNode->next = newHead;

    return newHead;
  }

  Node* push(T val) override {
    Node* node = new Node(val);

    Node* lastNode = this;
    while (lastNode->next != this) {
      lastNode = lastNode->next;
    }

    lastNode->next = node;
    node->next = this;
    return this;
  }

  Node* shift() override {
    Node* lastNode = this;
    while (lastNode->next != this) {
      lastNode = lastNode->next;
    }
    if (lastNode == this) {
      return nullptr;
    }

    // TODO: free処理
    lastNode->next = this->next;
    return this->next;
  }

  Node* pop() override {
    Node* lastNode = this;
    while (lastNode->next != this) {
      lastNode = lastNode->next;
    }
    if (this == lastNode) {
      return nullptr;
    }
    Node* prev_of_last = this;
    while (prev_of_last->next != lastNode) {
      prev_of_last = prev_of_last->next;
    }
    prev_of_last->next = this;
    return this;
  }

  vector<T> traverse() override {
    vector<T> result = vector<T>();
    Node* lastNode = this;
    while (lastNode->next != this) {
      lastNode = lastNode->next;
    }
    Node* current = this;
    while (current != lastNode) {
      result.push_back(current->val);
      current = current->next;
    }
    return result;
  }
};

int main() {
  using LinkedList = CircularLinkedListNode<int>;
  LinkedList* head = new LinkedList(1);
  head->push(10);
  head->push(100);
  head->push(1000);
  head = head->unshift(0);
  head = head->unshift(-1);
  head = head->unshift(-10);
  head = head->unshift(-100);

  for (auto item : head->traverse()) {
    cout << "item: " << item << endl;
  }
}
