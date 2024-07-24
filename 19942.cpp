// 초기화, 기저사례, 메모이제이션, 로직
// 완탐 > 경우의 수가 너무 크다 > 배열에 담을 수 있는지 > dp로 풀이
#include <bits/stdc++.h>

using namespace std;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
int n, m;
int a[1004];
int dp[1004][2][34]; // 특정 상태값에서 얻을 수 있는 나무의 최대 개수

int go(int idx, int pos, int cnt) {
	if (cnt < 0) return -1e9;
	if (idx == n) return 0;

	int& ret = dp[idx][pos][cnt];
	if (~ret) return ret;
	return ret = max(go(idx + 1, pos ^ 1, cnt - 1), go(idx + 1, pos, cnt)) + (a[idx] == pos + 1);
}

int main() {
	memset(dp, -1, sizeof(dp));
	cin >> n >> m;

	for (int i = 0; i < n; i++) cin >> a[i];

	cout << max(go(0, 0, m), go(0, 1, m - 1));

	return 0;
}