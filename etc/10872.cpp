#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#pragma warning(disable: 4996);
using namespace std;

int fac(int n) {
	if (n < 2)
		return n;
	else
		return n * fac(n - 1);
}
int main() {
	int n;
	cin >> n;
	int ans = fac(n);
	if (n == 0)
		printf("1\n"); // 0! = 1 ·Î ¾à¼Ó!
	else
		printf("%d\n", ans);
	return 0;
}