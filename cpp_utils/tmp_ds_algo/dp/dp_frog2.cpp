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
    ll K;
    cin >> N >> K;
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
        for (int j = 1; j <= K; j++)
        {
            if (i - j >= 0)
            {
                chmin(dp[i], dp[i - j] + abs(heights[i] - heights[i - j]));
            }
        }
    }
    cout << dp[N - 1] << endl;
}