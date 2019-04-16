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
#include <tuple>

using namespace std;

using ll = long long;

struct edge
{
	int from;
	int to;
	int cost;

	edge(int f, int t, int c)
	{
		from = f;
		to = t;
		cost = c;
	}

	bool operator<(const edge &other) const
	{
		return cost < other.cost;
	}
	bool operator>(const edge &other) const
	{
		return !(*this < other);
	}
};

struct Graph
{
	std::unordered_map<int, std::unordered_map<int, int>> am; // adjancency_matrix
	int size;

	Graph(int s)
	{
		size = s;
		for (int n = 1; n <= size; n++)
		{
			for (int m = 1; m <= size; m++)
			{
				am[n][m] = -1;
			}
		}
	}

	void addEdge(edge e)
	{
		am[e.from][e.to] = e.cost;
		am[e.to][e.from] = e.cost;
	}

	void removeEdge(edge e)
	{
		am[e.from].erase(e.to);
		am[e.to].erase(e.from);
	}

	void addNode() {}
	void removeNode() {}

	// distance, pathを返す.
	std::tuple<ll, std::vector<int>> dijkstra(int from, int to)
	{
		if (to == from)
		{
			return std::forward_as_tuple(0, vector<int>{to});
		}

		std::unordered_map<int, bool> visited;
		std::unordered_map<int, int> previous;
		std::unordered_map<int, int> distance;
		std::priority_queue<int> queue;

		for (int i = 1; i < size; i++)
		{
			visited[i] = false;
			previous[i] = -1;
			distance[i] = -1;
		}

		previous[from] = -1;
		distance[from] = 0;
		queue.push(from);

		while (!queue.empty())
		{
			int current = queue.top();
			queue.pop();

			if (current == to)
				break;
			if (visited[current])
				continue;

			visited[current] = true;

			for (auto to_cost : am[current])
			{
				int to = to_cost.first;
				int cost = to_cost.second;
				if (!visited[to])
				{
					if (distance[to] > distance[current] + am[current][to])
					{
						previous[to] = current;
						distance[to] = distance[current] + am[current][to];
					}
					queue.push(to);
				}
			}
		}

		if (previous[to] == -1)
		{
			return std::forward_as_tuple(-1, vector<int>{});
		}

		std::vector<int> path;
		int tmp = to;
		while (true)
		{
			if (previous[tmp] == -1)
				break;
			path.push_back(tmp);
			tmp = previous[tmp];
		}

		reverse(path.begin(), path.end());

		return std::forward_as_tuple(distance[to], path);
	}

	void dfs(int from)
	{
	}

	void bfs(int from)
	{
	}

	// debug
	void print()
	{
		for (auto from_tos : am)
		{
			std::cout << from_tos.first << " => ";
			for (auto to_cost : from_tos.second)
			{
				std::cout << to_cost.first << "(" << to_cost.second << "), ";
			}
			std::cout << std::endl;
		}
	}
};

int main()
{

	Graph g(6);

	std::vector<edge> edges;
	edges.push_back(edge(1, 2, 4));
	edges.push_back(edge(2, 5, 1));
	edges.push_back(edge(5, 4, 7));
	edges.push_back(edge(5, 3, 9));
	edges.push_back(edge(5, 6, 3));

	for (int i = 0; i < edges.size(); i++)
	{
		cout << edges[i].from << ":" << edges[i].to << ":" << edges[i].cost << endl;
		g.addEdge(edges[i]);
	}

	g.print();

	auto result = g.dijkstra(5, 3);

	std::cout << std::get<0>(result) << std::endl;
}