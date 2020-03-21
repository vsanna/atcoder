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
class SegmentTreeI 
{
public:
    virtual void update(ll pos, T val) = 0;
    virtual T query(ll from, ll to) = 0;
};

template <typename T>
class SegmentTree : SegmentTreeI<T>
{
private:
    // return min of [from, to)
    T _query(ll from, ll to, ll currentIdx, ll left, ll right) {
        if (to <= left || right <= from) return INF;
        if (from <= left && right <= to) return data[currentIdx]; // including base case
        T lelftMin = _query(from, to, 2*currentIdx + 1, left, (right + left) / 2);
        T righttMin = _query(from, to, 2*currentIdx + 2, (right + left) / 2, right);
        // cout << "from: " << from << ", to: " << to 
        //      << ", currentIdx: " << currentIdx << ", left: " << left << ", right: " << right
        //      << ", leftMin: " << lelftMin << ", rightMin: " << righttMin
        //      << endl;
        return min(lelftMin, righttMin);
    }

public:
    vector<T> data;
    ll base;
    T def; // 単位元
    function<T(T, T)> selection;
    // function<T(T, T)> update;

    SegmentTree(
        vector<T> arr, 
        T _def, 
        // function<T(T, T)> _update,
        function<T(T, T)> _selection
        ) {
        this->def = _def;
        this->selection = _selection;
        // this->update = _update;

        base = 1;
        while(base < arr.size()) {
            base *= 2;
        }
        data = vector<T>(2 * base - 1, def);

        for(int i = 0; i < arr.size(); i++) {
            data[base - 1 + i] = arr[i];
        }

        for(int i = base - 2; i >= 0; i--) {
            // data[i] = min(data[2 * i + 1], data[2 * i + 2]);
            data[i] = selection(data[2 * i + 1], data[2 * i + 2]);
        }

        for(auto v: data) {
            cout << v << ", ";
        }
        cout << endl;
    }

    void update(ll pos, T val) override {
        pos = pos + base - 1;
        data[pos] = val;
        ll parentIdx = floor((pos - 1) / 2);
        while(parentIdx >= 0) { 
            data[parentIdx] = selection(data[2 * parentIdx + 1], data[2 * parentIdx + 2]);
            parentIdx = floor((parentIdx - 1) / 2.0f);; 
        }
    }

    // [from, to) のminを返す
    T query(ll from, ll to) override {
        if (from >= to) throw invalid_argument("from must be less than to");
        return _query(from, to, 0, 0, base);
    }
};

int main() {
    // [3, 1, 5, 9, -1, -2]
    vector<ll> arr = vector<ll>();
    arr.push_back(3);
    arr.push_back(1);
    arr.push_back(5);
    arr.push_back(9);
    arr.push_back(-1);
    arr.push_back(2);

    function<ll(ll, ll)> selection = [](ll a, ll b) { return min(a, b); };

    SegmentTree<ll> st = SegmentTree<ll>(arr, INF, selection);
    cout << st.query(0, 1) << endl;
    cout << st.query(0, 2) << endl;
    cout << st.query(0, 3) << endl;
    cout << st.query(0, 4) << endl;
    cout << st.query(0, 5) << endl;
    cout << st.query(0, 6) << endl;

    st.update(2, -10);
    st.update(5, 100);

    cout << "=====" << endl;

    cout << st.query(0, 1) << endl;
    cout << st.query(0, 2) << endl;
    cout << st.query(0, 3) << endl;
    cout << st.query(0, 4) << endl;
    cout << st.query(0, 5) << endl;
    cout << st.query(0, 6) << endl;
}