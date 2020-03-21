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

class Solution {
 public:
  vector<string> subdomainVisits(vector<string> &cpdomains) {
    map<string, int> count;

    for (string record : cpdomains) {
      vector<string> data = split(record, " ");
      int score = stoi(data[0]);
      string domain = data[1];

      vector<string> sections = split(domain, ".");
      reverse(sections.begin(), sections.end());
      string current = "";
      for (string section : sections) {
        current = section + current;

        count[current] += score;

        current = "." + current;
      }
    }

    vector<string> result;

    for (auto kv : count) {
      int score = kv.second;
      string domain = kv.first;
      string record = to_string(score) + " " + domain;
      result.push_back(record);
    }

    return result;
  }
};

int main() {
  Solution s = Solution();
  vector<string> values = vector<string>{
      "900 google.mail.com",
      "50 yahoo.com",
      "1 intel.mail.com",
      "5 wiki.org",
  };
  for (string result : s.subdomainVisits(values)) {
    cout << result << endl;
  }
}