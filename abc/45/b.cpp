#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>

using namespace std;


char judge(string a, string b, string c) {
	int aidx = -1;
	int bidx = -1;
	int cidx = -1;
	char current = 'a';
	while(true) {
		switch(current) {
			case 'a':
				aidx++;
				if(aidx == a.length()) {
					return 'A';
				}
				current = a[aidx];
				break;
			case 'b':
				bidx++;
				if(bidx == b.length()) {
					return 'B';
				}
				current = b[bidx];
				break;
			case 'c':
				cidx++;
				if(cidx == c.length()) {
					return 'C';
				}
				current = c[cidx];
				break;
		}
	}
}

int main() {
	string a, b, c;
	cin >> a >> b >> c;

	cout << judge(a, b, c) << endl;
}