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
class PriorityQueueNode {
public:
    int priority;
    T val;

    PriorityQueueNode(T val, int priority) {
        this->val = val;
        this->priority = priority;
    }

    bool operator< (const PriorityQueueNode& other) const { 
        return this->priority < other.priority;
    }
    bool operator> (const PriorityQueueNode& other) const { 
        return this->priority > other.priority;
    }


};

template <typename T>
ostream& operator<<(ostream& os, PriorityQueueNode<T>& node) {
    // ここでストリームに obj を書き込みます。
    os << "{priority: " << node.priority << ", val: " << node.val << " }" << endl;
    return os;
}
// template <typename T>
// bool operator< (const PriorityQueueNode<T>*& t1, const PriorityQueueNode<T>*& t2) { 
//     return t2->priority < t1->priority; 
// }

// template <typename T>
// bool operator> (const PriorityQueueNode<T>*& t1, const PriorityQueueNode<T>*& t2) { 
//     return t2 > t1; 
// }



template <typename T>
class HeapI 
{
public:
    virtual void add(T val) = 0;
    virtual void bubbleUp() = 0;
    virtual T top() = 0;
    virtual T pop() = 0;
    virtual void sinkDown() = 0;
    virtual vector<T> heapSort() = 0;
};

template <typename T>
class Heap : HeapI<T> {
public:
    vector<T> data;
    Heap() {
        this->data = vector<T>();
    }

    void add(T val) override {
        data.push_back(val);
        bubbleUp();
    }

    void bubbleUp() override {
        if (data.empty()) return;

        ll currentIdx = data.size() - 1;
        ll parentIdx = floor((currentIdx - 1) / 2.0f);
        while(parentIdx >= 0 && data[currentIdx] < data[parentIdx]) {
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

    // 1 - 10 - 5 - 11 - 12
    // 12 - 10 - 5 - 11
    // 
    // 10 - 12 - 5
    // 

    void sinkDown() override {
        
        ll currentIdx = 0;
        ll leftChildIdx = currentIdx * 2 + 1;
        ll rightChildIdx = currentIdx * 2 + 2;

        while ((leftChildIdx < data.size() && data[currentIdx] > data[leftChildIdx]) || 
               (rightChildIdx < data.size() && data[currentIdx] > data[rightChildIdx])) {
            ll minIdx = (rightChildIdx < data.size() && data[leftChildIdx] > data[rightChildIdx]) ? rightChildIdx : leftChildIdx;
            swap(data[currentIdx], data[minIdx]);
            currentIdx = minIdx;
            leftChildIdx = currentIdx * 2 + 1;
            rightChildIdx = currentIdx * 2 + 2;
        }
    }

    T top() override {
        return data.front();
    }

    vector<T> heapSort() override {
        vector<T> result = vector<T>();
        while(data.size() > 0) {
            result.push_back(pop());
        }
        return result;
    }
};


int main() {
    using Node = PriorityQueueNode<int>;
    using PriorityQueue = Heap<Node>;

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

    for(auto node: pq.heapSort()) {
        cout << "priority: " << node.priority << " val: " << node.val << endl;
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