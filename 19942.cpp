// �ʱ�ȭ, �������, �޸������̼�, ����
// ��Ž > ����� ���� �ʹ� ũ�� > �迭�� ���� �� �ִ��� > dp�� Ǯ��
#include <bits/stdc++.h>

using namespace std;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
int n, m;
int a[1004];
int dp[1004][2][34]; // Ư�� ���°����� ���� �� �ִ� ������ �ִ� ����

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