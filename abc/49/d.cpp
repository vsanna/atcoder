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
#include <sstream>

using namespace std;

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

int main()
{
	int n, k, l;
	cin >> n >> k >> l;

	vector<int> cities;
	// O(N)
	for (int i = 1; i <= n; i++)
	{
		cities.push_back(i);
	}

	UnionFind<int> roads = UnionFind<int>(cities);
	UnionFind<int> trains = UnionFind<int>(cities);

	// O(K)
	for (int i = 0; i < k; i++)
	{
		int a, b;
		cin >> a >> b;
		roads.connect(a, b);
	}

	// O(L)
	for (int i = 0; i < l; i++)
	{
		int a, b;
		cin >> a >> b;
		trains.connect(a, b);
	}

	// roads.print();
	// cout << "=====" << endl;
	// trains.print();

	unordered_map<int, unordered_map<int, int>> freq;
	for (int i = 1; i <= n; i++)
	{
		freq[roads.root(i)][trains.root(i)] = freq[roads.root(i)][trains.root(i)] + 1;
	}
	for (int i = 1; i <= n; i++)
	{
		cout << freq[roads.root(i)][trains.root(i)] << " ";
	}
	cout << endl;
}