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
class CircularLinkedListI {
    virtual CircularLinkedListI* push_front(T val) = 0;
    virtual void push_back(T val) = 0;
    virtual T pop_front() = 0;
    virtual T pop_back() = 0;
    virtual vector<T> traverse() = 0;
};

template <typename T>
class CircularLinkedListNode : CircularLinkedListI<T> {
    using Node = CircularLinkedListNode; 
public:
    Node* next = nullptr;
    T val;

    CircularLinkedListNode(T val) {
        this->val = val;
    };

    Node* tail() {
        Node* current = this;
        while(current->next != nullptr) {
            current = current->next;
        } 

        return current;
    }

    Node* push_front(T val) override {
        Node* newHead = new Node(val);
        newHead->next = this;
        return newHead;
    }

    void push_back(T val) override {
        Node* node = new Node(val);
        Node* lastNode = tail();
        lastNode->next = node;
    }

    T pop_front() override {
        Node* next = this->next;
        if (next == nullptr) {
            throw runtime_error("data is empty.");
        }
        return next->val;
    }

    T pop_back() override {
        Node* prev = this;
        Node* next = this->next;

        // if only one node is here.
        if (next == nullptr) {
            throw runtime_error("data is empty.");
        }

        while(next->next) {
            prev = next;
            next = next->next;
        }

        prev->next = nullptr;
        return this->val;
    }

    vector<T> traverse() override {
        vector<T> result = vector<T>();
        Node* current = this;
        while(current) {
            result.push_back(current->val);
            current = current->next;
        }
        return result;
    }
};

int main() {
    using LinkedList = CircularLinkedListNode<int>;
    LinkedList* head = new LinkedList(1);
    head->push_back(10);
    head->push_back(100);
    head->push_back(1000);
    head = head->push_front(0);
    head = head->push_front(-1);
    head = head->push_front(-10);
    head = head->push_front(-100);

    for(auto item: head->traverse()) {
        cout << "item: " << item << endl;
    }
}
