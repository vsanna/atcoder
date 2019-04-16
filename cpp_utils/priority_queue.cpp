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

struct node
{
	int priority;
	string value;

	// TODO: class内に置きたい
	// bool operator<(const node &other) const
	// {
	// 	return priority < other.priority;
	// }
	// bool operator>(const node &other) const
	// {
	// 	return priority > other.priority;
	// }
};
bool operator<(const node &n1, const node &n2)
{
	return n1.priority < n2.priority;
}
bool operator>(const node &n1, const node &n2)
{
	return !(n1 < n2);
}

int main()
{

	// default のint並び替え
	priority_queue<int> pq1;
	pq1.push(10);
	pq1.push(1);
	pq1.push(7);
	while (!pq1.empty())
	{
		cout << pq1.top() << endl;
		pq1.pop();
	}

	// オリジナルクラスのpq. operator< を実装しておく
	priority_queue<node> pq2;

	node n1{10, "hoge1"};
	node n2{3, "hoge2"};
	node n3{12, "hoge3"};
	pq2.push(n1);
	pq2.push(n2);
	pq2.push(n3);

	while (!pq2.empty())
	{
		cout << pq2.top().priority << ":" << pq2.top().value << endl;
		pq2.pop();
	}

	priority_queue<node, vector<node>, greater<node>> pq3;
	pq3.push(n1);
	pq3.push(n2);
	pq3.push(n3);

	while (!pq3.empty())
	{
		cout << pq3.top().priority << ":" << pq3.top().value << endl;
		pq3.pop();
	}
}