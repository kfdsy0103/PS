#include <bits/stdc++.h>
using namespace std;

const int dy[4] = { -1,1,0,0 };
const int dx[4] = { 0,0,-1,1 };
int n, m, lo, hi, ret;
int a[300001];

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

bool check(int num) {
    int sum = 0; // �� ���� �й�Ǵ°�?
    for (int i = 0; i < m; i++) {
        sum += a[i] / num;
        if (a[i] % num) sum++;
    }
    return sum <= n;
}

int main() {
    init();
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }
    
    lo = 1;
    hi = 1e9;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (check(mid)) { // �������� mid�϶�
            ret = mid;
            hi = mid - 1; 
        }
        else {
            lo = mid + 1;
        }
    }

    cout << ret;

    return 0;
}