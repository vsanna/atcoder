#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>

using namespace std;

void reverse(string &stones, int &cnt, char currentTurn)
{
	// string other = (currentTurn == 'W') ? "B" : "W";

	if (stones[0] == currentTurn)
	{
		for (auto itr = stones.rbegin(); itr != stones.rend(); itr++)
		{
			if (*itr == currentTurn)
			{
				break;
			}
			else
			{
				*itr = currentTurn;
			}
		}
		stones = stones + string{currentTurn};
		cnt++;
	}
	else
	{
		for (auto itr = stones.begin(); itr != stones.end(); itr++)
		{
			if (*itr == currentTurn)
			{
				break;
			}
			else
			{
				*itr = currentTurn;
			}
		}
		stones = string{currentTurn} + stones;
		cnt++;
	}
}

bool hasFinished(string const &stones)
{
	return find(stones.begin(), stones.end(), 'W') == stones.end() || find(stones.begin(), stones.end(), 'B') == stones.end();
}

int main()
{
	// string stones;
	// cin >> stones;

	// int cnt = 0;

	// char currentTurn = '-';

	// while (true)
	// {
	// 	if (hasFinished(stones))
	// 	{
	// 		break;
	// 	}

	// 	if (currentTurn == '-')
	// 	{
	// 		if (stones[0] == 'W' && stones[stones.length() - 1] == 'W')
	// 		{
	// 			currentTurn = 'B';
	// 		}
	// 		else
	// 		{
	// 			currentTurn = 'W';
	// 		}
	// 	}

	// 	reverse(stones, cnt, currentTurn);
	// 	currentTurn = (currentTurn == 'W') ? 'B' : 'W';
	// }

	// cout << cnt << endl;

	string stones;
	cin >> stones;
	char current;
	int cnt = 0;

	for (auto itr = stones.begin(); itr != stones.end(); itr++)
	{
		if (itr == stones.begin())
		{
			current = *itr;
		}
		else
		{
			if (current != *itr)
			{
				cnt++;
				current = *itr;
			}
		}
	}

	cout << cnt << endl;
}