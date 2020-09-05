#pragma warning (disable: 4996)
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

// 각 좌표에 대한 위치를 확인하는 방법

void solve(int x, int y, int n) {
	if ((x / n) % 3 == 1 && (y / n) % 3 == 1)
		cout << ' ';
	else {
		if (n / 3 == 0)
			cout << '*';
		else
			solve(x, y, n / 3);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N; // N은 3의 거듭제곱 

	// 출력부
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			solve(i, j, N);
		cout << '\n';
	}
		
	return 0;
}