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

int stringHash(string key, int capacity) {
    // TODO: fix
    int total = 0;
    const int prime = 31;

    int upperLimit = (key.size() < 100) ? key.size() : 100;
    cout << "key: " << key << endl << "upper: " << upperLimit << endl;

    for (int i = 0; i < upperLimit; i++)
    {
        const char character = key[i];
        cout << "character: " << character << endl;
        int value = atoi(&character);
        cout << "value: " << value << endl;
        total += (total * prime + value) % capacity;
    }

    return total;
}

template <typename K, typename V>
class HashMapI
{
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
    HashMap() {
        data = vector<vector<pair<K, V>>>(capacity);
    }

    void set(K key, V val) override {
        int idx = hash(key);
        bool found = false;
        for(pair<K, V> p: data[idx]) {
            if (p.first == key) {
                found = true;
                p.second = val;
                break;
            }
        }

        if (!found) {
            pair<K, V> p = pair<K, V>(key, val);
            data[idx].push_back(p);
        }
    }

    V get(K key) override {
        int idx = hash(key);
        for(pair<K, V> p: data[idx]) {
            if (p.first == key) {
                return p.second;
            }
        }
    }

    int hash(K key) override {
        int hashIdx = stringHash(key, capacity);
        cout << "hashIdx: " << hashIdx << endl;
        return hashIdx;
    }

    ll size() override {
        // TODO: imple
        return 10;
    }
};


int main() {
    using Dict = HashMap<string, int>;
    Dict dict = Dict();

    dict.set("a", 10);
    dict.set("aa", 20);
    dict.set("bb", 30);
    dict.set("c", 40);

    cout << dict.get("c") << endl;
    cout << dict.get("a") << endl;
    cout << dict.get("aa") << endl;
    cout << dict.get("bb") << endl;

}