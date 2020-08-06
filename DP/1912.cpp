#include <algorithm>
#include <iostream>
using namespace std;
int N; // 수열 크기
int arr[100002] = { 0, };
int dp[100002] = { 0, };
int ans = -1001;
int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	dp[0] = arr[0];
	ans = max(ans, dp[0]);
	for (int i = 1; i < N; i++) {
		dp[i] = arr[i];
		dp[i] = max(dp[i], dp[i-1] + arr[i]);
		
		ans = max(ans, dp[i]);
	}
	cout << ans << endl;
	return 0;
}
