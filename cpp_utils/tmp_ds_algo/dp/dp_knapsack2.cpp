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
    // max of value = 1000
    // max of n = 100
    // Thus, max of total value = 10^5
    ll datalen = 100000;
    ll N, W;
    cin >> N >> W;
    vector<ll> ws = vector<ll>(N + 1);
    vector<ll> vs = vector<ll>(N + 1);
    for (int i = 1; i <= N; i++)
    {
        ll w, v;
        cin >> w >> v;
        ws[i] = w;
        vs[i] = v;
    }

    vector<vector<ll>> dp = vector<vector<ll>>(N + 1, vector<ll>(datalen + 1, INF));
    // dp[0][0] = 0;
    for (int i = 0; i <= N; i++)
    {
        dp[i][0] = 0;
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j <= datalen; j++)
        {

            ll minV = INF;
            chmin(minV, dp[i - 1][j]); // i番目を利用しない
            if (vs[i] <= j)
            {
                // dp[i - 1][j - vs[i]] == INFのときに加算するとオーバーフローする
                if (dp[i - 1][j - vs[i]] <= INF - ws[i])
                {
                    chmin(minV, dp[i - 1][j - vs[i]] + ws[i]); // i番目を利用する
                }
                else
                {
                    dp[i][j] = INF;
                }
            }
            dp[i][j] = minV;
        }
    }

    ll maxV = -INF;
    for (int i = 0; i <= datalen; i++)
    {
        if (dp[N][i] <= W)
        {
            chmax(maxV, i);
        }
    }

    // int i = 0;
    // for (auto row : dp)
    // {
    //     int j = 0;
    //     for (auto cell : row)
    //     {
    //         cout << cell << "(" << i << "," << j << ")"
    //              << " ";
    //         j++;
    //     }
    //     cout << endl;
    //     cout << "===" << endl;
    //     i++;
    // }
    cout << maxV << endl;
}