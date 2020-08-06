#include <algorithm>
#include <iostream>
using namespace std;
int N; // 수열 크기
int arr[1002] = { 0, };
int dp[1002] = { 0, };
int ans;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	for (int i = 0; i < N; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		ans = max(ans, dp[i]);

	}
	cout << ans << endl;
	return 0;
}