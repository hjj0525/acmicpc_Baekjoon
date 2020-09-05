#pragma warning (disable: 4996)
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

// Divide and Conquer ���
// 1/3�� �ɰ��� �»�ܺ��� ���ϴܱ��� �� �����鼭 ������ ������Ű�� ���
int N;
char map[2187][2187];

void solve(int x, int y, int n) {
	if (n == 1) {
		map[x][y] = '*';
		return; // Ȯ���Ǿ����Ƿ� ��, n == 0 �� ����� �ʿ䰡 ����.
	}

	int div = n / 3;
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == 1 && j == 1) // ��� ��ǥ�� (1,1)�� �κ��� ����ִ� �κ�
				continue;
			solve(x+(i*div), y+(j*div), div);
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> N; // N�� 3�� �ŵ����� 
	memset(map, ' ', sizeof(map));
	
	solve(0, 0, N);

	// ��º�
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout << map[i][j];
		cout << '\n';
	}
		
	return 0;
}