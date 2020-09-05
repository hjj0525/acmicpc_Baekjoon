#pragma warning (disable: 4996)
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int vid[64][64];
int N;

void solve(int x, int y, int size) {
	int state = vid[x][y];
	bool isSame = true;

	for (int i = x; i < x+size; i++) {
		for (int j = y; j < y+size; j++) {
			if (state != vid[i][j]) {
				isSame = false;
				break;
			}
		}
		if (!isSame)
			break;
	}

	if (!isSame) {
		cout << '(';
		for (int i = 0; i < size; i+=(size/2)) {
			for (int j = 0; j < size; j += (size / 2))
				solve(x + i, y + j, size / 2);
		}
		cout << ')';
	}
	else
		cout << state;
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			scanf("%1d", &vid[i][j]);
	}
	int x = 0, y = 0;
	
	solve(x, y, N);

	return 0;
}