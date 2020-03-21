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
class SingleLinkedListI {
  virtual SingleLinkedListI* insert(T val, ll pos) = 0;
  virtual SingleLinkedListI* remove(ll pos) = 0;
  virtual ll indexOf(T val) = 0;
  virtual T get(ll pos) = 0;
  virtual ll size() = 0;
  virtual T reGet(ll pos) = 0;
  virtual bool isCircle() = 0;
  virtual ll circleLength() = 0;
  virtual SingleLinkedListI* connectedNode() = 0;
  // 逆順にして返す
  virtual SingleLinkedListI* reverse() = 0;
  // 2つのSLLの合流点を返す
  // virtual SingleLinkedListI* mergedNode(SingleLinkedListI<T>* otherHead) = 0;
  // 中央を返す
  virtual SingleLinkedListI* centerNode() = 0;
  // 先頭からvectorにつめて返す
  virtual vector<T> traverse() = 0;
  virtual vector<T> retraverse() = 0;
  virtual bool isPalindrome() = 0;
};

template <typename T>
class SingleLinkedListNode : SingleLinkedListI<T> {
  using Node = SingleLinkedListNode;

 public:
  Node* next = nullptr;
  T val;

  SingleLinkedListNode(T val) { this->val = val; };

  // return head
  Node* insert(T val, ll pos) override {
    Node* node = new Node(val);

    if (pos == 0) {
      node->next = this;
      return node;
    }

    Node* current = this;
    Node* next = this->next;
    ll currentPos = 0;
    while (current) {
      if (currentPos + 1 == pos) {
        node->next = current->next;
        current->next = node;
        return this;
      }
      current = next;
      next = current->next;
      currentPos++;
    }

    throw out_of_range("pos is over than len");
  }

  Node* remove(ll pos) override {
    if (pos == 0) {
      Node* newHead = this->next;
      this->next = nullptr;
      return newHead;
    }

    Node* current = this;
    Node* next = this->next;
    ll currentPos = 0;

    while (next) {
      if (currentPos + 1 == pos) {
        current->next = next->next;
        return this;
      }
      current = next;
      next = next->next;
      currentPos++;
    }

    throw out_of_range("pos is over than len");
  }

  ll indexOf(T val) override {
    Node* current = this;
    ll currentPos = 0l;
    while (current) {
      if (val == current->val) {
        return currentPos;
      }
      currentPos++;
      current = current->next;
    }
  }

  T get(ll pos) override {
    Node* current = this;
    ll currentPos = 0;
    while (current) {
      if (pos == currentPos) {
        return current->val;
      }
      current = current->next;
      currentPos++;
    }
  }

  Node* getNode(ll pos) {
    Node* current = this;
    ll currentPos = 0;
    while (current) {
      if (pos == currentPos) {
        return current;
      }
      current = current->next;
      currentPos++;
    }
  }

  // 0 1 2 3 4 5: 後ろから1 = 4 = size() - 1 - k
  T reGet(ll pos) override {
    // if isCircle() return null;
    ll len = size();
    return get(len - 1 - pos);
  }

  ll size() override {
    // if isCircle() return null;
    if (this->next == nullptr) return 1;
    return this->next->size() + 1;
  }

  bool isCircle() override {
    if (this->next == nullptr || this->next->next == nullptr) {
      return false;
    }

    Node* fastPtr = this->next->next;
    Node* slowPtr = this->next;

    while (true) {
      if (fastPtr->next == nullptr || fastPtr->next->next == nullptr) {
        break;
      }

      if (fastPtr == slowPtr) return true;

      fastPtr = fastPtr->next->next;
      slowPtr = slowPtr->next;
    }

    return false;
  }

  ll circleLength() override {
    if (this->next == nullptr || this->next->next == nullptr) {
      return -1;
    }

    Node* fastPtr = this->next->next;
    Node* slowPtr = this->next;
    bool isCircle = false;

    while (true) {
      if (fastPtr->next == nullptr || fastPtr->next->next == nullptr) {
        isCircle = false;
        break;
      }

      if (fastPtr == slowPtr) {
        isCircle = true;
        break;
      }

      fastPtr = fastPtr->next->next;
      slowPtr = slowPtr->next;
    }

    if (isCircle) {
      fastPtr = fastPtr->next->next;
      slowPtr = slowPtr->next;
      ll len = 1;
      while (true) {
        if (fastPtr == slowPtr) break;
        len++;
        fastPtr = fastPtr->next->next;
        slowPtr = slowPtr->next;
      }
      return len;
    } else {
      return -1;
    }
  }

  Node* connectedNode() override {
    if (this->next == nullptr || this->next->next == nullptr) {
      return nullptr;
    }

    Node* fastPtr = this->next->next;
    Node* slowPtr = this->next;
    bool isCircle = false;

    while (true) {
      if (fastPtr->next == nullptr || fastPtr->next->next == nullptr) {
        isCircle = false;
        break;
      }

      if (fastPtr == slowPtr) {
        isCircle = true;
        break;
      }

      fastPtr = fastPtr->next->next;
      slowPtr = slowPtr->next;
    }

    if (isCircle) {
      fastPtr = this;
      while (true) {
        if (fastPtr == slowPtr) break;
        fastPtr = fastPtr->next;
        slowPtr = slowPtr->next;
      }
      return fastPtr;
    } else {
      return nullptr;
    }
  }

  Node* mergedNode(Node* otherHead) {
    ll size1 = this->size();
    ll size2 = otherHead->size();

    Node* headA = this;
    Node* headB = otherHead;
    if (size1 > size2) {
      for (ll i = 0; i < size1 - size2; i++) {
        headA = headA->next;
      }
    } else {
      for (ll i = 0; i < size2 - size1; i++) {
        headB = headB->next;
      }
    }
    while (headA->val != headB->val && (headA != nullptr && headB != nullptr)) {
      cout << "headA: " << headA->val << ", headB: " << headB->val << endl;
      headA = headA->next;
      headB = headB->next;
    }
    return headA;
  }

