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

void chmin(ll &a, ll b)
{
    if (a > b)
    {
        a = b;
    }
}
void chmax(ll &a, ll b)
{
    if (a < b)
    {
        a = b;
    }
}

int main()
{
    ll N;
    cin >> N;
    vector<ll> heights = vector<ll>(N);
    for (int i = 0; i < N; i++)
    {
        ll h;
        cin >> h;
        heights[i] = h;
    }

    vector<ll> dp = vector<ll>(N, INF);
    dp[0] = 0;

    for (int i = 0; i < N; i++)
    {
        chmin(dp[i], dp[i - 1] + abs(heights[i] - heights[i - 1]));
        if (i > 1)
        {
            chmin(dp[i], dp[i - 2] + abs(heights[i] - heights[i - 2]));
        }
    }
    cout << dp[N - 1] << endl;
}