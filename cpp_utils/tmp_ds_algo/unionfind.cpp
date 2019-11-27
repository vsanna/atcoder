#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <cmath>
#include <utility>
#include <bitset>
#include <queue>
#include <stack>
#include <limits>
#include <list>

using namespace std;
using ll = long long;
const ll INF = numeric_limits<ll>::max();
const int MOD = 1000000007;

template <typename T>
class UnionFindI {
public:
    virtual T root(T val) = 0;
    virtual bool isConnected(T a, T b) = 0;
    virtual void connect(T a, T b) = 0;
    virtual ll size(T a) = 0;
};

template <typename T>
class UnionFind : UnionFindI<T> {
public:
    vector<T> nodes;
    map<T, ll> parents;
    UnionFind(vector<T> nodes): nodes(nodes) {
        this->nodes = vector<T>(nodes);
        this->parents = map<T, ll>();
        for(auto node: nodes) {
            parents[node] = -1; // negative means isParent == true
        }
    };

    T root(T node) override {
        // assuming node is included in nodes
        ll parentIndex = parents[node];
        if (parentIndex < 0) {
            return node;
        } else {
            return root(nodes[parentIndex]);
        }
    }

    ll size(T node) override {
        T rootNode = root(node);
        return parents[rootNode] * -1;
    }

    bool isConnected(T a, T b) override {
        T root_a = root(a);
        T root_b = root(b);
        return root_a == root_b;
    }

    void connect(T a, T b) override {
        if (isConnected(a, b)) return;

        T root_a = root(a);
        T root_b = root(b);

        // make root_a bigger union
        if (size(root_a) < size(root_b)) {
            swap(root_a, root_b);
        }

        auto indexOfRootA = nodeIndex(root_a);

        parents[root_a] += parents[root_b];
        parents[root_b] = indexOfRootA;
    }

    void traverse() {
        cout << parents << endl;
    }

    ll nodeIndex(T node) {
        auto itr = find(nodes.begin(), nodes.end(), node);
        return distance(nodes.begin(), itr);
    }
};

int main() {
    vector<string> nodes = vector<string>();
    nodes.push_back("a");
    nodes.push_back("b");
    nodes.push_back("c");
    nodes.push_back("d");
    nodes.push_back("e");
    nodes.push_back("f");
    nodes.push_back("g");
    nodes.push_back("h");
    UnionFind<string> uf = UnionFind<string>(nodes);

    cout << (uf.isConnected("a", "b") ? "connected" : "not connected") << endl;
    cout << (uf.isConnected("b", "c") ? "connected" : "not connected") << endl;
    cout << (uf.isConnected("c", "d") ? "connected" : "not connected") << endl;
    cout << (uf.isConnected("d", "e") ? "connected" : "not connected") << endl;
    cout << (uf.isConnected("e", "f") ? "connected" : "not connected") << endl;
    cout << "=====" << endl;

    uf.connect("a", "c");
    uf.connect("b", "d");
    
    cout << (uf.isConnected("a", "b") ? "connected" : "not connected") << endl;
    cout << (uf.isConnected("b", "c") ? "connected" : "not connected") << endl;
    cout << (uf.isConnected("c", "d") ? "connected" : "not connected") << endl;
    cout << (uf.isConnected("d", "e") ? "connected" : "not connected") << endl;
    cout << (uf.isConnected("e", "f") ? "connected" : "not connected") << endl;
    cout << "=====" << endl;
    cout << (uf.isConnected("a", "c") ? "connected" : "not connected") << endl;
    cout << (uf.isConnected("b", "d") ? "connected" : "not connected") << endl;
    cout << "=====" << endl;

    uf.connect("c", "b");
    
    cout << (uf.isConnected("a", "b") ? "connected" : "not connected") << endl;
    cout << (uf.isConnected("b", "c") ? "connected" : "not connected") << endl;
    cout << (uf.isConnected("c", "d") ? "connected" : "not connected") << endl;
    cout << (uf.isConnected("d", "e") ? "connected" : "not connected") << endl;
    cout << (uf.isConnected("e", "f") ? "connected" : "not connected") << endl;

    cout << "a size is: " << uf.size("a") << endl;
    cout << "b size is: " << uf.size("b") << endl;
    cout << "c size is: " << uf.size("c") << endl;
    cout << "d size is: " << uf.size("d") << endl;
    cout << "e size is: " << uf.size("e") << endl;
    cout << "f size is: " << uf.size("f") << endl;
    cout << "g size is: " << uf.size("g") << endl;
    cout << "h size is: " << uf.size("h") << endl;
}
