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

void chmin(ll& a, ll b) {
  if (a > b) {
    a = b;
  }
}
void chmax(ll& a, ll b) {
  if (a < b) {
    a = b;
  }
}

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

// i以降でj以降を再現する
ll levenshteinDistanceHelper(string& original, string& other,
                             vector<vector<ll>>& dp, ll i, ll j) {
  if (original.length() == i && other.length() == j) {
    dp[i][j] = 0;
    return dp[i][j];
  }

  if (original.length() == i) {
    // there is no character left in original string.
    // 残りのother分insertする
    // dp[i][j] = (ll)(other.length() - j);
    dp[i][j] = levenshteinDistanceHelper(original, other, dp, i, j + 1) + 1;
    return dp[i][j];
  }

  if (other.length() == j) {
    // there is no character left in other string.
    // 残りのoriginal分remove処理を行う
    // dp[i][j] = (ll)(original.length() - i);
    dp[i][j] = levenshteinDistanceHelper(original, other, dp, i + 1, j) + 1;
    return dp[i][j];
  }

  if (dp[i][j] >= 0) {
    return dp[i][j];
  }

  if (original[i] == other[j]) {
    dp[i][j] = levenshteinDistanceHelper(original, other, dp, i + 1, j + 1);
  } else {
    ll minCost = INF;
    // NOTE: insertCost, removeCost, replaceCostにしてもいい

    // remove
    chmin(minCost,
          levenshteinDistanceHelper(original, other, dp, i + 1, j) + 1);

    // insert
    chmin(minCost,
          levenshteinDistanceHelper(original, other, dp, i, j + 1) + 1);

    // replace
    chmin(minCost,
          levenshteinDistanceHelper(original, other, dp, i + 1, j + 1) + 1);

    dp[i][j] = minCost;
  }
  return dp[i][j];
}

ll levenshteinDistance(string& original, string& other) {
  // i以降を使ってj以降を再現するコスト
  vector<vector<ll>> dp = vector<vector<ll>>(
      other.length() + 1, vector<ll>(original.length() + 1, -1));
  return levenshteinDistanceHelper(original, other, dp, 0, 0);
}

vector<string> split(string s, string delimiter) {
  int first = 0;
  int last = s.find_first_of(delimiter);
  vector<string> result;

  while (first < s.size()) {
    string sub = s.substr(first, last - first);
    result.push_back(sub);
    first = last + 1;
    last = s.find_first_of(delimiter, first);

    if (last == string::npos) {
      last = s.size();
    }
  }

  return result;
}

string join(vector<string> strings, string delimiter) {
  string result = "";
  for (int i = 0; i < strings.size(); i++) {
    if (result != "") result += delimiter;
    result += strings[i];
  }
  return result;
}

int main() {
  vector<pair<pair<string, string>, ll>> testcases =
      vector<pair<pair<string, string>, ll>>();
  testcases.push_back(make_pair(make_pair("aiueo", "auueo"), 1));
  testcases.push_back(make_pair(make_pair("other", "nothing"), 4));
  testcases.push_back(make_pair(make_pair("aiueo", "gahogahogaho"), 10));

  for (auto testcase : testcases) {
    cout << "expected: " << testcase.second
         << ", input: original:" << testcase.first.first
         << ", other: " << testcase.first.second << ", actual: "
         << levenshteinDistance(testcase.first.first, testcase.first.second)
         << endl;
  }
}