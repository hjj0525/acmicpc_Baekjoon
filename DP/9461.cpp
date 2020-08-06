#include <algorithm>
#include <iostream>
using namespace std;
int main() {
	int testCase;
	cin >> testCase;
	while (testCase--) {
		int n;
		long dp[101];
		dp[1] = 1;
		dp[2] = 1;
		dp[3] = 1;
		dp[4] = 2;
		dp[5] = 2;

		cin >> n;

		for (int i = 6; i <= n; i++) {
			dp[i] = dp[i - 1] + dp[i - 5];
		}
		cout << dp[n] << endl;
	}
	return 0;
}
