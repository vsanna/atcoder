#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

using ll = long long;

int ctoi(char c)
{
	if (c >= '0' && c <= '9')
	{
		return c - '0';
	}
	return 0;
}

void dfs(string num, ll &sum, ll currentSum, ll prev, int pos, int len)
{
	if (pos == len)
	{
		currentSum += prev;
		sum += currentSum;
		return;
	}

	// refreshする
	if (prev != 0)
	{
		dfs(num, sum, currentSum + prev, ctoi(num[pos]), pos + 1, len);
	}

	// refreshしない
	dfs(num, sum, currentSum, prev * 10 + ctoi(num[pos]), pos + 1, len);
}

int main()
{
	string s;
	cin >> s;

	ll ans = 0;
	dfs(s, ans, 0, 0, 0, s.length());
	cout << ans << endl;
}