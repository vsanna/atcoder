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
class Node
{
public:
    T val;
    Node<T>* left = nullptr;
    Node<T>* right = nullptr;

    Node(T& v) {
        this->val = v;
    }
};

template <typename T>
class BinarySearchTreeI
{
public:
    virtual void add(T val) = 0;
    // virtual Node* remove(T val) = 0;
    virtual Node* find(T val) = 0;
    virtual Node* findMin(Node* start) = 0;
    // virtual Node* findMax() = 0;
    virtual Node* findKthMin() = 0;
    virtual vector<T> bfs(Node<T>* start) = 0;
    virtual vector<T> dfsInorder(Node<T>* start) = 0;
    // virtual vector<T> dfsPreorder() = 0;
    // virtual vector<T> dfsPostorder() = 0;
    // virtual int height() = 0;
    // LCA
    // diameter
    virtual Node* findParent(Node* target) = 0;
    virtual Node* findNext(Node* target) = 0;
    // ancesstors
    //
};

template <typename T>
class BinarySearchTree : BinarySearchTreeI<T>
{
    // NOTE: こういう書き方ができる
    using Node = Node<T>;

    Node *root = nullptr;

public:
    BinarySearchTree(){};

    void add(T val) override
    {
        // Node* node = Node(val); // TODO: これがなぜかrootをうわがく理由
        Node* node = new Node(val); // NOTE: ポインタ変数の初期化はnew使う

        if (this->root == nullptr)
        {
            this->root = node;
            return;
        }

        Node* current = this->root;
        while (true)
        {
            if (val < current->val)
            {
                if (current->left == nullptr)
                {
                    current->left = node;
                    break;
                }
                else
                {
                    current = current->left;
                    continue;
                }
            }
            else
            {
                if (current->right == nullptr)
                {
                    current->right = node;
                    break;
                }
                else
                {
                    current = current->right;
                    continue;
                }
            }
        }

        return;
    }

    Node* find(T val) override {

    }

    vector<T> bfs(Node* start) override {
        if (start == nullptr) {
            start = this->root;
        }

        vector<T> result = vector<T>();
        auto q = queue<Node*>();
        q.push(start);

        while(!q.empty()) {
            Node* current = q.front();
            q.pop();
            if(current->left != nullptr) {
                q.push(current->left);
            }
            if(current->right != nullptr) {
                q.push(current->right);
            }
            result.push_back(current->val);
        }

        return result;
    }

    void dfsInorderHelper(Node* current, vector<T>& results) {
        if (current->left != nullptr){
            dfsInorderHelper(current->left, results);
        }
        results.push_back(current->val);
        if (current->right != nullptr){
            dfsInorderHelper(current->right, results);
        }
    }

    vector<T> dfsInorder(Node* start) override {
        vector<T> results = vector<T>();
        if (start == nullptr) {
            start = this->root;
        }

        dfsInorderHelper(start, results);

        return results;
    }

    Node* findKthMin() override {
        int count = 0;
        
    }

    Node* findParent(Node* target) override {
        if (this->root == target) {
            return nullptr;
        }

        Node* current = this->root;
        while(true) {
            if (current->left == target || current->right == target) {
                return current;
            }
            if (target->val <= current->val) {
                if (current->left == nullptr) {
                    return nullptr;
                }
                current = current->left;
                continue;
            }
            if (target->val > current->val) {
                if (current->right == nullptr) {
                    return nullptr;
                }
                current = current->right;
                continue;
            }
        }
    }

    Node* findNext(Node* target) override {
        if (target->right == nullptr) {
            return this->findParent(target);
        }

        return this->findMin(target->right);
    }

    Node* findMin(Node* start) override {
        Node* current = start;
        while(current->left) {
            current = current->left;
        }
        return current;
    }
};

int main()
{
    BinarySearchTree<int> bts = BinarySearchTree<int>();
    bts.add(100);
    bts.add(210);
    bts.add(90);
    bts.add(130);
    bts.add(120);
    bts.add(170);
    bts.add(180);
    bts.add(140);
    cout << "====" << endl;
    auto result = bts.bfs(nullptr);
    for(auto item: result) {
        cout << item << endl;
    }
    cout << "=========" << endl;
    result = bts.dfsInorder(nullptr);
    for(auto item: result) {
        cout << item << endl;
    }
}