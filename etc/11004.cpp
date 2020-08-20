#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int v[5000000];
int main() {
	int N;
	int K;
	scanf("%d", &N);
	scanf("%d", &K);
	for (int i = 0; i < N; i++) {
		scanf("%d", &v[i]);
	}
	sort(v, v+N);

	printf("%d\n", v[K - 1]);
	return 0;
}