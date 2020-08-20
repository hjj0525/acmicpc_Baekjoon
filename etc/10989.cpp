#include <iostream>
#include <cstdio>
using namespace std;

int arr[10001] = { 0, };
int main() {
	int n;
	int num;
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d", &num);
		arr[num]++;
	}

	for (int i = 1; i <=10000; i++) {
		while (arr[i]--)
			printf("%d\n", i);
	}
	return 0;
}