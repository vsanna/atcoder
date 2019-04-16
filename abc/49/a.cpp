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
	char c;
	cin >> c;
	vector<char> vowels{'a', 'e', 'i', 'u', 'o'};

	auto itr = find(vowels.begin(), vowels.end(), c);
	if (itr != vowels.end())
	{
		cout << "vowel" << endl;
	}
	else
	{
		cout << "consonant" << endl;
	}
}