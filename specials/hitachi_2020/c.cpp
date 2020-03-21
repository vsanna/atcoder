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

int main() {
  int N;
  cin >> N;

  vector<unordered_set<int>> onehop =
      vector<unordered_set<int>>(N + 1, unordered_set<int>());
  vector<unordered_set<int>> twohop =
      vector<unordered_set<int>>(N + 1, unordered_set<int>());
  vector<unordered_set<int>> threehop =
      vector<unordered_set<int>>(N + 1, unordered_set<int>());

  for (int i = 1; i < N; i++) {
    int a, b;
    cin >> a >> b;

    // hop1
    onehop[a].insert(b);

    // hop2
    unordered_set<int> newa;
    set_union(twohop[a].begin(), twohop[a].end(), onehop[b].begin(),
              onehop[b].end(), inserter(newa, newa.begin()));
    twohop[a] = newa;

    // hop3
    unordered_set<int> newa3 = threehop[a];
    for (int n : twohop[a]) {
      unordered_set<int> tmp;
      set_union(newa3.begin(), newa3.end(), onehop[n].begin(), onehop[n].end(),
                inserter(tmp, tmp.begin()));
      newa3 = tmp;
    }

    // hop1
    onehop[b].insert(a);

    // hop2
    unordered_set<int> newb;
    set_union(twohop[b].begin(), twohop[b].end(), onehop[a].begin(),
              onehop[a].end(), inserter(newb, newb.begin()));
    twohop[b] = newb;

    // hop3
    unordered_set<int> newb3 = threehop[b];
    for (int n : twohop[b]) {
      unordered_set<int> tmp;
      set_union(newb3.begin(), newb3.end(), onehop[n].begin(), onehop[n].end(),
                inserter(tmp, tmp.begin()));
      newb3 = tmp;
    }
  }

  for (int i = 1; i <= N; i++) {
    int key = i;
    unordered_set<int> threehopFromHere = threehop[i];
    for (int n : threehopFromHere) {
      if ((key + n) % 3 != 0 || (key * n) % 3 != 0) {
        cout << -1 << endl;
        return 0;
      }
    }
  }
  for (int i = 1; i <= N; i++) {
    cout << i << " ";
  }
  cout << endl;
}