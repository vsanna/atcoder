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

template<typename T = ll>
class ModInt {
    static mod = 1000000007; 
public:
    T data;
    ModInt(T d) {
        data = d;
    }

    ModInt operator+(const ModInt& other) const {
        data += other.data;
        if (data > mod) {
            data -= mod;
        }
        return *this;
    }

    ModInt operator-(const ModInt& other) const {
        data -= other.data;
        if (data > mod) {
            data -= mod;
        }
        return *this;
    }

    ModInt operator*(const ModInt& other) const {
        data = data * other.data % mod;
        return *this;
    }
    
    ModInt operator/(const ModInt& other) const {
        u64 exp = mod - 2;
        while (exp) {
        if (exp % 2) {
            *this *= rhs;
        }
        rhs *= rhs;
        exp /= 2;
        }
        return *this;
    }

    ModInt pow(ll exp) const {

    }
};

int main() {
    
}