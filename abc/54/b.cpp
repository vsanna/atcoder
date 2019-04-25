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
#include <functional>

using namespace std;

using ll = long long;

template <typename T>
inline bool chmax(T &a, T b)
{
	if (a < b)
	{
		a = b;
		return 1;
	}
	return 0;
}

int main()
{
	int n, m;
	cin >> n >> m;


	vector<vector<ll>> a_hash_map;

	ll b_hash;
	string b_image;

	vector<string> a_image;

	for (int i = 0; i < n; i++)
	{
		string line;
		cin >> line;
		a_image.push_back(line);
		
		for (int j = 0; j < n - m; j++)
		{

		}
	}

	for (int i = 0; i < m; i++)
	{
		string line;
		cin >> line;
		auto h = hash<string>()(line);
		for (int j = 0; j < n - m; j++)
		{
			if(hash_map[i][j] == h){
				for (int k = 0; k < n; k++)
				{
					if (hash_map[i][j] == h)
					{
					}
				}
			}
		}
	}
}