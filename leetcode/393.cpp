#include <algorithm>
#include <bitset>
#include <cmath>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <set>
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
  bool validUtf8(vector<int> &data) {
    // NOTE: bitset初期化
    // bitset<8>("00001000")
    // bitset<8>(8)      // bum
    bitset<8> singlebyte = bitset<8>("10000000");
    bitset<8> doublebyte = bitset<8>("11100000");
    bitset<8> triplebyte = bitset<8>("11110000");
    bitset<8> quadruplebyte = bitset<8>("11111000");
    bitset<8> trailmask = bitset<8>("10000000");

    bitset<8> headForSingle = bitset<8>("00000000");
    bitset<8> headForDouble = bitset<8>("11000000");
    bitset<8> headForTriple = bitset<8>("11100000");
    bitset<8> headForQuadruple = bitset<8>("11110000");
    bitset<8> headForTrailing = bitset<8>("10000000");

    int idx = 0;
    while (idx < data.size()) {
      if (data[idx] > (1 << 8) - 1) {
        return false;
      }

      bitset<8> current = bitset<8>(data[idx]);
      if ((current & singlebyte) == 0) {
        // 1byte
        idx++;
        continue;
      }
      if ((current & doublebyte) == headForDouble) {
        // 2byte
        if (idx + 1 < data.size() &&
            (bitset<8>(data[idx + 1]) & trailmask) == headForTrailing) {
          idx += 2;
          continue;
        } else {
          return false;
        }
      }
      if ((current & triplebyte) == headForTriple) {
        // 3byte
        if (idx + 2 < data.size() &&
            ((bitset<8>(data[idx + 1]) & trailmask) == headForTrailing) &&
            ((bitset<8>(data[idx + 2]) & trailmask) == headForTrailing)) {
          idx += 3;
          continue;
        } else {
          return false;
        }
      }
      if ((current & quadruplebyte) == headForQuadruple) {
        // 3byte
        if (idx + 3 < data.size() &&
            ((bitset<8>(data[idx + 1]) & trailmask) == headForTrailing) &&
            ((bitset<8>(data[idx + 2]) & trailmask) == headForTrailing) &&
            ((bitset<8>(data[idx + 3]) & trailmask) == headForTrailing)) {
          idx += 4;
          continue;
        } else {
          return false;
        }
      }
      return false;
    }
    return true;
  }
};

int main() {
  Solution s = Solution();
  // auto nums = vector<int>{197, 130, 1};
  // auto nums = vector<int>{235, 140, 4};
  auto nums = vector<int>{255};
  cout << s.validUtf8(nums) << endl;

  // sizeof: *byte*を返す
  cout << "size of bitset<1>: " << sizeof(bitset<1>) << endl;
  cout << "size of bitset<2>: " << sizeof(bitset<2>) << endl;
  cout << "size of bitset<3>: " << sizeof(bitset<3>) << endl;
  cout << "size of bitset<4>: " << sizeof(bitset<4>) << endl;
  cout << "size of bitset<5>: " << sizeof(bitset<5>) << endl;
  cout << "size of bitset<6>: " << sizeof(bitset<6>) << endl;
  cout << "size of bitset<7>: " << sizeof(bitset<7>) << endl;
  cout << "size of bitset<8>: " << sizeof(bitset<8>) << endl;
  cout << "size of bitset<16>: " << sizeof(bitset<16>) << endl;
  cout << "size of bitset<32>: " << sizeof(bitset<32>) << endl;
  cout << "size of bitset<64>: " << sizeof(bitset<64>) << endl;    // 8
  cout << "size of bitset<65>: " << sizeof(bitset<65>) << endl;    // 16
  cout << "size of bitset<128>: " << sizeof(bitset<128>) << endl;  // 16
  cout << "size of bitset<129>: " << sizeof(bitset<129>) << endl;  // 24
}