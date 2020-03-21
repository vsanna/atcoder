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

void chmin(ll &a, ll b) {
  if (a > b) {
    a = b;
  }
}
void chmax(ll &a, ll b) {
  if (a < b) {
    a = b;
  }
}

// 特になし！
class MyHashSet {
  static const int size = 100;
  vector<list<int>> data;

 public:
  /** Initialize your data structure here. */
  MyHashSet() { this->data = vector<list<int>>(size, list<int>{}); }

  void add(int key) {
    int _hash = hash(key);
    for (auto iter = data[_hash].begin(); iter != data[_hash].end(); iter++) {
      if (*iter == key) return;
    }
    data[_hash].push_back(key);
  }

  void remove(int key) {
    int _hash = hash(key);
    for (auto iter = data[_hash].begin(); iter != data[_hash].end(); iter++) {
      if (*iter == key) {
        data[_hash].erase(iter);
        return;
      }
    }
  }

  bool contains(int key) {
    int _hash = hash(key);
    for (auto iter = data[_hash].begin(); iter != data[_hash].end(); iter++) {
      if (*iter == key) {
        return true;
      }
    }

    return false;
  }

 private:
  int hash(int key) {
    int _hash = 7;
    string s = to_string(key);
    for (int i = 0; i < min(50, (int)s.length()); i++) {
      _hash = (_hash * 31 + s[i]) % size;
    }
    return _hash;
  }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */

int main() {
  MyHashSet *obj = new MyHashSet();
  obj->add(1);
  obj->add(2);
  obj->add(3);
  obj->add(4);
  cout << obj->contains(1) << endl;
  cout << obj->contains(2) << endl;
  cout << obj->contains(3) << endl;
  cout << obj->contains(4) << endl;
  cout << obj->contains(5) << endl;
  cout << obj->contains(6) << endl;
  obj->remove(4);
  obj->remove(5);
  obj->remove(6);
  obj->remove(7);
  cout << obj->contains(1) << endl;
  cout << obj->contains(2) << endl;
  cout << obj->contains(3) << endl;
  cout << obj->contains(4) << endl;
  cout << obj->contains(5) << endl;
  cout << obj->contains(6) << endl;
}