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

using namespace std;

using ll = long long;

int on(int bits, int pos)
{
	int mask = 1 << pos;
	return bits | mask;
}

int off(int const bits, int const pos)
{
	int mask = ~(1 << pos);
	return bits & mask;
}

int toggle(int const bits, int const pos)
{
	int mask = 1 << pos;
	return bits ^ mask;
}

bool isSet(int const bits, int const pos)
{
	int mask = 1 << pos;
	return (bits & mask) > 0; // 指定したposが1なら1以上
}

// 最下位ビット
int lsb(int bits)
{
	return (bits & 1);
}

bool allUnset(int const bits)
{
	return bits == 0;
}

bool allSet(int bits)
{
	if (bits == 0)
		return false;

	while (bits > 0)
	{
		if (lsb(bits) == 0)
			return false;

		bits = bits >> 1;
	}

	return true;
}

int countSetBit(int bits)
{
	int cnt = 0;
	while (bits > 0)
	{
		if (lsb(bits) == 1)
			cnt++;

		bits = bits >> 1;
	}
	return cnt;
}

/*
一番右にセットされている1をoffにする
*/
bool offRightMostSetBit(int bits)
{
	return bits & (bits - 1);
}

int rightPostSetBitPosition(int bits)
{
	int pos = -1;
	while (bits > 0)
	{
		if (lsb(bits) == 1)
			return pos + 1;
		pos++;
		bits = bits >> 1;
	}

	return pos;
}

/*
[0..len-1]までのbit dfsを作る

  vector<int> bits;
  dfs(bits, 0, 0, 5); [0, 1, 2, 3, .. 31]
*/

void dfs(vector<int> &bits, int current, int currentlen, int const maxlen)
{
	if (currentlen == maxlen)
	{
		bits.push_back(current);
		return;
	}

	dfs(bits, current << 1, currentlen + 1, maxlen);
	dfs(bits, on(current << 1, 0), currentlen + 1, maxlen);
}

/*
{0, 1, ..., n-1}の部分集合
*/
vector<vector<int>> allSubgroup(int n)
{
	vector<vector<int>> groups;

	// {0, 1, ..., n-1} の部分集合の全探索
	for (int bit = 0; bit < (1 << n); ++bit)
	{
		vector<int> group;
		for (int i = 0; i < n; ++i)
		{
			if (bit & (1 << i))
			{ // i が bit に入るかどうか
				group.push_back(i);
			}
		}
		groups.push_back(group);
	}

	return groups;
}

int main()
{
	vector<int> bits;
	dfs(bits, 0, 0, 5);
	for (auto n : bits)
	{
		cout << bitset<8>(n) << endl;
	}

	vector<vector<int>> all = allSubgroup(5);
	for (int i = 0; i < all.size(); i++)
	{
		cout << i << ": ";
		for (int j = 0; j < all[i].size(); j++)
		{
			cout << all[i][j] << " ";
		}
		cout << endl;
	}

	for (int i = 0; i <= 8; i++)
	{
		cout << bitset<8>(i) << ":" << (allSet(i) ? "ALLSET" : "NOT ALLSET") << endl;
	}

	for (int i = 0; i <= 8; i++)
	{
		cout << "bit count: " << bitset<8>(i) << ":" << countSetBit(i) << endl;
	}

	for (int i = 0; i <= 16; i++)
	{
		cout << "rightPostSetBitPosition: " << bitset<8>(i) << ":" << rightPostSetBitPosition(i) << endl;
	}
}