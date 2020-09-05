#pragma warning (disable: 4996)
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

char arr[3073][6145];

void solve(int n, int r, int c) { // num, row, col
	if (n == 3) {
		arr[r][c] = '*';
		arr[r + 1][c - 1] = '*';
		arr[r + 1][c + 1] = '*';
		for (int i = c - 2; i <= c + 2; i++)
			arr[r + 2][i] = '*';
		return;
	}

	solve(n / 2, r, c);
	solve(n / 2, r + n / 2, c - n / 2);
	solve(n / 2, r + n / 2, c + n / 2);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;
	
	solve(N, 1, N); // 시작점 (삼각형의 위 꼭지점)
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= 2 * N - 1; j++) {
			if (arr[i][j] != '*')
				arr[i][j] = ' ';
		}
	}
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= 2*N - 1; j++) {
			cout << arr[i][j];
		}
		cout << '\n';
	}

	return 0;
}