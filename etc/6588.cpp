#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#pragma warning(disable: 4996);

using namespace std;


int main() {
	int n = 1;
	int a[1000001] = { 0, 1 };

	// 배열값이 0이면 소수 
	for (int i = 2; i <= 1000000; i++) {
		for (int j = 2; i*j <= 1000000; j++)
			a[i*j] = 1;
	}
	while (1) {
		scanf("%d", &n);
		if (n == 0)
			break;
		int i = 3;
		while (1) {
			if ((n - i) < 0) {
				printf("Goldbach's conjecture is wrong.\n");
				break;
			}
			if (!a[i] && !a[n - i]) {
				printf("%d = %d + %d\n", n, i, n - i);
				break;
			}
			i++;
		}
	}
	
	return 0;
}