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
class SingleLinkedListI {
    virtual SingleLinkedListI* insert(T val, ll pos) = 0;
    virtual SingleLinkedListI* remove(ll pos) = 0;
    virtual ll indexOf(T val) = 0;
    virtual T get(ll pos) = 0;
    virtual ll size() = 0;
    virtual T reGet(ll pos) = 0;
    virtual bool isCircle() = 0;
    virtual ll circleLength() = 0;
    // virtual SingleLinkedListNode* reverse() = 0;
    // virtual SingleLinkedListNode* connectionNode(SingleLinkedListNode* otherHead) = 0; 
    // virtual SingleLinkedListNode* centerNode() = 0;
    // virtual vector<T> traverse() = 0;
    // virtual vector<T> retraverse() = 0;
    // virtual bool isPalindrome() = 0;
};

template <typename T>
class SingleLinkedListNode : SingleLinkedListI<T> {
    using Node = SingleLinkedListNode; 
public:
    Node* next = nullptr;
    T val;

    SingleLinkedListNode(T val) {
        this->val = val;
    };

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
        while(current) {
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

        while(next) {
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
        while(current) {
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
        while(current) {
            if (pos == currentPos) {
                return current->val;
            }
            current = current->next;
            currentPos++;
        }
    }

    Node* getNode(ll pos) {
        Node *current = this;
        ll currentPos = 0;
        while(current) {
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

        while(true) {
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

        while(true) {
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
            while(true) {
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

    Node* connectedNode() {
        if (this->next == nullptr || this->next->next == nullptr) {
            return nullptr;
        }

        Node* fastPtr = this->next->next;
        Node* slowPtr = this->next;
        bool isCircle = false;

        while(true) {
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
            while(true) {
                if (fastPtr == slowPtr) break;
                fastPtr = fastPtr->next;
                slowPtr = slowPtr->next;
            }
            return fastPtr;
        } else {
            return nullptr;
        }
    }

    vector<T> traverse() {
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
    auto head = SingleLinkedListNode<int>(1);

    // 1 -> 2 -> 5 -> -1 -> 10 -> 100
    head.insert(2, 1);
    head.insert(-1, 2);
    head.insert(10, 3);
    head.insert(5, 2);
    head.insert(100, 5);
    for(auto item: head.traverse()) {
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
    SingleLinkedListNode<int>* lastNode = head.getNode(head.size()-1); 
    SingleLinkedListNode<int>* connectedNode = head.getNode(3);
    lastNode->next = connectedNode;
    cout << "isCircle: " << (head.isCircle() ? "true" : "false") << endl;
    cout << "circleLength: " << head.circleLength() << endl;
    cout << "connectedNode: " << head.connectedNode()->val << endl;

}


/*
- 
*/