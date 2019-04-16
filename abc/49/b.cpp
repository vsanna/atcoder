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

using namespace std;

int main()
{
	int h, w;
	cin >> h >> w;
	for (int i = 0; i < h; i++)
	{
		vector<char> symbols(w);
		for (int j = 0; j < w; j++)
		{
			cin >> symbols[j];
		}
		for (int j = 0; j < w; j++)
		{
			cout << symbols[j];
		}
		cout << endl;
		for (int j = 0; j < w; j++)
		{
			cout << symbols[j];
		}
		cout << endl;
	}
}