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

template <typename K, typename V>
class HashMapI {
 public:
  virtual void set(K key, V val) = 0;
  virtual V get(K key) = 0;
  virtual ll size() = 0;
  virtual int hash(K key) = 0;
};

template <typename K = string, typename V = int>
class HashMap : HashMapI<K, V> {
 public:
  int capacity = 10;
  vector<vector<pair<K, V>>> data;
  HashMap(int cap) {
    this->capacity = cap;
    this->data = vector<vector<pair<K, V>>>(capacity);
  }
  HashMap() { HashMap(10); }

  void set(K key, V val) override {
    int idx = hash(key);
    cout << "idx: " << idx << endl;
    cout << "idx: " << data[idx] << endl;
    bool found = false;
    for (pair<K, V> p : data[idx]) {
      if (p.first == key) {
        found = true;
        p.second = val;
        break;
      }
    }

    // if (!found) {
    //   cout << "====";
    //   pair<K, V> p = make_pair(key, val);
    //   data[idx].push_back(p);
    // }
  }

  V get(K key) override {
    int idx = hash(key);
    for (pair<K, V> p : data[idx]) {
      if (p.first == key) {
        return p.second;
      }
    }
  }

  int hash(K key) override {
    int hashIdx = stringHash(key, capacity);
    return hashIdx;
  }

  ll size() override {
    // TODO: imple
    return 10;
  }

 private:
  int stringHash(string key, int capacity) {
    int _hash = 7;
    const int prime = 31;

    int upperLimit = min((int)key.length(), 100);

    for (int i = 0; i < upperLimit; i++) {
      const char character = key[i];
      int value = atoi(&character);
      _hash += (_hash * prime + key.at(i)) % capacity;
    }

    return _hash % capacity;
  }
};

int main() {
  using Dict = HashMap<string, int>;
  Dict dict = Dict();

  dict.set("a", 10);
  //   dict.set("aa", 20);
  //   dict.set("bb", 30);
  //   dict.set("c", 40);

  //   cout << dict.get("c") << endl;
  //   cout << dict.get("a") << endl;
  //   cout << dict.get("aa") << endl;
  //   cout << dict.get("bb") << endl;
}