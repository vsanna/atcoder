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

using namespace std;

using ll = long long;

struct shop
{
	ll stock;
	ll price;
};

bool operator<(const shop &a, const shop &b)
{
	return a.price < b.price;
}
bool operator>(const shop &a, const shop &b)
{
	return !(a < b);
}

int main()
{
	int n, m;
	cin >> n >> m;

	priority_queue<shop, vector<shop>, greater<shop>> pq;

	for (int i = 1; i <= n; i++)
	{
		shop obj;
		cin >> obj.price >> obj.stock;
		pq.push(obj);
	}

	ll current = 0;
	ll cost = 0;

	while (!pq.empty())
	{
		if (m - current >= pq.top().stock)
		{
			// 全購入
			cost += (pq.top().stock * pq.top().price);
			current += pq.top().stock;
		}
		else
		{
			// 残り分購入
			cost += (pq.top().price * (m - current));
			current += (m - current);
		}

		if (current == m)
			break;

		pq.pop();
	}

	// M本に至るまで安いところから買い漁る

	cout << cost << endl;
}