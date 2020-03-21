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
  int evalRPN(vector<string> &tokens) {
    stack<ll> s = stack<ll>();

    ll a, b;

    // NOTE: c++のswitchは整数値(char含む)しか使えない
    for (string token : tokens) {
      if (token == "+") {
        // NOTE: 取り出す順番に注意
        b = s.top();
        s.pop();
        a = s.top();
        s.pop();
        s.push(a + b);
        continue;
      }
      if (token == "-") {
        b = s.top();
        s.pop();
        a = s.top();
        s.pop();
        s.push(a - b);
        continue;
      }
      if (token == "/") {
        b = s.top();
        s.pop();
        a = s.top();
        s.pop();
        s.push(a / b);
        continue;
      }
      if (token == "*") {
        b = s.top();
        s.pop();
        a = s.top();
        s.pop();
        s.push(a * b);
        continue;
      }

      s.push(stoi(token));
    }
    return (int)s.top();
  }
};

int main() {
  Solution s = Solution();
  vector<string> tokens = vector<string>{"4", "13", "5", "/", "+"};
  cout << s.evalRPN(tokens);
}