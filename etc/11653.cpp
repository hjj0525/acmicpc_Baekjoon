#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#pragma warning(disable: 4996);
using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = 2; i <= n; i++) {
		if (n%i == 0) {
			printf("%d\n", i);
			n /= i;
			i--;
		}
	}
	return 0;
}