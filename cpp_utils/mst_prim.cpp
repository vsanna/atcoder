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

template <typename T>
class UnionFind
{
	std::unordered_map<T, T> parents;

  public:
	UnionFind(std::vector<T> nodes)
	{
		for (T node : nodes)
		{
			parents[node] = -1;
		}
	}
	UnionFind(T size)
	{
		std::vector<int> nodes;
		for (int i = 1; i <= size; i++)
		{
			parents[i] = -1;
		}
	}

	T root(T node)
	{
		T p = parents[node];
		if (p < 0)
		{
			return node;
		}
		else
		{
			return root(p);
		}
	}

	bool isConnected(T a, T b)
	{
		T root_of_a = root(a);
		T root_of_b = root(b);
		shallow(a);
		shallow(b);
		return root_of_a == root_of_b;
	}

	void connect(T a, T b)
	{
		if (isConnected(a, b))
			return;

		T root_a = root(a);
		T root_b = root(b);

		parents[root_a] += parents[root_b];
		parents[root_b] = root_a;
		for (auto kv : parents)
		{
			if (kv.second == root_b)
			{
				parents[kv.first] = root_a;
			}
		}
	}

	T size(T node)
	{
		return parents[root(node)];
	}

	void shallow(T node)
	{
		if (parents[node] < 0)
			return;

		T root_node = root(node);
		if (root_node != parents[node])
		{
			T current = node;
			while (current != root_node)
			{
				T parent = parents[current];
				parents[current] = root_node;
				current = parent;
			}
		}
	}

	void printRow()
	{
		for (auto kv : parents)
		{
			cout << kv.first << " => " << kv.second << endl;
		}
	}

	void print()
	{
		for (auto kv : parents)
		{
			if (kv.second < 0)
			{
				cout << kv.first << "(" << -size(kv.first) << ") => ";
				for (auto node : parents)
				{
					if (node.second == kv.first || node.first == kv.first)
					{
						cout << node.first << " ";
					}
				}
				cout << endl;
			}
		}
	}
};

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

// 最小コストの辺から見ていってconnectするなら加える、そうでないなら捨てる
int main()
{
	int n, m;
	cin >> n >> m;

	UnionFind<int> uf = UnionFind<int>(n);

	int used = 0;

	priority_queue<edge, vector<edge>, greater<edge>> edges;

	for (int i = 1; i <= m; i++)
	{
		edge e;
		cin >> e.from >> e.to >> e.cost;
		edges.push(e);
	}

	while (!edges.empty())
	{
		if (!uf.isConnected(edges.top().to, edges.top().from))
		{
			uf.connect(edges.top().from, edges.top().to);
			used++;
		}
		uf.print();
		cout << "======" << endl;
		edges.pop();
	}

	cout << (m - used) << endl;
}