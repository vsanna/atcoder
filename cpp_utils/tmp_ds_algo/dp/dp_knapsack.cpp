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

    // maxV = 1000
    vector<vector<ll>> dp = vector<vector<ll>>(N + 1, vector<ll>(W + 1, 0));

    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (j == 0)
            {
                continue;
            }
            chmax(dp[i][j], dp[i - 1][j]);

            // i番目を用いて重さjを実現できる場合
            if (ws[i] <= j)
            {
                // NOTE: なぜdp[i-1][j-ws[i]]ではなく
                // dp[i][j-ws[i]]をベースにするのか
                // -> 同じ商品を複数選択できる状態なので、i番目を加えられる時点ではすでに一回以上iを加えている可能性がある
                // chmax(dp[i][j], dp[i][j - ws[i]] + vs[i]);

                // 本文は一つの商品を一度しか選択できないのでdp[i-1]をベースにする
                chmax(dp[i][j], dp[i - 1][j - ws[i]] + vs[i]);
            }
        }
    }

    // for (auto row : dp)
    // {
    //     for (auto cell : row)
    //     {
    //         cout << cell << " ";
    //     }
    //     cout << endl;
    // }
    cout << dp[N][W] << endl;
}