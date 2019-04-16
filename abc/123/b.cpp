#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	int a, b, c, d, e;

	cin >> a >> b >> c >> d >> e;
	vector<int> nums{a, b, c, d, e};

	int min = a;
	int min_digit = a % 10;

	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] % 10 == 0)
			continue;
		if (nums[i] % 10 < min_digit)
		{
			min = nums[i];
			min_digit = nums[i] % 10;
		}
	}

	int result = 0;
	bool used = false;
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] == min && !used)
		{
			result += nums[i];
			used = true;
		}
		else
		{
			if (nums[i] % 10 == 0)
			{
				result += nums[i];
			}
			else
			{
				result += (floor(nums[i] / 10.0) + 1) * 10;
			}
		}
	}

	cout << result << endl;
}