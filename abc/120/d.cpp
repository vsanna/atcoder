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
	std::vector<T> parents;
	T uf_size;

  public:
	UnionFind(std::vector<T> nodes)
	{
		uf_size = max(nodes);
		parents = std::vector<T>(uf_size + 1, -1);
		parents[0] = 0; // 0は使わない
	}

	UnionFind(T s)
	{
		uf_size = s;
		parents = std::vector<T>(uf_size + 1, -1);
		parents[0] = 0; // 0は使わない
	}

	T root(T node)
	{
		T p = parents[node];
		return (p < 0) ? node : root(p);
	}

	// O(1)
	bool isConnected(T a, T b)
	{
		T root_of_a = root(a);
		T root_of_b = root(b);
		return root_of_a == root_of_b;
	}

	// O(1)
	void connect(T a, T b)
	{
		T root_a = root(a);
		T root_b = root(b);

		if (root_a == root_b)
			return;

		if (parents[root_a] < parents[root_b])
			swap(root_a, root_b);

		parents[root_a] += parents[root_b];
		parents[root_b] = root_a;
	}

	// O(1)
	T size(T node)
	{
		shallow(node);
		return -parents[root(node)];
	}

	// O(N)
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
		for (int i = 1; i <= uf_size; i++)
		{
			std::cout << i << " => " << parents[i] << std::endl;
		}
	}

	void print()
	{
		for (int i = 1; i <= uf_size; i++)
		{
			if (parents[i] < 0)
			{
				std::cout << i << "(" << -size(i) << ") => ";
				for (int j = 1; j <= uf_size; j++)
				{
					if (parents[j] == i || i == j)
					{
						std::cout << j << " ";
					}
				}
				std::cout << std::endl;
			}
		}
	}
};

struct bridge
{
	int from;
	int to;
};

int main()
{
	ll n, m;
	cin >> n >> m;

	// O(N)
	UnionFind<ll> uf = UnionFind<ll>(n);

	vector<bridge> bridges(m);

	//O(M)
	for (int i = 0; i < m; i++)
	{
		bridge b;
		cin >> b.from >> b.to;
		bridges[i] = b;
	}

	vector<ll> inconvinience_scores(m + 1, 0); // i本の橋があるときの不便さ
	ll current_score = n * (n - 1) / 2;
	inconvinience_scores[0] = current_score;

	// O(M)
	for (int i = 0; i < m; i++)
	{
		bridge b = bridges[m - 1 - i];

		// O(1)
		if (!uf.isConnected(b.from, b.to))
		{
			current_score = current_score - (uf.size(b.from) * uf.size(b.to));
			uf.connect(b.from, b.to);
		}

		if (current_score == 0)
			break;

		inconvinience_scores[i + 1] = current_score;
	}

	for (auto itr = inconvinience_scores.rbegin() + 1; itr != inconvinience_scores.rend(); itr++)
	{
		cout << *itr << endl;
	}
}