#include <algorithm>
#include <iostream>
using namespace std;
int N; // 수열 크기
int arr[1003] = { 0, };
long dp[1003] = { 0, };
long ans=0;
int temp[2] = { 0, };
int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	for (int i = 0; i < N; i++) {
		dp[i] = arr[i];
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i] && dp[i] < dp[j] + arr[i])
				dp[i] = dp[j] + arr[i];
		}
		ans = max(ans, dp[i]);

	}
	cout << ans << endl;
	return 0;
}
// https://m.blog.naver.com/occidere/220793914361 참고