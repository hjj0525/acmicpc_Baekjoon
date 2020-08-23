#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#pragma warning(disable: 4996);
using namespace std;

long long fac(long long n) {
	if (n < 2)
		return n;
	else
		return n * fac(n - 1);
}
int main() {
	int n, res = 0;
	cin >> n;
	int chk[501] = { 0, };
	
	for (int i = 0; i <= n; i++) {
		if (i >= 125 && i % 125 == 0)
			chk[i] = 3;
		else if (i >= 25 && i % 25 == 0)
			chk[i] = 2;
		else if (i>= 5 && i % 5 == 0)
			chk[i] = 1;
		
		res += chk[i];
	}
	
	printf("%d\n", res);
	return 0;
}