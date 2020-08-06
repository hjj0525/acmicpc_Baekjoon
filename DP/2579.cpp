#include <algorithm>
#include <iostream>
using namespace std;
int main() {
	int n;
	int score[301] = { 0, };
	int dp[301] = { 0, };
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		cin >> score[i];
	}
	dp[1] = score[1];
	dp[2] = dp[1] + score[2];
	for (int i = 3; i <= n; i++) {
		dp[i] = max(dp[i-3]+score[i-1], dp[i-2]) + score[i];
	}
	cout << dp[n] << endl;
	return 0;
}
