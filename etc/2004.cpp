#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#pragma warning(disable: 4996);
#define ll long long
using namespace std;

int getFive(int num) {
	int cnt = 0;
	for (ll i = 5; num / i >= 1; i *= 5) {
		cnt += num / i;
	}

	return cnt;
}
int getTwo(int num) {
	int cnt = 0;
	for (ll i = 2; num / i >= 1; i *= 2) {
		cnt += num / i;
	}

	return cnt;
}

int main() {
	int n, r;
	scanf("%d %d", &n, &r);

	int five = 0;
	int two = 0;
	
	five += getFive(n);
	if (r != 0)
		five -= getFive(r);
	if (n != r)
		five -= getFive(n - r);

	two += getTwo(n);
	if (r != 0)
		two -= getTwo(r);
	if (n != r)
		two -= getTwo(n - r);

	printf("%d\n", min(two, five));
	return 0;
}