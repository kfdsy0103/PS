// ���Ҿ� dp >> 1�� ����� ��� -> 2�� ����� ��� -> 3���� ����� ���
#include <bits/stdc++.h>

using namespace std;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
int t, n;
int dp[10001];

int main() {
	cin >> t;

	dp[0] = 1;
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 10000; j++) {
			if(j - i >= 0) dp[j] += dp[j - i];
		}
	}
	while (t--) {
		cin >> n;
		cout << dp[n] << "\n";
	}

	return 0;
}