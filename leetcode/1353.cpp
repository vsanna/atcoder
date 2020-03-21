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

class Solution {
 public:
  int maxEvents(vector<vector<int>> &events) {
    // 終わりが近いものから取る
    // 終わりが同じものの中ではstart_atが早いものからとる
    // start_at, end_at

    // priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)>
    // pq(
    //     comp);

    // start_at, end_at
    // NOTE: pqはデフォルトで降順
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;

    for (vector<int> event : events) {
      pq.push(make_pair(event[0], event[1]));
    }

    int count = 0;
    int currentdate = 1;

    // NOTE: true -> bが前
    auto comp = [](pair<int, int> a, pair<int, int> b) {
      if (a.second != b.second) {
        return a.second > b.second;  // end_atが近い順
      } else {
        return a.first > b.first;  // start_atが近い順
      }
    };

    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)>
        available(comp);

    while (pq.size() > 0 && pq.top().first <= currentdate) {
      pair<int, int> event = pq.top();
      pq.pop();
      available.push(event);
    }
    if (available.size() == 0 && pq.size() > 0) {
      pair<int, int> event = pq.top();
      pq.pop();
      available.push(event);
    }

    while (available.size() > 0) {
      pair<int, int> event = available.top();
      available.pop();

      int start_at = event.first;
      int end_at = event.second;

      if (end_at < currentdate) {
        goto reload;
      };

      if (currentdate < start_at) {
        currentdate = start_at;
      }

      cout << "====" << endl;
      cout << "avalable: " << available.size() << ", pq:" << pq.size() << endl;
      dump(currentdate);
      dump(start_at);
      dump(end_at);

      count++;
      currentdate++;

    reload:
      // cout << "pq.top().first: " << pq.top().first << endl;
      while (pq.size() > 0 && pq.top().first <= currentdate) {
        pair<int, int> event = pq.top();
        pq.pop();
        available.push(event);
      }

      if (available.size() == 0 && pq.size() > 0) {
        pair<int, int> event = pq.top();
        pq.pop();
        available.push(event);
      }
    }

    return count;
  }
};

int main() {
  Solution s = Solution();
  vector<vector<int>> events = vector<vector<int>>{
      vector<int>{1, 2}, vector<int>{1, 2}, vector<int>{3, 3},
      vector<int>{1, 5}, vector<int>{1, 5},
  };

  // events = vector<vector<int>>{
  //     vector<int>{1, 3}, vector<int>{2, 3}, vector<int>{3, 3},
  //     vector<int>{5, 7}, vector<int>{6, 7}, vector<int>{7, 7},
  // };

  events = vector<vector<int>>{
      vector<int>{},     vector<int>{1, 5}, vector<int>{1, 5},
      vector<int>{2, 3}, vector<int>{2, 3},
  };

  events = vector<vector<int>>{
      vector<int>{27, 29}, vector<int>{28, 32}, vector<int>{3, 3},
      vector<int>{24, 25}, vector<int>{7, 7},   vector<int>{22, 25},
      vector<int>{14, 15}, vector<int>{13, 17}, vector<int>{1, 2},
      vector<int>{7, 7},   vector<int>{10, 12}, vector<int>{9, 13},
      vector<int>{21, 25}, vector<int>{20, 21}, vector<int>{20, 22},
      vector<int>{19, 20}, vector<int>{27, 28}, vector<int>{9, 9},
      vector<int>{21, 24}, vector<int>{18, 21}, vector<int>{6, 10},
      vector<int>{29, 30}, vector<int>{22, 24},
  };
  cout << s.maxEvents(events) << endl;
}