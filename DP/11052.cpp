#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<long> p(N+1);
	vector<long> dp(N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> p[i];
		dp[i] = p[i];
	}
	for (int i = 2; i <= N; i++) {
		for (int j = 1; j <= i/2; j++) {
			dp[i] = max(dp[i], dp[j]+dp[i-j]);
		}
	}

	cout << dp[N] << endl;
	return 0;
}
