#include <bits/stdc++.h>

using namespace std;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
const int INF = 99999999;
int n;
int dp[1000001];

void trace(int n) {
	if (n == 0) return;
	cout << n << " ";
	if ((n % 3 == 0) && (dp[n] == dp[n / 3] + 1)) trace(n / 3);
	else if ((n % 2 == 0) && (dp[n] == dp[n / 2] + 1)) trace(n / 2);
	else trace(n - 1);
}

int main() {
	int n;
	cin >> n;
	fill(dp, dp + 1000001, INF);

	dp[1] = 0;
	for (int i = 1; i <= n; i++) {
		if (i % 3 == 0) dp[i] = min(dp[i], dp[i / 3] + 1);
		if (i % 2 == 0) dp[i] = min(dp[i], dp[i / 2] + 1);
		dp[i] = min(dp[i], dp[i - 1] + 1);
	}
	cout << dp[n] << "\n";
	trace(n);
	
	return 0;
}