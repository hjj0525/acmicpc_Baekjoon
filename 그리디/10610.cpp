#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	char n[100001];
	cin >> n;

	bool isZero = false;
	int cnt = 0;
	int pos = 0;	
	
	int numCnt[10] = { 0, };

	while (n[pos] != '\0') {
		if (n[pos] == '0') {
			numCnt[0]++;
			pos++;
			isZero = true;
		}
		else {
			int num = n[pos] - '0';
			cnt += num;
			numCnt[num]++;
			pos++;
		}
	}


	if (cnt % 3 == 0 && isZero) {
		for (int i = 9; i >= 0; i--) {
			for (int j = 0; j < numCnt[i]; j++)
				cout << i;
		}
	}
	else
		cout << -1 << '\n';

	return 0;
}