#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int N, M, tmp;
vector<int> V;
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		V.push_back(tmp);
	}
	sort(V.begin(), V.end());

	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d", &tmp);
		auto low = lower_bound(V.begin(), V.end(), tmp);
		auto high = lower_bound(V.begin(), V.end(), tmp+1);
		printf("%d ", high - low);
	}
	return 0;
}