#pragma warning (disable: 4996)
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

// Divide and Conquer 방식
// 1/3로 쪼개서 좌상단부터 우하단까지 쭉 훑으면서 조건을 만족시키는 방법
int N;
char map[2187][2187];

void solve(int x, int y, int n) {
	if (n == 1) {
		map[x][y] = '*';
		return; // 확정되었으므로 끝, n == 0 은 고려할 필요가 없다.
	}

	int div = n / 3;
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == 1 && j == 1) // 가운데 좌표가 (1,1)인 부분이 비어있는 부분
				continue;
			solve(x+(i*div), y+(j*div), div);
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> N; // N은 3의 거듭제곱 
	memset(map, ' ', sizeof(map));
	
	solve(0, 0, N);

	// 출력부
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout << map[i][j];
		cout << '\n';
	}
		
	return 0;
}