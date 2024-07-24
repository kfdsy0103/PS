// ����� �� = ���ϱ�
// dp[y][x][dir] : y, x��ǥ�� ����/����/�밢�� �Ǵ��ϴ� ���°� dir
// �������� ���̴� �������� ����Ͽ� Ǯ��
#include <bits/stdc++.h>

using namespace std;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
const int INF = 99999999;
int n;
int mp[20][20];
int dp[20][20][3];

bool check(int y, int x, int dir) {
	if (dir == 0 || dir == 2) {
		if(!mp[y][x]) return true;
	}
	else if (!mp[y][x] && !mp[y - 1][x] && !mp[y][x - 1]) {
		return true;
	}
	return false;
}



int main() {
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> mp[i][j];
		}
	}

	dp[1][2][0] = 1; // ���η� ������ �� ������
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (check(i, j + 1, 0)) dp[i][j + 1][0] += dp[i][j][0];
			if (check(i + 1, j + 1, 1)) dp[i + 1][j + 1][1] += dp[i][j][0];

			if (check(i + 1, j, 2)) dp[i + 1][j][2] += dp[i][j][2];
			if (check(i + 1, j + 1, 1)) dp[i + 1][j + 1][1] += dp[i][j][2];

			if (check(i, j + 1, 0)) dp[i][j + 1][0] += dp[i][j][1];
			if (check(i + 1, j, 2)) dp[i + 1][j][2] += dp[i][j][1];
			if (check(i + 1, j + 1, 1))	dp[i + 1][j + 1][1] += dp[i][j][1];
		}
	}

	int ret = 0;
	ret = dp[n][n][0] + dp[n][n][1] + dp[n][n][2];
	cout << ret << "\n";

	return 0;
}