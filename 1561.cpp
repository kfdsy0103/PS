// 시간을 1분단위로 계산한다면 20억 x 30분 = 600억 (시간초과...)
// 시간이 mid 일때 n명을 태울 수 있는가 ? -> 이분탐색으로 풀이
// 필요한 시간보다 조금 더 큰 시간을 구하고, 그 시간에 새롭게 타는 사람 수를 빼준 뒤, 다시 한 명씩 놀이기구에 태워 확인한다.
#include <bits/stdc++.h>
using namespace std;

const int dy[4] = { -1,1,0,0 };
const int dx[4] = { 0,0,-1,1 };
long long n, m, temp, a[10004], lo, hi, mid, ret;

bool check(long long mid) {
    temp = m; // m명을 미리 태우고
    for (long long i = 0; i < m; i++) {
        temp += mid / a[i]; // mid 시간까지 확인했을 때 몇 명이 탑승하는지
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
    // ret 시간 바로 전까지 몇 명이 탔는지 파악

    for (long long i = 0; i < m; i++) {
        if (ret % a[i] == 0) temp++; // ret 시간에 동작 주기가 맞으면 사람 태움
        if (temp == n) {
            cout << i + 1 << '\n';
            return 0;
        }
    }

    return 0;
}