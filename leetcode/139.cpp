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

// heap buffer flow -> out of rangeを疑う
class Solution {
 public:
  bool wordBreak(string s, vector<string> &wordDict) {
    // 先頭からlenが表現可能か
    vector<int> dp = vector<int>(s.length() + 1, -1);
    rec(s, dp, 0, wordDict);
    return dp[s.length()] == 1;
  }

  // dpを埋める
  void rec(string &s, vector<int> &dp, int len, vector<string> &wordDict) {
    if (len == 0) {
      dp[len] = 1;
    }
    if (len == s.length()) {
      return;
    }

    for (string word : wordDict) {
      if (len + word.length() <= s.length()) {
        if (dp[len + word.length()] == 1) {
          continue;
        }
        if (s.substr(len, word.length()) == word) {
          dp[len + word.length()] = 1;
          rec(s, dp, len + word.length(), wordDict);
        }
      }
    }
  }
};

int main() {
  Solution s = Solution();
  vector<string> dict{"leet", "code"};
  cout << s.wordBreak("leetcode", dict) << endl;
  cout << "====" << endl;
  dict = vector<string>{"apple", "pen"};
  cout << s.wordBreak("applepenapple", dict) << endl;
  cout << "====" << endl;
  dict = vector<string>{"cats", "dog", "sand", "and", "cat"};
  cout << s.wordBreak("catsandog", dict) << endl;
  cout << "====" << endl;
  dict = vector<string>{
      "cbc",   "bcda",  "adb",  "ddca", "bad",   "bbb",  "dad",   "dac",
      "ba",    "aa",    "bd",   "abab", "bb",    "dbda", "cb",    "caccc",
      "d",     "dd",    "aadb", "cc",   "b",     "bcc",  "bcd",   "cd",
      "cbca",  "bbd",   "ddd",  "dabb", "ab",    "acd",  "a",     "bbcc",
      "cdcbd", "cada",  "dbca", "ac",   "abacd", "cba",  "cdb",   "dbac",
      "aada",  "cdcda", "cdc",  "dbc",  "dbcb",  "bdb",  "ddbdd", "cadaa",
      "ddbc",  "babb"};
  cout << s.wordBreak("bccdbacdbdacddabbaaaadababadad", dict) << endl;
}