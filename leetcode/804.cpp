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

const vector<string> morseMap = vector<string>{
    ".-",   "-...", "-.-.", "-..",  ".",   "..-.", "--.",  "....", "..",
    ".---", "-.-",  ".-..", "--",   "-.",  "---",  ".--.", "--.-", ".-.",
    "...",  "-",    "..-",  "...-", ".--", "-..-", "-.--", "--.."};

class Solution {
 public:
  int uniqueMorseRepresentations(vector<string> &words) {
    int count = 0;
    map<string, int> freq = map<string, int>();
    for (auto word : words) {
      string result = "";
      for (int i = 0; i < word.size(); i++) {
        result += toMorse(word[i]);
      }
      if (freq[result] == 0) {
        count++;
      }
      freq[result]++;
    }

    return count;
  }

  string toMorse(char c) { return morseMap[(int)(c)-97]; }
};

int main() {
  Solution s = Solution();
  vector<string> words1 = vector<string>{"gin", "zen", "gig", "msg"};
  cout << s.uniqueMorseRepresentations(words1) << endl;
}