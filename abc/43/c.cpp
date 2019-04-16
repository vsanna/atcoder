#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <cmath>
#include <math.h>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> as(n);
	int sum = 0;
	for(int i = 0; i < n; i++) {
		cin >> as[i];
		sum += as[i];
	}
	double avg = double(sum) / double(as.size());
	int rounded_avg = round(avg);

	int cost = 0;
	for(int i = 0; i < n; i++) {
		cost += pow((as[i] - rounded_avg), 2);
	}

	cout << cost << endl;
}