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
#include <limits>
#include <list>

using namespace std;
using ll = long long;
const ll INF = numeric_limits<ll>::max();
const int MOD = 1000000007;

int main()
{
    // binary search
    vector<int> nums = {1, 3, 9, 12, 21, 100, 130, 211};

    for (int i = 0; i < 220; i++)
    {
        if (binary_search(nums.begin(), nums.end(), i))
        {
            cout << i << ":"
                 << "foud" << endl;
        }
        else
        {
            cout << i << ":"
                 << "not foud" << endl;
        }
    }

    for (int i = 0; i < 220; i++)
    {
        // i"以上"の値を見つける. つまり、下限iの左端posを探す
        auto itr = lower_bound(nums.begin(), nums.end(), i);
        if (itr != nums.end())
        {
            cout << i << ": pos: " << distance(nums.begin(), itr) << endl;
        }
        else
        {
            cout << i << ": not found" << endl;
        }
    }

    for (int i = 0; i < 220; i++)
    {
        // i"以下"の値を見つける. つまり、上限iの右端posを探す
        auto itr = upper_bound(nums.begin(), nums.end(), i);
        if (itr != nums.end())
        {
            cout << i << ": pos: " << distance(nums.begin(), itr) << endl;
        }
        else
        {
            cout << i << ": not found" << endl;
        }
    }
}