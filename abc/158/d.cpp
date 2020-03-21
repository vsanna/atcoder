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

int main() {
  string s;
  int q;
  cin >> s >> q;
  stack<char> front;
  stack<char> tail;
  bool swi = true;

  int ops;
  int f;
  char c;
  for (int i = 0; i < q; i++) {
    cin >> ops;
    if (ops == 1) {
      swi = !swi;
    } else {
      cin >> f >> c;
      if (f == 1) {
        if (swi) {
          front.push(c);
        } else {
          tail.push(c);
        }
      } else {
        if (swi) {
          tail.push(c);
        } else {
          front.push(c);
        }
      }
    }
  }

  if (swi) {
    string headString = "";
    while (front.size() > 0) {
      headString += front.top();
      front.pop();
    }
    string tailString = "";
    while (tail.size() > 0) {
      tailString += tail.top();
      tail.pop();
    }
    reverse(tailString.begin(), tailString.end());
    cout << (headString + s + tailString) << endl;
  } else {
    string headString = "";
    while (front.size() > 0) {
      headString += front.top();
      front.pop();
    }
    reverse(headString.begin(), headString.end());
    string tailString = "";
    while (tail.size() > 0) {
      tailString += tail.top();
      tail.pop();
    }
    reverse(s.begin(), s.end());
    cout << (tailString + s + headString) << endl;
  }
  return 0;
}