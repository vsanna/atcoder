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
using ull = unsigned long long;
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
  string fractionToDecimal(int numerator, int denominator) {
    if (numerator == 0) return "0";

    ll Numerator = (ll)numerator;
    ll Denominator = (ll)denominator;

    bool isNegative = (Numerator < 0 ? -1 : 1) * (Denominator < 0 ? -1 : 1) < 0;

    // NOTE: 不要にマイナスをかけるとoverflowする
    Numerator = Numerator < 0 ? Numerator * -1 : Numerator;
    Denominator = Denominator < 0 ? Denominator * -1 : Denominator;

    stack<pair<string, pair<int, int>>> ans{};
    ll currentN = Numerator;
    ll currentR = 0;
    string repeating = "";

    set<pair<int, int>> shown{};

    while (true) {
      ll a = currentN / Denominator;
      ll b = currentN % Denominator;
      pair<ll, ll> p = make_pair(a, b);

      cout << "currentN = " << currentN << ", currentR = " << currentR
           << ", a = " << a << ", b = " << b << endl;

      // detect loop.
      // 直前の同一pairからここまでの内容をカッコにくくる
      if (shown.count(p) > 0) {
        stack<string> tmp{};
        while (true) {
          pair<string, pair<ll, ll>> c = ans.top();
          ans.pop();
          tmp.push(c.first);
          if (c.second == p) {
            break;
          }
        }
        while (tmp.size() > 0) {
          repeating += tmp.top();
          tmp.pop();
        }
        break;
      }

      shown.insert(p);

      ans.push(make_pair(to_string(a), p));
      if (b == 0) {
        break;
      }

      currentN = b * 10;
    }

    string result = "";
    vector<string> rev{};
    while (ans.size() > 0) {
      rev.push_back(ans.top().first);
      ans.pop();
    }
    reverse(rev.begin(), rev.end());
    for (int i = 0; i < rev.size(); i++) {
      string c = rev[i];
      result += c;
      if (i == 0 && (i + 1 < rev.size() || repeating.length() > 0)) {
        result += ".";
      }
    }

    if (repeating.length() > 0) {
      result += '(' + repeating + ')';
    }

    if (isNegative) {
      result = "-" + result;
    }

    return result;
  }
};

int main() {
  Solution s = Solution();
  cout << s.fractionToDecimal(1, 2) << endl;
  cout << s.fractionToDecimal(2, 1) << endl;
  cout << s.fractionToDecimal(1, 3) << endl;
  cout << s.fractionToDecimal(2, 3) << endl;
  cout << s.fractionToDecimal(15, 7) << endl;
  cout << s.fractionToDecimal(7, 15) << endl;
  cout << s.fractionToDecimal(150, 7) << endl;
  cout << s.fractionToDecimal(-1, -2147483648) << endl;
}