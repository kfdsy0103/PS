#include <bits/stdc++.h>
using namespace std;

const int dy[4] = { -1,1,0,0 };
const int dx[4] = { 0,0,-1,1 };
int n, m, lo, hi, ret, mx;
int a[100001];

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

bool check(int num) {
    int cnt = 1;
    int temp = num;
    for (int i = 0; i < n; i++) {
        if (temp - a[i] < 0) {
            cnt++;
            temp = num;
        }
        temp -= a[i];
    }
    return cnt <= m;
}

int main() {
    init();
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    
    lo = mx;
    hi = 1e9;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (check(mid)) {
            hi = mid - 1;
            ret = mid;
        }
        else {
            lo = mid + 1;
        }
    }
    
    cout << ret;

    return 0;
}