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

  ll size() override { return data.size(); }

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

// BFS, DFS
// dijkstra
// ベルマンフォード
// わーシャルフロイド
// 最小全域木: クラスカル, プリム
// 最大フロー, 最小カット, 二部グラフの最大マッチ
// 強連結成分, 橋, 辺
// ハミルトン経路
// オイラー経路
// セールスマン順回路
// グラフ彩色
// A*
template <typename T>
class dijkstraResult {
 public:
  T to;
  ll distance;
  vector<T> path;
  dijkstraResult(T to, ll distance, vector<T> path) {
    this->to = to;
    this->distance = distance;
    this->path = path;
  }
  void traverse() {
    cout << "to: " << to << ", distance: " << distance << ", path: ";
    for (auto item : path) {
      cout << item;
      if (item != *path.end()) {
        cout << " <= ";
      }
    }
    cout << endl;
  }
};

template <typename T>
class GraphI {
  virtual void addNode(T val) = 0;
  virtual void addEdge(T from, T to, int weight = 1) = 0;
  virtual void removeNode(T val) = 0;
  virtual void removeEdge(T from, T to) = 0;
  virtual void bfs(T start) = 0;
  virtual void recursiveDfs(T start) = 0;
  virtual void iterativeDfs(T start) = 0;
  // virtual void dijkstra(T start) = 0;
  virtual ResultObject<map<T, dijkstraResult<T>*>> dijkstra(T start) = 0;
  virtual ResultObject<map<T, dijkstraResult<T>*>> bellmanFord(T start) = 0;
  // virtual void warshallFloyd() = 0;
  // virtual void shortestPath(T a, T b) = 0;
  // virtual void shortestPathsDijkstra(T from) = 0;
  // virtual void shortestPathsBellmanFord(T from) = 0;
  // virtual void shortestPathsWarshallFloyd() = 0;
};

// matrix: map<T, map<T, ll>>
// list/set: map<T, vector<pair<T, ll>>>

template <typename T>
class Edge {
 public:
  T from;
  T to;
  ll weight;
  Edge(T from, T to, ll weight) {
    this->from = from;
    this->to = to;
    this->weight = weight;
  }
};

template <typename T>
class Graph : GraphI<T> {
  using Edge = Edge<T>;

 public:
  map<T, vector<Edge*>> data;

  Graph() { data = map<T, vector<Edge*>>(); }

  void addNode(T val) override {
    if (data.count(val) == 0) {
      data[val] = vector<Edge*>();
    }
  }

  void addEdge(T from, T to, int weight) override {
    for (Edge* edge : data[from]) {
      if (edge->to == to) {
        edge->weight = weight;
        return;
      }
    }
    Edge* newEdge = new Edge(from, to, weight);
    data[from].push_back(newEdge);
  }

  void removeNode(T target) override {
    for (pair<T, vector<Edge*>> neighbors : data) {
      vector<Edge*> edges = neighbors.second;
      for (Edge* edge : edges) {
        if (edge->to == target) {
          auto itr = find(edges.begin(), edges.end(), edge);
          edges.erase(itr);
        }
      }
    }

    data.erase(target);
  }

  void removeEdge(T from, T to) override {
    auto edges = data[from];
    for (auto edge : edges) {
      if (edge->to == to) {
        auto itr = find(edges.begin(), edges.end(), edge);
        edges.erase(itr);
        return;
      }
    }
  }

  void bfs(T start) override {
    map<T, T> previous = map<T, T>();
    map<T, ll> distance = map<T, ll>();
    map<T, bool> visited = map<T, bool>();
    for (auto node : data) {
      visited[node.first] = false;
    }

    queue<T> remaining = queue<T>();
    remaining.push(start);

    while (remaining.size() > 0) {
      T current = remaining.front();
      remaining.pop();
      visited[current] = true;

      // for debug
      // cout << current << endl;

      for (Edge* edge : data[current]) {
        if (visited[edge->to]) continue;

        // for 1:1 shortest path
        // if(to == goal) break;

        // bfs doesn't need to check updatable
        distance[edge->to] = distance[current] + 1;
        previous[edge->to] = current;
        remaining.push(edge->to);
      }
    }
  }

