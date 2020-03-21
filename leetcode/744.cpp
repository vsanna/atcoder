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

class Solution {
 public:
  char nextGreatestLetter(vector<char>& letters, char target) {
    return binarySearch(letters, target);
  }

  char binarySearch(vector<char>& letters, char target) {
    if (letters[letters.size() - 1] <= target) {
      return letters[0];
    }

    int low = 0;
    int high = letters.size() - 1;

    while (low < high) {
      int mid = (low + high) / 2;
      if (letters[mid] <= target) {
        low = mid + 1;
        continue;
      } else {
        high = mid;
      }
    }
    return letters[low];
  }
};

int main() {
  Solution s = Solution();
  char c;
  cin >> c;
  vector<char> letters = vector<char>{'c', 'f', 'j'};
  cout << s.nextGreatestLetter(letters, c) << endl;
}