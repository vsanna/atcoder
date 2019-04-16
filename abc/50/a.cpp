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
	int a, b;
	string op;
	cin >> a >> op >> b;
	if (op == "-")
	{
		cout << (a - b) << endl;
	}
	else
	{
		cout << (a + b) << endl;
	}
}