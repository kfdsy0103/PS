#include <bits/stdc++.h>
using namespace std;

const int dy[4] = { -1,1,0,0 };
const int dx[4] = { 0,0,-1,1 };
int n, m, lo, hi, ret, mx, s;
int a[100001];

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

bool check(int num) {
    if (mx > num) return false;
    int temp = num;
    int sum = 0; // 사용한 블루레이 개수
    for (int i = 0; i < n; i++) {
        if (temp - a[i] < 0) {
            sum++;
            temp = num;
        }
        temp -= a[i];
    }
    if (temp != num) sum++;
    return sum <= m;
}

int main() {
    init();
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s += a[i];
        mx = max(mx, a[i]);
    }
    
    lo = 0;
    hi = s;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (check(mid)) {
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