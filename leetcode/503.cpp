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

class Solution {
 public:
  vector<int> nextGreaterElements(vector<int> &nums) {
    if(nums.size() == 0) return vector<int>{};

    
    ll max = -INF;
    int maxpos = -1;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] >= max) {
        chmax(max, nums[i]);
        maxpos = i;
      }
    }

    vector<int> rotated{};
    for (int i = maxpos + 1; i < nums.size(); i++) {
      rotated.push_back(nums[i]);
    }
    for (int i = 0; i <= maxpos; i++) {
      rotated.push_back(nums[i]);
    }

    vector<int> nge = vector<int>(nums.size(), 0);
    // pos, val
    stack<pair<int, int>> st;
    for (int i = rotated.size() - 1; i >= 0; i--) {
      while (st.size() > 0 && st.top().second <= rotated[i]) {
        st.pop();
      }
      if (st.size() == 0) {
        nge[i] = -1;
        st.push(make_pair(i, rotated[i]));
      } else {
        nge[i] = st.top().second;
        st.push(make_pair(i, rotated[i]));
      }
    }

    vector<int> ans{};
    for (int i = nums.size() - maxpos - 1; i < nums.size(); i++) {
      ans.push_back(nge[i]);
    }
    for (int i = 0; i < nums.size() - maxpos - 1; i++) {
      ans.push_back(nge[i]);
    }
    return ans;
  }
};

int main() {
  Solution s = Solution();
  vector<int> nums = vector<int>{1, 2, 3, 1};
  dumpvec(s.nextGreaterElements(nums));
  nums = vector<int>{4, 2, 5, 7, 0, 2, 9, 7, 3};
  dumpvec(s.nextGreaterElements(nums));
}