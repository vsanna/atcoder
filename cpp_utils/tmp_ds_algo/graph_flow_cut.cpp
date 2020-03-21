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

// BFS, DFS
// dijkstra
// ベルマンフォード
// わーシャルフロイド
// 強連結成分, 橋, 辺
// ハミルトン経路
// オイラー経路
// セールスマン順回路
// グラフ彩色
// A*

// 最小全域木: クラスカル, プリム

// 最大フロー, 最小カット, 二部グラフの最大マッチ

template <typename T>
class GraphI {
  virtual void addNode(T val) = 0;
  virtual void addEdge(T from, T to, int weight = 1) = 0;
  virtual void removeNode(T val) = 0;
  virtual void removeEdge(T from, T to) = 0;
  virtual void bfs(T start) = 0;
  virtual void recursiveDfs(T start) = 0;
  virtual void iterativeDfs(T start) = 0;
  // virtual void shortestPath(T a, T b) = 0;
  // virtual void shortestPathsDijkstra(T from) = 0;
  // virtual void shortestPathsBellmanFord(T from) = 0;
  // virtual void shortestPathsWarshallFloyd() = 0;
};

// matrix: map<T, map<T, ll>>
// list/set: map<T, vector<pair<T, ll>>>
template <typename T>
class Graph : GraphI<T> {
 public:
  map<T, vector<pair<T, ll>>> data;
  Graph() { data = map<T, vector<pair<T, ll>>>(); }

  void addNode(T val) override {
    if (data.count(val) == 0) {
      data[val] = vector<pair<T, ll>>();
    }
  }

  void addEdge(T from, T to, int weight) override {
    auto neighbors = data[from];
    for (auto neighbor : neighbors) {
      if (neighbor.first == to) {
        neighbor.second = weight;
        return;
      }
    }
    auto newNeighbor = pair<T, ll>(to, weight);
    data[from].push_back(newNeighbor);
  }

  void removeNode(T val) override {
    for (auto neighbors : data) {
      for (auto neighbor : neighbors.second) {
        if (neighbor.first == val) {
          auto itr =
              find(neighbors.second.begin(), neighbors.second.end(), neighbor);
          neighbors.second.erase(itr);
        }
      }
    }

    data.erase(val);
  }

  void removeEdge(T from, T to) override {
    auto neighbors = data[from];
    for (auto neighbor : neighbors) {
      if (neighbor.first == to) {
        auto itr = find(neighbors.begin(), neighbors.end(), neighbor);
        neighbors.erase(itr);
        return;
      }
    }
  }

  void bfs(T start) override {
    queue<T> remainings = queue<T>();
    remainings.push(start);
    map<T, bool> visited = map<T, bool>();
    for (auto neighbors : data) {
      visited[neighbors.first] = false;
    }

    while (!remainings.empty()) {
      T current = remainings.front();
      remainings.pop();
      visited[current] = true;
      for (auto neighbor : data[current]) {
        if (!visited[neighbor.first]) {
          remainings.push(neighbor.first);
        }
      }
      cout << current << endl;
    }
  }

  void iterativeDfs(T start) override {
    stack<T> remainings = stack<T>();
    remainings.push(start);
    map<T, bool> visited = map<T, bool>();
    for (auto neighbors : data) {
      visited[neighbors.first] = false;
    }

    while (!remainings.empty()) {
      T current = remainings.top();
      remainings.pop();
      visited[current] = true;
      for (auto neighbor : data[current]) {
        if (!visited[neighbor.first]) {
          remainings.push(neighbor.first);
        }
      }
      cout << current << endl;
    }
  }

  void recursiveDfsHelper(T current, map<T, bool>& visited) {
    visited[current] = true;
    for (auto neighbor : data[current]) {
      if (!visited[neighbor.first]) {
        recursiveDfsHelper(neighbor.first, visited);
      }
    }
    cout << current << endl;
  }

  void recursiveDfs(T start) override {
    map<T, bool> visited = map<T, bool>();
    for (auto neighbors : data) {
      visited[neighbors.first] = false;
    }
    recursiveDfsHelper(start, visited);
  }

  void traverse() {
    for (auto neighbors : data) {
      cout << neighbors.first << " => ";
      for (auto neighbor : neighbors.second) {
        cout << neighbor.first << "(" << neighbor.second << "),";
      }
      cout << endl;
    }
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
  graph.addEdge(1, -4, 1);
  graph.addEdge(33, 89, 1);
  graph.addEdge(89, 33, 1);
  graph.addEdge(33, 12, 1);
  graph.traverse();

  cout << "=======" << endl;
  graph.bfs(33);
  cout << "=======" << endl;
  graph.iterativeDfs(1);
  cout << "=======" << endl;
  graph.recursiveDfs(1);
}