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
const ll INF = numeric_limits<ll>::max();
const int MOD = 1000000007;

/*
- 約数列挙
- 約数の個数
- 約数の総和
- 素数判定
- 素因数分解
- 中国余剰定理
- オイラーのφ関数: N以下のNと互いに素な整数の個数
- 最大公約数 / 最小公倍数 / ユークリッドの互除法
- 拡張ユークリッドの互除法
- 中国剰余定理
- 逆元
- modint
*/

template <typename T>
T gcd(T a, T b) {
  if (a < b) swap(a, b);

  while (b != 0) {
    T tmp = b;
    b = a % b;
    a = b;
  }

  return a;
}

template <typename T>
T lcm(T a, T b) {
  T gcd = gcd(a, b);
  return (a / gcd) * b;
}

template <typename T>
bool isPrime(T val) {
  if (val == 0) return false;
  if (val == 1) return false;
  for (int i = 2; i * i <= val; i++) {
    if (val % i == 0) return false;
  }
  return true;
}

// 約数の配列
template <typename T>
vector<T> dividors(T val) {
  vector<T> result = vector<T>();
  for (int i = 1; i * i <= val; i++) {
    if (val % i == 0) {
      result.push_back(i);
      if (i * i != val) {
        result.push_back(val / i);
      }
    }
  }
  return result;
}

// idxを底, result[idx]をその指数として返す
template <typename T>
vector<T> primeFactors(T val) {
  if (val < 2) {
    return vector<T>();
  }

  T orignal = val;
  vector<T> result = vector<T>(val, 0);
  for (int i = 2; i * i <= val; i++) {
    if (val % i == 0) {
      result[i]++;
      val /= i;
    }
  }
  return result;
}

// 6x+8y=10の整数解を求めよ
// ax + by = c という四季があるとする
// 1. cはLCM(a, b)の倍数であることが会を持つ条件
//
template <typename T>
T extGCD(T a, T b, T &x, T &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  T d = extGCD(b, a % b, y, x);
  y -= a / b * x;
  return d;
}

int main() {
  cout << "gcd: " << gcd(48, 15) << endl;
  cout << "lcm: " << lcm(48, 15) << endl;

  for (int i = 0; i <= 100; i++) {
    cout << "primeFactor(" << i << "): ";
    for (auto val : primeFactors(0)) {
      cout << val;
    }
    cout << endl;
  }
}