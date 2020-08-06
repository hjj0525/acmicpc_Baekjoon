#include <algorithm>
#include <iostream>
using namespace std;

int main() {
	int n;
	int sum = 0;
	int ml[10001] = { 0, };
	int dp[10001] = { 0, };
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> ml[i];
	}
	dp[1] = ml[1];
	dp[2] = dp[1] + ml[2];

	for (int i = 3; i <= n; i++)
		dp[i] = max(dp[i - 1], max(dp[i-2]+ml[i], dp[i-3]+ml[i-1]+ml[i]));

	cout << dp[n] << endl;
	return 0;
}