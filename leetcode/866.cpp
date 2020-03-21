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
  int primePalindrome(int N) {
    if (isPalindrome(N) && isPrime(N)) {
      return N;
    }

    int result;
    int current = N;
    while (true) {
      current = nextPalindrome(current);
      if (isPrime(current)) {
        result = current;
        break;
      };
    }
    return result;
  }

  bool isPrime(int N) {
    if (N == 0 || N == 1) return false;
    for (int i = 2; i * i <= N; i++) {
      if (N % i == 0) return false;
    }
    return true;
  }

  int nextPalindrome(int N) {
    int result = 0;
    if (!isPalindrome(N)) {
      while (true) {
        N++;
        if (isPalindrome(N)) {
          result = N;
          break;
        }
      }
    } else {
      vector<int> digits = vector<int>();
      if (N == 0) {
        return 1;
      } else {
        while (N > 0) {
          digits.push_back(N % 10);
          N = N / 10;
        }
        reverse(digits.begin(), digits.end());
      }

      for (int i = (digits.size() - 1) / 2; i >= 0; i--) {
        int currentDigit = digits[i];
        int newDigit = currentDigit + 1;

        if (newDigit < 10) {
          digits[i] = digits[digits.size() - 1 - i] = newDigit;
          break;
        }

        digits[i] = digits[digits.size() - 1 - i] = 0;
      }

      // 端点でも繰り上がった場合
      if (digits[0] == 0) {
        // 桁を一つ増やして 1, 0, 0, ...., 0, 1
        vector<int> newDigits = vector<int>(digits.size() + 1, 0);
        newDigits[0] = 1;
        newDigits[newDigits.size() - 1] = 1;
        digits = newDigits;
      }

      // cout << "======" << endl;
      // for (int i = 0; i < digits.size(); i++) {
      //   cout << digits[i] << ", ";
      // }
      // cout << endl;

      for (int i = 0; i < digits.size(); i++) {
        result = (result * 10) + digits[i];
      }
    }

    return result;
  }

  bool isPalindrome(int N) {
    vector<int> digits = vector<int>();
    if (N == 0) {
      return true;
    }

    while (N > 0) {
      digits.push_back(N % 10);
      N = N / 10;
    }

    for (int i = 0; i <= digits.size() / 2; i++) {
      if (digits[i] != digits[digits.size() - 1 - i]) return false;
    }
    return true;
  }
};

int main() {
  Solution s = Solution();
  for (int i = 0; i < 1000; i++) {
    int r = s.primePalindrome(i);
    cout << "i: " << i << ", isPalindrome: " << s.isPalindrome(i)
         << ", isPrime: " << s.isPrime(i) << ", result: " << r << endl;
  }
}