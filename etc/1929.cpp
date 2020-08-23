#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#pragma warning(disable: 4996);
using namespace std;

// 에라토스테네스의 방법으로 소수구하기
int main() {
	int m, n;
	scanf("%d %d", &m, &n);
	int a[1000001] = { 0, 1 };

	for (int i = 2; i <= n; i++) {
		for (int j = 2; i*j <= n; j++)
			a[i*j] = 1;
	}

	for (int i = m; i <= n; i++) {
		if (!a[i])
			printf("%d\n", i);
	}

	return 0;
}