#include <bits/stdc++.h>

using namespace std;

const int dy[] = { 0, 0, -1, 1};
const int dx[] = { 1, -1, 0, 0};
double a, b;
int prime[100];
double dp[20][20][20];

double dfs(int time, int score_a, int score_b) {
	if (time == 18) {
		if (!prime[score_a] || !prime[score_b]) return 1;
		return 0;
	}

	double &ret = dp[time][score_a][score_b];
	if (ret > -0.5) return ret;

	ret = 0;
	ret += dfs(time+1, score_a + 1, score_b) * a * (1 - b);
	ret += dfs(time+1, score_a, score_b + 1) * (1 - a) * b;
	ret += dfs(time+1, score_a + 1, score_b + 1) * a * b;
	ret += dfs(time+1, score_a, score_b) * (1 - a) * (1 - b);

	return ret;
}

int main() {
	memset(dp, -1, sizeof(dp));

	cin >> a >> b;
	a /= 100;
	b /= 100;

	prime[0] = 1; prime[1] = 1;
	for (int i = 2; i < 100; i++) {
		for (int j = i*2; j < 100; j += i) {
			prime[j] = 1;
		}
	}

	cout <<	dfs(0, 0, 0);

	return 0;
}