  void iterativeDfs(T start) override {
    map<T, T> previous = map<T, T>();
    map<T, ll> distance = map<T, ll>();
    map<T, bool> visited = map<T, bool>();
    for (auto node : data) {
      visited[node.first] = false;
    }
    stack<T> remaining = stack<T>();
    remaining.push(start);

    while (remaining.size() > 0) {
      T current = remaining.top();
      remaining.pop();
      // for debug
      cout << current << endl;

      for (Edge* edge : data[current]) {
        if (visited[edge->to]) continue;

        // for 1:1 shortest path
        // if(to == goal) break;

        // bfs doesn't need to check updatable
        distance[edge->to] = distance[current] + 1;
        previous[edge->to] = current;
        remaining.push(edge->to);
      }
    }
  }

  void recursiveDfsHelper(T current, map<T, bool>& visited, map<T, T>& previous,
                          map<T, ll>& distance) {
    visited[current] = true;

    // for debug
    cout << current << endl;

    for (auto edge : data[current]) {
      if (!visited[edge->to]) {
        distance[edge->to] = distance[current] + 1;
        previous[edge->to] = current;
        recursiveDfsHelper(edge->to, visited, previous, distance);
      }
    }
  }

  void recursiveDfs(T start) override {
    map<T, T> previous = map<T, T>();
    map<T, ll> distance = map<T, ll>();
    map<T, bool> visited = map<T, bool>();
    for (auto node : data) {
      visited[node.first] = false;
    }
    recursiveDfsHelper(start, visited, previous, distance);
  }

  ResultObject<map<T, dijkstraResult<T>*>> dijkstra(T from) override {
    map<T, T> previous = map<T, T>();
    map<T, ll> distance = map<T, ll>();
    for (auto neighbors : data) {
      previous[neighbors.first] = NULL;
      distance[neighbors.first] = INF;
    }
    distance[from] = 0;

    map<T, bool> visited = map<T, bool>();
    for (auto node : data) {
      visited[node.first] = false;
    }

    // dijkstra uses updatable_priority_queue
    using Node = PriorityQueueNode<T>;
    using PriorityQueue = Heap<Node, int>;
    PriorityQueue remaining = PriorityQueue();
    Node fromNode = Node(from, distance[from]);
    remaining.add(fromNode);

    while (remaining.size() > 0) {
      Node current = remaining.pop();

      // 同一nodeが複数挿入されている場合は無視することでupdateを考えなくてすむ
      if (distance[current.val] < current.priority) continue;

      visited[current.val] = true;

      for (Edge* edge : data[current.val]) {
        if (visited[edge->to]) continue;

        // for 1:1 shortest path
        // if(to == goal) break;
        if (distance[edge->to] > distance[current.val] + edge->weight) {
          distance[edge->to] = distance[current.val] + edge->weight;
          previous[edge->to] = current.val;

          remaining.add(Node(edge->to, distance[edge->to]));
        }
      }
    }

    // for debug
    return ResultObject<map<T, dijkstraResult<T>*>>(
        buildShortestPathResult(distance, previous), false);
  }

  ResultObject<map<T, dijkstraResult<T>*>> bellmanFord(T from) override {
    map<T, T> previous = map<T, T>();
    map<T, ll> distance = map<T, ll>();
    for (auto neighboars : data) {
      distance[neighboars.first] = INF;
    }
    distance[from] = 0;

    ll index = 0;
    for (ll i = 0; i < data.size(); i++) {
      // V * E を回す
      for (auto nodeAndEdges : data) {
        for (Edge* edge : nodeAndEdges.second) {
          if (distance[edge->to] > distance[edge->from] + edge->weight) {
            distance[edge->to] = distance[edge->from] + edge->weight;
            previous[edge->to] = edge->from;

            // V回目のループでまだ更新できるようだったら負辺の閉路あり
            if (index == data.size() - 1) {
              return ResultObject<map<T, dijkstraResult<T>*>>(
                  buildShortestPathResult(), true);
            }
          }
        }
      }
      index++;
    }
    // for debug
    return ResultObject<map<T, dijkstraResult<T>*>>(
        buildShortestPathResult(distance, previous), false);
  }

