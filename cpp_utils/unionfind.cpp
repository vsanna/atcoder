#include <unordered_map>
#include <vector>
#include <iostream>

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
			std::cout << kv.first << " => " << kv.second << std::endl;
		}
	}

	void print()
	{
		for (auto kv : parents)
		{
			if (kv.second < 0)
			{
				std::cout << kv.first << "(" << -size(kv.first) << ") => ";
				for (auto node : parents)
				{
					if (node.second == kv.first || node.first == kv.first)
					{
						std::cout << node.first << " ";
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