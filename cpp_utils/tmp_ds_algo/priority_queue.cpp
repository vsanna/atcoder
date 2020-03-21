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

// FROM HERE: heap/priority_queue ========================

template <typename T>
class PriorityQueueNode {
 public:
  ll priority;
  T val;

  PriorityQueueNode(T val, ll priority) {
    this->val = val;
    this->priority = priority;
  }

  bool operator<(const PriorityQueueNode& other) const {
    return this->priority < other.priority;
  }
  bool operator>(const PriorityQueueNode& other) const {
    return this->priority > other.priority;
  }
};

template <typename T>
ostream& operator<<(ostream& os, PriorityQueueNode<T>& node) {
  // ここでストリームに obj を書き込みます。
  os << "{priority: " << node.priority << ", val: " << node.val << " }" << endl;
  return os;
}

template <typename T>
class HeapI {
 public:
  virtual void add(T val) = 0;
  virtual void bubbleUp(ll startIdx) = 0;
  virtual T top() = 0;
  virtual T pop() = 0;
  virtual void sinkDown(ll startIdx) = 0;
  virtual vector<T> heapSort() = 0;
  virtual ll size() = 0;
};

template <typename T, typename S>
class Heap : HeapI<T> {
 public:
  vector<T> data;
  Heap() { this->data = vector<T>(); }

  ll size() override { return data.size(); }

  void add(T val) override {
    data.push_back(val);
    bubbleUp(this->data.size() - 1);
  }

  void bubbleUp(ll startingIdx) override {
    if (data.empty()) return;

    ll currentIdx = startingIdx;
    ll parentIdx = floor((currentIdx - 1) / 2.0f);
    while (parentIdx >= 0 && data[currentIdx] < data[parentIdx]) {
      swap(data[currentIdx], data[parentIdx]);
      currentIdx = parentIdx;
      parentIdx = floor((currentIdx - 1) / 2.0f);
    }
  }

  T pop() override {
    if (data.size() == 0) {
      throw runtime_error("data is empty.");
    }

    if (data.size() == 1) {
      T head = top();
      data.pop_back();
      return head;
    }

    T head = data.front();
    T tail = data.back();
    data.pop_back();
    data[0] = tail;
    sinkDown();

    return head;
  }

  void sinkDown(ll startingIdx = 0) override {
    ll currentIdx = startingIdx;
    ll leftChildIdx = currentIdx * 2 + 1;
    ll rightChildIdx = currentIdx * 2 + 2;

    while (
        (leftChildIdx < data.size() && data[currentIdx] > data[leftChildIdx]) ||
        (rightChildIdx < data.size() &&
         data[currentIdx] > data[rightChildIdx])) {
      ll minIdx = (rightChildIdx < data.size() &&
                   data[leftChildIdx] > data[rightChildIdx])
                      ? rightChildIdx
                      : leftChildIdx;
      swap(data[currentIdx], data[minIdx]);
      currentIdx = minIdx;
      leftChildIdx = currentIdx * 2 + 1;
      rightChildIdx = currentIdx * 2 + 2;
    }
  }

  void update(T oldVal, T newVal) {
    ll pos = findPos(oldVal);
    // TODO: how to express not_found
    if (pos == -1) return;

    data[pos] = newVal;
    sinkDown(pos);
    bubbleUp(pos);
  }

  // this method is only for PriorityQueue
  // TODO: move to other place
  void updateForPQ(S val, ll newPriority) {
    auto targetNode = find_if(this->data.begin(), this->data.end(),
                              [&val](T item) { return item.val == val; });
    if (targetNode == this->data.end()) {
      return;
    }

    targetNode->priority = newPriority;
    ll pos = findPosByNode(*targetNode);
    sinkDown(pos);
    bubbleUp(pos);
  }

  T top() override { return data.front(); }

  vector<T> heapSort() override {
    vector<T> result = vector<T>();
    while (data.size() > 0) {
      result.push_back(pop());
    }
    return result;
  }

 private:
  // TODO: how to express T<OTHER_T>
  ll findPos(const T& val, ll pos = 0) {
    if (data[pos] == val) return pos;
    if (pos >= data.size()) return -1;
    ll result = findPos(val, 2 * pos + 1);
    if (result == -1) {
      result = findPos(val, 2 * pos + 2);
    }
    return result;
  }

  ll findPosByNode(const T& node, ll pos = 0) {
    if (data[pos].val == node.val) return pos;
    if (pos >= data.size()) return -1;
    ll result = findPosByNode(node, 2 * pos + 1);
    if (result == -1) {
      result = findPosByNode(node, 2 * pos + 2);
    }
    return result;
  }
};

// TO HERE: heap/priority_queue ========================

int main() {
  using Node = PriorityQueueNode<int>;
  using PriorityQueue = Heap<Node, int>;

  /*
   * [(10, 1), (-3, 5), (1, 10), (21, 11), (-10, 12)]
   */
  PriorityQueue pq = PriorityQueue();
  Node node1 = Node(1, 10);
  Node node2 = Node(-3, 5);
  Node node3 = Node(10, 1);
  Node node4 = Node(21, 11);
  Node node5 = Node(-10, 12);
  pq.add(node1);
  pq.add(node2);
  pq.add(node3);
  pq.add(node4);
  pq.add(node5);

  for (auto node : pq.heapSort()) {
    cout << "val: " << node.val << " priority: " << node.priority << endl;
  }

  cout << "======" << endl;
  pq.add(node1);
  pq.add(node2);
  pq.add(node3);
  pq.add(node4);
  pq.add(node5);
  pq.updateForPQ(-3, 100);
  for (auto node : pq.heapSort()) {
    cout << "val: " << node.val << " priority: " << node.priority << endl;
  }

  Node node6 = Node(1, 10);
  Node node7 = Node(-3, 5);
  Node node8 = Node(10, 1);
  Node node9 = Node(21, 11);
  Node node10 = Node(-10, 12);

  cout << (node6 > node7 ? "true" : "false") << endl;
  cout << (node7 > node8 ? "true" : "false") << endl;
  cout << (node8 < node9 ? "true" : "false") << endl;
  cout << (node9 < node10 ? "true" : "false") << endl;
  cout << (node10 > node6 ? "true" : "false") << endl;
}