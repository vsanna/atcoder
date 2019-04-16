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

struct edge
{
	int from;
	int to;
	int cost;
};

bool operator<(const edge &a, const edge &b)
{
	return a.cost < b.cost;
}
bool operator>(const edge &a, const edge &b)
{
	return !(a < b);
}

// 最短経路をたどり、使ったedgeを記録する
void traverse(unordered_map<edge, bool> &used, vector<edge> edges, int from, int to)
{
	
}

int main()
{
	int n, m;
	cin >> n >> m;

	priority_queue<edge, vector<edge>, greater<edge>> edges;
	unordered_map<edge, bool> used;

	for (int i = 1; i <= m; i++)
	{
		edge e;
		int to, from, cost;
		cin >> from >> to >> cost;
		edges.emplace(from, to, cost);
		used[edges.top()] = false;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			traverse(used, edges, i, j);
		}
	}
}