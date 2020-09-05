#pragma warning (disable: 4996)
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int board[2200][2200];
int ans[3];

void solve(int x, int y, int cur) {
	int first = board[x][y];
	bool isSame = true;

	for (int i = x; i < x + cur; i++) {
		for (int j = y; j < y + cur; j++) {
			if (first != board[i][j]) {
				isSame = false;
				break;
			}
		}
		if (!isSame)
			break;
	}
	
	if (isSame) {
		ans[first + 1]++; // first의 값은 -1, 0, 1 이기에 ans[0, 1, 2]에 넣기 위함
		return;
	}

	// 한 변의 길이가 k인 사각형으로 9분할 하여 계산
	int k = cur / 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			solve(x + i * k, y + j * k, k);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j];

	solve(0, 0, N);
	
	for (int x : ans)
		cout << x << "\n";

	return 0;
}