  // 奇数の場合は中央、偶数の場合は後半の先頭を返す
  Node* centerNode() override {
    Node* first = this;
    Node* second = this->next;
    while (second != nullptr) {
      first = first->next;
      if (second->next == nullptr || second->next->next == nullptr) {
        break;
      }
      second = second->next->next;
    }
    return first;
  }

  vector<T> traverse() override {
    vector<T> result = vector<T>();
    Node* current = this;
    while (current) {
      result.push_back(current->val);
      current = current->next;
    }

    return result;
  }

  vector<T> retraverse() override {
    Node* newHead = this->reverse();
    return newHead->traverse();
  }

  // newHead
  Node* reverse() override {
    pair<Node*, Node*> result = reverse(this);
    result.first->next = nullptr;
    return result.second;
  }

  // prev, newHead
  pair<Node*, Node*> reverse(Node* current) {
    if (current->next == nullptr || current->next == NULL) {
      Node* newHead = new Node(current->val);
      return make_pair(newHead, newHead);
    }
    pair<Node*, Node*> result = reverse(current->next);
    Node* newNode = new Node(current->val);
    result.first->next = newNode;
    return make_pair(newNode, result.second);
  }

  bool isPalindrome() override {
    auto traversal_result = this->traverse();
    auto retraversal_result = this->retraverse();
    ll len = this->size();
    for (ll i = 0; i < this->size() / 2; i++) {
      if (traversal_result[i] != retraversal_result[i]) return false;
    }
    return true;
  }
};

class ListNode {
 public:
  int val;
  ListNode* next;
  ListNode(int val) { this->val = val; }
};

// 追加スペースなしのreverse
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

int main() {
  auto head = SingleLinkedListNode<int>(1);

  // 1 -> 2 -> 5 -> -1 -> 10 -> 100
  head.insert(2, 1);
  head.insert(-1, 2);
  head.insert(10, 3);
  head.insert(5, 2);
  head.insert(100, 5);
  for (auto item : head.traverse()) {
    cout << item << " > ";
  }
  cout << endl;

  // virtual ll index(T val) = 0;
  // virtual T get(ll pos) = 0;
  // virtual ll size() = 0;
  // virtual T reGet(ll pos) = 0;

  cout << "indexOf: " << head.indexOf(1) << endl;
  cout << "indexOf: " << head.indexOf(2) << endl;
  cout << "indexOf: " << head.indexOf(5) << endl;
  cout << "indexOf: " << head.indexOf(-1) << endl;
  cout << "indexOf: " << head.indexOf(10) << endl;
  cout << "indexOf: " << head.indexOf(100) << endl;

  cout << "reGet: " << head.reGet(0) << endl;
  cout << "reGet: " << head.reGet(1) << endl;
  cout << "reGet: " << head.reGet(2) << endl;
  cout << "reGet: " << head.reGet(3) << endl;
  cout << "reGet: " << head.reGet(4) << endl;
  cout << "reGet: " << head.reGet(5) << endl;

  cout << "get: " << head.get(0) << endl;
  cout << "get: " << head.get(1) << endl;
  cout << "get: " << head.get(2) << endl;
  cout << "get: " << head.get(3) << endl;
  cout << "get: " << head.get(4) << endl;
  cout << "get: " << head.get(5) << endl;

  cout << "size: " << head.size() << endl;

  cout << "isCircle: " << (head.isCircle() ? "true" : "false") << endl;
  SingleLinkedListNode<int>* lastNode = head.getNode(head.size() - 1);
  SingleLinkedListNode<int>* connectedNode = head.getNode(3);
  lastNode->next = connectedNode;
  cout << "isCircle: " << (head.isCircle() ? "true" : "false") << endl;
  cout << "circleLength: " << head.circleLength() << endl;
  cout << "connectedNode: " << head.connectedNode()->val << endl;

  auto head2 = SingleLinkedListNode<int>(1);
  head2.insert(2, 1);
  head2.insert(3, 2);
  head2.insert(4, 3);
  head2.insert(5, 4);
  head2.insert(6, 5);
  head2.reverse();
  cout << "get: " << head2.get(0) << endl;
  cout << "get: " << head2.get(1) << endl;
  cout << "get: " << head2.get(2) << endl;
  cout << "get: " << head2.get(3) << endl;

  cout << "size:" << head2.retraverse().size() << endl;
  for (auto item : head2.retraverse()) {
    cout << "item" << item << " ";
  }
  cout << endl;

  auto listA = SingleLinkedListNode<int>(1);
  // 1 -> 2 -> 5 -> -1 -> 10 -> 100
  listA.insert(2, 1);
  listA.insert(-1, 2);
  listA.insert(10, 3);
  listA.insert(5, 2);
  listA.insert(100, 5);

  auto listB = SingleLinkedListNode<int>(3);
  // 3 -> 11 -> -10-> 50 -> -1 -> 10 -> 100
  listB.insert(11, 1);
  listB.insert(-10, 2);
  listB.insert(50, 3);
  listB.insert(-1, 4);
  listB.insert(10, 5);
  listB.insert(100, 6);

  cout << "merged: " << listA.mergedNode(&listB)->val << endl;

  auto listC = SingleLinkedListNode<int>(1);
  listC.insert(2, 1);
  listC.insert(3, 2);
  listC.insert(4, 3);
  listC.insert(3, 4);
  listC.insert(2, 5);
  listC.insert(1, 6);
  cout << (listC.isPalindrome() ? "YES" : "NO") << endl;
}
