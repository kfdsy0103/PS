#include <bits/stdc++.h>
using namespace std;

const int dy[4] = { -1,1,0,0 };
const int dx[4] = { 0,0,-1,1 };
long long s, c, l, hi, lo, ret, sum;
long long a[1000001];

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

bool check(long long slice) {
    long long sum = 0;
    for (int i = 0; i < s; i++) {
        sum += a[i] / slice;
    }
    return sum >= c;
}

int main() {
    init();
    cin >> s >> c;
    for (int i = 0; i < s; i++) {
        cin >> a[i];
        if (a[i] > hi) hi = a[i];
    }

    lo = 1;
    while (lo <= hi) {
        long long mid = (lo + hi) / 2;
        if (check(mid)) {
            ret = mid;
            lo = mid + 1; // mid로 가능하면 더 크게 자르기
        }
        else {
            hi = mid - 1; // mid로 불가능하면 더 작게 자르기
        }
    }

    for (int i = 0; i < s; i++) {
        sum += a[i];
    }
    cout << sum - ret * c;

    return 0;
}