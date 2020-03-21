#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <cmath>
#include <utility>
#include <bitset>
#include <queue>
#include <stack>
#include <limits>
#include <list>

using namespace std;
using ll = long long;
const ll INF = numeric_limits<ll>::max();
const int MOD = 1000000007;

/*
- 数え上げ: 写像12相
*/


template<typename T>
vector<T> factorialTable(T val) {
    vector<T> fact = vector<T>();
    fact[0] = 1;
    if (val == 0) {
        return fact;
    }
    
    for(int i = 1; i <= val; i++) {
        fact[i] = fact[i-1] * i;
    }

    return fact;
}

template<typename T>
T factorial(T val) {
    vector<T> factMap = factorialTable(val);
    return factMap[val];
}

template<typename T> 
T combination(T n, T r) {
    vector<T> fact = factorialTable(n);
    return (fact[n] / fact[r]) / fact[n-r];
}

template<typename T>
T permutation(T n, T r) {
    vector<T> fact = factorialTable(n);
    return fact[n] / fact[r]; 
}

// nCn = 1
// nC0 = 1
template<typename T>
vector<vector<T>> combinationTable(T n, T r) {
    vector<vector<T>> table = vector<vector<T>>(n + 1, vector<T>(r + 1, 0));
    // nCr = n-1Cr-1 + n-1Cr
    for(int i = 0; i <= n; i++) {
        table[i][0] = 1;
        for(int j = 1; j <= i; j++) {
            table[i][j] = table[i-1][j-1] + table[i-1][j];
        }
    }

    return table;
}

template<typename T> 
T combinationDp(T n, T r) {
    vector<vector<T>> dp = combinationTable(n, r);
    return dp[n][r];
}


// S(k, k) = 1, S(k, 0) = 0, S(0, 0) = 1
template<typename T>
vector<vector<T>> stirlingDpMap(T n, T r) {
    vector<vector<T>> dp = vector<vector<T>>(n + 1, vector<T>(n+1, 0));
    dp[0][0] = 1;

    for(int i = 1; i<=n; i++) {
        dp[i][0] = 0;
        dp[i][i] = 1;
        for(int j = 1; j<=r; j++) {
            dp[i][j] = dp[i-1][j-1] + j * dp[i-1][j];
        }
    }

    return dp;
}

// n個の要素を区別した上で、r種のグループに分ける分け方の総数
template<typename T>
T stirling(T n, T r) {
    vector<vector<T>> dp = stirlingDpMap(n, r);
    return dp[n][r];
}

template<typename T>
T bell(T n) {
    vector<vector<T>> dp = stirlingDpMap(n, n);
    ll result = 0;
    for(int i = 0; i <= n; i++) {
        result += dp[n][i];
    }
    return result;
}


// P(0, 0) = 1
// P(i, i) = 1
// P(n, r) = P(n-r, r) + P(n-1, r)
template<typename T>
vector<vector<T>> partitionTable(T n) {
   vector<vector<T>> table = vector<vector<T>>(n+1, vector<T>(n+1, 0));
   table[0][0] = 1;
   for(int i = 1; i<=n; i++) {
       for(int j = 1; j <= i; j++) {
           table[i][j] = table[i-j][j] + table[i-1][j];
       }
   }

   return table;
}

template <typename T>
T partition(T n, T r) {
    vector<vector<T>> pt = partitionTable<T>(n); 

    return pt[n][r];
}

int main() {
    cout << "====" << endl;
    cout << combination<ll>(0, 0) << endl;
    cout << combinationDp<ll>(0, 0) << endl;

    for(int i = 0; i <= 5; i++) {
        cout << "S(5, " << i << "): " << stirling<ll>(5, i) << endl;
    }
    
    for(int i = 0; i <= 10; i++) {
        cout << "B(" << i <<  "): " << bell<ll>(i) << endl;
    }
    
    for(int i = 0; i <= 10; i++) {
        cout << "partition(" << i <<  "): " << partition<ll>(i, i) << endl;
    }
}