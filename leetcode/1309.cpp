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

class Tokenizer {
 public:
  Tokenizer(string input) {
    this->input = input;
    this->idx = 0;
  }

  string input;
  int idx;

  bool hasHash() {
    if (idx + 2 > input.size() - 1) {
      return false;
    }

    return (input[idx + 2] == '#');
  }

  char nextChar() {
    int result = 96;  // 97 = 'a'
    if (idx == input.size()) {
      return EOF;
    }

    string token;
    int numtoken;

    if (hasHash()) {
      token = input.substr(idx, 2);
      // ref: https://marycore.jp/prog/cpp/convert-string-to-number/
      // string -> int: stoi
      // string -> double: stod
      // int -> string: to_string(someInt);
      // char -> int('1' -> 1): ???
      // int -> char(1 -> '1'): ???
      //
      // char -> int('a' -> 97): int(someChar)
      // char -> int('a' -> 1): int(someChar) - 96
      //
      numtoken = stoi(token);
      idx += 3;
    } else {
      token = input.substr(idx, 1);
      numtoken = stoi(token);
      idx++;
    }

    // cout << "token: " << token << ", numtoken: " << numtoken << endl;

    return (char)(result + numtoken);
  }
};

class Solution {
 public:
  string freqAlphabets(string s) {
    string result = "";
    Tokenizer tokenizer = Tokenizer(s);

    while (true) {
      char nextChar = tokenizer.nextChar();
      if (nextChar == EOF) {
        break;
      }
      result += nextChar;
    }

    return result;
  }
};

int main() {
  Solution s = Solution();
  cout << s.freqAlphabets("10#11#12") << endl;
  cout << s.freqAlphabets("1326#") << endl;
  cout << s.freqAlphabets("25#") << endl;
  cout << s.freqAlphabets(
              "12345678910#11#12#13#14#15#16#17#18#19#20#21#22#23#24#25#26#")
       << endl;

  cout << (char)(96 + 1) << endl;
}