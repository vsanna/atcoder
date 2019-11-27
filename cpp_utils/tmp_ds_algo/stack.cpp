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
class StackI 
{
public:
    virtual void push(T val) = 0;
    virtual T pop() = 0;
    virtual T top() = 0;
    virtual ll size() = 0;
    virtual bool isEmpty() = 0;
};

template <typename T>
class Stack : StackI<T> {
public:
    list<T> data;
    Stack() {
        this->data = list<T>();
    }

    void push(T val) override {
        data.push_back(val);
    }

    T pop() override {
        T val = data.back();
        data.pop_back();
        return val;
    }

    T top() override {
        return data.back();
    }

    ll size() override {
        return data.size();
    }

    bool isEmpty() override {
        return data.size() == 0;
    }
};


int main() {
    Stack<int> s = Stack<int>();
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;


    // stack使った問題をここに説いていく
}