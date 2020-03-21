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
    vector<ll> as = vector<ll>(N);
    vector<ll> bs = vector<ll>(N);
    vector<ll> cs = vector<ll>(N);
    for (int i = 0; i < N; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        as[i] = a;
        bs[i] = b;
        cs[i] = c;
    }

    vector<vector<ll>> dp = vector<vector<ll>>(N, vector<ll>(3, -INF));
    dp[0][0] = as[0];
    dp[0][1] = bs[0];
    dp[0][2] = cs[0];

    for (int i = 1; i < N; i++)
    {
        dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]) + as[i];
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + bs[i];
        dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + cs[i];
    }
    ll maxV = dp[N - 1][0];
    chmax(maxV, dp[N - 1][1]);
    chmax(maxV, dp[N - 1][2]);
    cout << maxV << endl;
}