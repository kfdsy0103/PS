// �ð��� 1�д����� ����Ѵٸ� 20�� x 30�� = 600�� (�ð��ʰ�...)
// �ð��� mid �϶� n���� �¿� �� �ִ°� ? -> �̺�Ž������ Ǯ��
// �ʿ��� �ð����� ���� �� ū �ð��� ���ϰ�, �� �ð��� ���Ӱ� Ÿ�� ��� ���� ���� ��, �ٽ� �� �� ���̱ⱸ�� �¿� Ȯ���Ѵ�.
#include <bits/stdc++.h>
using namespace std;

const int dy[4] = { -1,1,0,0 };
const int dx[4] = { 0,0,-1,1 };
long long n, m, temp, a[10004], lo, hi, mid, ret;

bool check(long long mid) {
    temp = m; // m���� �̸� �¿��
    for (long long i = 0; i < m; i++) {
        temp += mid / a[i]; // mid �ð����� Ȯ������ �� �� ���� ž���ϴ���
    }
    return temp >= n;
}

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    init();
    cin >> n >> m;

    for (long long i = 0; i < m; i++) cin >> a[i];

    if (n <= m) {
        cout << n;
        return 0;
    }

    hi = 60000000004;
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        if (check(mid)) {
            ret = mid; hi = mid - 1;
        }
        else {
            lo = mid + 1;
        }
    }

    temp = m;
    for (long long i = 0; i < m; i++) temp += ((ret - 1) / a[i]);
    // ret �ð� �ٷ� ������ �� ���� ������ �ľ�

    for (long long i = 0; i < m; i++) {
        if (ret % a[i] == 0) temp++; // ret �ð��� ���� �ֱⰡ ������ ��� �¿�
        if (temp == n) {
            cout << i + 1 << '\n';
            return 0;
        }
    }

    return 0;
}