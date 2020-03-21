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
void dumpvec(vector<T> vec) {
  for (T cnt : vec) {
    cout << cnt << ", ";
  }
  cout << endl;
}

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

int main() {}