#pragma warning (disable: 4996)
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

void hanoi(int n, int from, int by, int to) {
	if (n == 1)
		cout << from << " " << to << '\n';
	else {
		hanoi(n - 1, from, to, by);
		cout << from << " " << to << '\n';
		hanoi(n - 1, by, from, to);
	}
		
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N, K;
	cin >> N;
	K = pow(2, N) - 1;
	cout << K << '\n';
	
	hanoi(N, 1, 2, 3);

	return 0;
}