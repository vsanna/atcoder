#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int a, b, c;
	cin >> a >> b >> c;

	if (a == b + c || b == a + c || c == a + b)
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}
}