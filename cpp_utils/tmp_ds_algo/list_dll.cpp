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
class DoublyLinkedListI {
  virtual DoublyLinkedListI* insert(T val, ll pos) = 0;
  virtual DoublyLinkedListI* remove(ll pos) = 0;
  virtual ll indexOf(T val) = 0;
  virtual T get(ll pos) = 0;
  virtual ll size() = 0;
};

template <typename T>
class DoublyLinkedList : DoublyLinkedListI<T> {
  using Node = DoublyLinkedList;

 public:
  Node* next = nullptr;
  Node* prev = nullptr;
  T val;

  DoublyLinkedList(T val) { this->val = val; };

  Node* insert(T val, ll pos) override {
    Node* newNode = new Node(val);

    if (pos == 0) {
      newNode->next = this;
      this->prev = newNode;
      return newNode;
    }

    Node* current = this;
    int currentIdx = 0;

    while (currentIdx < pos) {
      if (currentIdx + 1 == pos) {
        if (current->next != nullptr) {
          auto nextNode = current->next;
          nextNode->prev = newNode;
          newNode->next = nextNode;
        }
        current->next = newNode;
        newNode->prev = current;
      }
      current = this->next;
      currentIdx++;
    }
    return this;
  }

  Node* remove(ll pos) override {
    Node* current = this;
    int currentIdx = 0;
    if (pos == 0) {
      if (this->next != nullptr) {
        this->next = nullptr;
      }
      return this->next;
    }

    while (pos < currentIdx) {
      current = this->next;
      currentIdx++;
    }

    Node* prevNode = current->prev;
    Node* nextNode = current->next;
    if (prevNode != nullptr) {
      prevNode->next = current->next;
    }

    if (nextNode != nullptr) {
      nextNode->prev = current->prev;
    }

    return this;
  }

  ll indexOf(T val) override {
    Node* current = this;
    int currentIdx = 0;

    while (current->val != val) {
      if (current == nullptr) {
        throw - 1;  // not found
      }

      current = this->next;
      currentIdx++;
    }

    return currentIdx;
  }

  T get(ll pos) override {
    Node* current = this;
    int currentIdx = 0;

    while (currentIdx < pos) {
      if (current == nullptr) {
        throw range_error("pos is out of range");
      }
      current = this->next;
      currentIdx++;
    }

    return current->val;
  }

  ll size() override {
    if (this->next == nullptr) return 1;
    return 1 + this->next->size();
  }

  vector<T> traverse() {
    vector<T> result = vector<T>();
    Node* current = this;
    while (current != nullptr) {
      result.push_back(current->val);
      current = current->next;
    }
    return result;
  }
};

int main() {
  DoublyLinkedList<ll>* dll = new DoublyLinkedList<ll>(100l);
  dll = dll->insert(1, dll->size());
  dll = dll->insert(2, dll->size());
  dll = dll->insert(3, dll->size());
  dll = dll->insert(4, dll->size());
  dll = dll->insert(5, dll->size());
  dll = dll->insert(6, dll->size());
  for (auto item : dll->traverse()) {
    cout << item << endl;
  }
}