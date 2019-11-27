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
    Heap<int> heap = Heap<int>();
    heap.add(10);
    heap.add(21);
    heap.add(5);
    heap.add(-10);
    heap.add(100);

    cout << "top: " << heap.top() << endl;

    for(auto item: heap.heapSort()) {
        cout << "sort: " << item << endl;
    }

    // 問題をここに解いていく
}