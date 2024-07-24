// a -> d ��� ���� ��,
// ���� ������ ��� �ִٸ� {a, b, c, d}, {a, c, b, d} ...
// �����ν� �����ؾ� �ϹǷ� 16!�� �ð����⵵�� ���´�.
// �׷��� b�� ���� �湮�ϳ�, c�� ���� �湮�ϳ� ������ ��� ����
// {a, b, c}�� �κ� ������ + d�� ���� ��븸 ���ϸ� �ǹǷ�,
// dp + ��Ʈ����ŷ(Ư�� ������ �湮ó���� ����)�� Ȱ���Ѵ�.
// ���� ���� ������ � ���� �ǵ� ����� ����.
#include <bits/stdc++.h>

using namespace std;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
const int INF = 99999999;
int n;
int mp[17][17];
int dp[17][1 << 16];

int travel(int here, int visited) {
	if (visited == (1 << n) - 1) {
		if (mp[here][0]) return mp[here][0];
		else return INF;
	}
	int& ret = dp[here][visited];
	if (~ret) return ret;
	ret = INF;
	for (int i = 0; i < n; i++) {
		if (visited & (1 << i)) continue; // �̹� �湮�� ����
		if (mp[here][i] == 0) continue; // �� �� ���� ����
		ret = min(ret, travel(i, visited | (1 << i)) + mp[here][i]);
	}
	return ret;
}

int main() {
	memset(dp, -1, sizeof(dp));
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mp[i][j];
		}
	}
	
	cout << travel(0, 1);

	return 0;
}