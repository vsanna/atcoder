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
class QueueI 
{
public:
    virtual void enqueue(T val) = 0;
    virtual T dequeue() = 0;
    virtual T top() = 0;
    virtual ll size() = 0;
    virtual bool isEmpty() = 0;
};

template <typename T>
class Queue : QueueI<T> {
public:
    list<T> data;
    Queue() {
        this->data = list<T>();
    }

    void enqueue(T val) override {
        data.push_back(val);
    }

    T dequeue() override {
        T val = data.front();
        data.pop_front();
        return val;
    }

    T top() override {
        return data.front();
    }

    ll size() override {
        return data.size();
    }

    bool isEmpty() override {
        return data.size() == 0;
    }
};


int main() {
    Queue<int> q = Queue<int>();
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;


    // queue使った問題をここに説いていく
}