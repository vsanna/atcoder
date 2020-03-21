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
  vector<double> sampleStats(vector<int> &count) {
    return vector<double>{min(count), max(count), mean(count), mediam(count),
                          mode(count)};
  }

  double min(vector<int> &count) {
    double result = 0.0;
    for (int i = 0; i < count.size(); i++) {
      if (count[i] != 0) {
        result = (double)i;
        break;
      }
    }
    return result;
  }

  double max(vector<int> &count) {
    double result = 0.0;
    for (int i = count.size() - 1; i >= 0; i--) {
      if (count[i] != 0) {
        result = (double)i;
        break;
      }
    }
    return result;
  }

  double mean(vector<int> &count) {
    double result = 0.0;
    ll sum = 0;
    ll freqSum = 0;
    for (int i = 0; i < count.size(); i++) {
      sum += count[i] * i;
      freqSum += count[i];
    }
    return sum / (double)freqSum;
  }

  double mediam(vector<int> &count) {
    double result = 0.0;

    vector<ll> freqSums = vector<ll>(count.size());
    freqSums[0] = count[0];
    for (int i = 1; i < count.size(); i++) {
      freqSums[i] = freqSums[i - 1] + count[i];
    }
    ll totalFreq = freqSums[freqSums.size() - 1];
    ll mediumFreq = totalFreq / 2;
    for (int i = 1; i < count.size(); i++) {
      if (freqSums[i] == mediumFreq) {
        // 偶数のケース
        // 次に登場する値との平均
        for (int j = i + 1; j < count.size(); j++) {
          if (freqSums[i] < freqSums[j]) {
            result = (double)((i + j) / 2.0);
            goto end;
          }
        }
      } else if (freqSums[i] > mediumFreq) {
        // 奇数のケース
        result = (double)i;
        goto end;
      }
    }

  end:;
    return result;
  }

  double mode(vector<int> &count) {
    ll maxFreq = -1;
    ll maxFreqIdx = -1;
    for (int i = 0; i < count.size(); i++) {
      if (count[i] > maxFreq) {
        maxFreq = count[i];
        maxFreqIdx = i;
      }
    }
    return (double)maxFreqIdx;
  }
};

int main() {
  Solution s = Solution();
  auto nums1 = vector<int>{
      0, 1, 3, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  auto nums2 = vector<int>{
      0, 4, 3, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  // auto nums = vector<int>{1, 2147483647};
  // auto nums = vector<int>{1, 2147483647};
  vector<double> result = s.sampleStats(nums2);
  for (int i = 0; i < result.size(); i++) {
    cout << result[i] << ", ";
  }
  cout << endl;
}