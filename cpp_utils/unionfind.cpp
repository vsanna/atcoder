#include <unordered_map>
#include <vector>
#include <iostream>
#include <vector>

template <typename T>
class UnionFind
{
	std::vector<T> parents;
	T uf_size;

  public:
	UnionFind(std::vector<T> nodes)
	{
		uf_size = *std::max_element(nodes.begin(), nodes.end());
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

	bool isConnected(T a, T b)
	{
		return root(a) == root(b);
	}

	void connect(T a, T b)
	{
		T root_a = root(a);
		T root_b = root(b);

		if (root_a == root_b)
			return;

		if (parents[root_a] < parents[root_b])
			std::swap(root_a, root_b);

		parents[root_a] += parents[root_b];
		parents[root_b] = root_a;

		return;
	}

	T size(T node)
	{
		shallow(node);
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

	void shallowAll()
	{
		for (int i = 1; i <= uf_size; i++)
		{
			shallow(i);
		}
	}

	void printRow()
	{
		shallowAll();
		for (int i = 1; i <= uf_size; i++)
		{
			std::cout << i << " => " << parents[i] << std::endl;
		}
	}

	void print()
	{
		shallowAll();
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

int main()
{
	std::vector<int> nodes{1, 2, 3, 4, 5, 6};
	UnionFind<int> uf = UnionFind<int>(nodes);
	uf.connect(1, 2);
	uf.print();
	uf.connect(3, 4);
	uf.print();
	uf.connect(1, 3);
	uf.print();

	std::cout << "====" << std::endl;
	UnionFind<int> uf2 = UnionFind<int>(3);
	uf2.print();
}