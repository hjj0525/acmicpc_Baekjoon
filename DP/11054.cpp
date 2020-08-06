#include <algorithm>
#include <iostream>
using namespace std;
int N; // 수열 크기
int arr[1003] = { 0, };
long dpInc[1003] = { 0, };
long dpDec[1003] = { 0, };
long ans=0;
int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	for (int i = 0; i < N; i++) {
		dpInc[i] = 1;
		for (int j = 0; j < i; j++) 
			if(arr[i] > arr[j]) 
				dpInc[i] = max(dpInc[i], dpInc[j] + 1);	
	}
	for (int i = N-1; i >= 0; i--) {
		dpDec[i] = 1;
		for (int j = N-1; j > i; j--)
			if (arr[i] > arr[j])
				dpDec[i] = max(dpDec[i], dpDec[j] + 1);
	}
/*	
	cout << endl;
	for (int i = 0; i < N; i++) {
		cout << dpInc[i] << " ";
	}
	cout << "앞에서 부터 증가 수열" << endl;
	for (int i = 0; i < N; i++) {
		cout << dpDec[i] << " ";
	}
	cout << "뒤에서 부터 증가 수열" << endl;
	cout << "결과: ";
*/

	for (int i = 0; i < N; i++)
		ans = max(ans, dpInc[i] + dpDec[i]);
	cout << ans-1 << endl;

	return 0;
}