  void traverse() {
    for (auto item : data) {
      cout << item.first << " => ";
      for (Edge* edge : item.second) {
        cout << edge->to << "(" << edge->weight << "),";
      }
      cout << endl;
    }
  }

  // TODO: いい方法ないか調べる
  map<T, dijkstraResult<T>*> buildShortestPathResult() {
    return map<T, dijkstraResult<T>*>();
  }

  map<T, dijkstraResult<T>*> buildShortestPathResult(map<T, ll>& distance,
                                                     map<T, T>& previous) {
    map<T, dijkstraResult<T>*> result = map<T, dijkstraResult<T>*>();
    for (auto nodeAndDistance : distance) {
      T to = nodeAndDistance.first;
      ll d = nodeAndDistance.second;
      vector<T> path = vector<T>();
      T current = to;
      while (current != NULL) {
        path.push_back(current);
        current = previous[current];
      }
      dijkstraResult<T>* resultForNode = new dijkstraResult<T>(to, d, path);
      result[to] = resultForNode;
    }
    return result;
  }
};

int main() {
  Graph<int> graph = Graph<int>();
  graph.addNode(1);
  graph.addNode(10);
  graph.addNode(3);
  graph.addNode(-4);
  graph.addNode(9);
  graph.addNode(12);
  graph.addNode(89);
  graph.addNode(33);
  graph.traverse();
  cout << "=========" << endl;
  graph.addEdge(1, 10, 1);
  graph.addEdge(1, -4, 3);
  graph.addEdge(10, -4, 10);
  graph.addEdge(10, 1, 1);  // change
  graph.addEdge(33, 89, 1);
  graph.addEdge(89, 33, 1);
  graph.addEdge(33, 12, 1);
  graph.traverse();

  cout << "=======" << endl;
  graph.bfs(33);
  cout << "==" << endl;
  graph.bfs(1);
  cout << "==" << endl;
  graph.bfs(3);
  cout << "==" << endl;
  graph.bfs(-4);
  cout << "==" << endl;
  graph.bfs(12);
  cout << "==" << endl;
  cout << "=======" << endl;
  graph.iterativeDfs(1);
  cout << "=======" << endl;
  graph.recursiveDfs(1);

  cout << "=======" << endl;
  ResultObject<map<int, dijkstraResult<int>*>> result = graph.dijkstra(10);
  if (result.err) return 0;
  for (auto item : result.result) {
    item.second->traverse();
  }

  // 不変あり
  Graph<int> graphWithNegativeEdge = Graph<int>();
  graphWithNegativeEdge.addNode(1);
  graphWithNegativeEdge.addNode(10);
  graphWithNegativeEdge.addNode(3);
  graphWithNegativeEdge.addNode(-4);
  graphWithNegativeEdge.addNode(9);
  graphWithNegativeEdge.addNode(12);
  graphWithNegativeEdge.addNode(89);
  graphWithNegativeEdge.addNode(33);
  graphWithNegativeEdge.traverse();
  cout << "=========" << endl;
  graphWithNegativeEdge.addEdge(1, 10, 1);
  graphWithNegativeEdge.addEdge(1, -4, -3);
  graphWithNegativeEdge.addEdge(10, -4, 10);
  graphWithNegativeEdge.addEdge(10, 1, 1);
  graphWithNegativeEdge.addEdge(33, 89, -1);
  graphWithNegativeEdge.addEdge(89, 33, 1);
  graphWithNegativeEdge.addEdge(33, 12, -1);
  ResultObject<map<int, dijkstraResult<int>*>> result2 =
      graphWithNegativeEdge.bellmanFord(10);
  if (result2.err) {
    cout << "has error" << endl;
    return 0;
  }
  for (auto item : result2.result) {
    item.second->traverse();
  }
}