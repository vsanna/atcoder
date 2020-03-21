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
void chmax(int &a, int b) {
  if (a < b) {
    a = b;
  }
}

class Solution {
 public:
  int distanceBetweenBusStops(vector<int> &distance, int start,
                              int destination) {
    ll totallen = 0L;
    ll onepath = 0L;
    if (destination < start) {
      swap(destination, start);
    }

    for (int i = 0; i < distance.size(); i++) {
      totallen += distance[i];
      if (i >= start && i < destination) {
        onepath += distance[i];
      }
    }

    ll otherpath = (totallen - onepath);
    return onepath > otherpath ? otherpath : onepath;
  }
};

int main() {
  Solution s = Solution();
  vector<int> distances = vector<int>{1, 2, 3, 4};
  cout << s.distanceBetweenBusStops(distances, 0, 1) << endl;
  cout << s.distanceBetweenBusStops(distances, 0, 2) << endl;
  cout << s.distanceBetweenBusStops(distances, 0, 3) << endl;

  distances = vector<int>{7, 10, 1, 12, 11, 14, 5, 0};
  cout << s.distanceBetweenBusStops(distances, 7, 2) << endl;
}