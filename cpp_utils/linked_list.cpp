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
    // 双方向
    list<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    lst.push_back(4);
    lst.push_front(-1);
    lst.push_front(-2);
    lst.push_front(-3);

    auto itr = lst.begin();
    itr++;
    itr++;
    lst.insert(itr, 100);

    for (auto n : lst)
    {
        cout << n << endl;
    }

    lst.pop_back();
    lst.pop_front();
    lst.erase(itr);

    for (auto n : lst)
    {
        cout << n << endl;
    }
}