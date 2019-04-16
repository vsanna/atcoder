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
ostream &operator<<(ostream &os, const vector<vector<T>> &vec)
{
	os << "[" << endl;

	for (int i = 0; i < vec.size(); i++)
	{
		os << "  [";
		for (int j = 0; j < vec[i].size(); j++)
		{
			os << vec[i][j];
			if (j + 1 != vec[i].size())
				os << ", ";
		}
		os << "]" << endl;
	}
	os << "]" << endl;
}

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &vec)
{
	cout << "[";
	for (auto itr = vec.begin(); itr != vec.end(); itr++)
	{
		cout << *itr;
		if (itr + 1 != vec.end())
			cout << ", ";
	}

	cout << "]" << endl;
}

template <typename T>
void ap(const T val)
{
	cout << val << endl;
}

int main()
{
	string msg = "hello";
	ap(msg);

	vector<int> hoge{1, 2, 3, 4, 5};

	ap(hoge);

	// vector<vector<int>> hoge2{
	// 	{1, 2, 3, 4},
	// 	{5, 6, 7, 8},
	// 	{9, 10, 11, 12}};

	// ap(hoge2);

	// vector<vector<vector<int>>> hoge3{
	// 	{{1, 2, 3, 4},
	// 	 {5, 6, 7, 8},
	// 	 {9, 10, 11, 12}},
	// 	{{1, 2, 3, 4},
	// 	 {5, 6, 7, 8},
	// 	 {9, 10, 11, 12}}};
	// debug::debug(hoge3);
}