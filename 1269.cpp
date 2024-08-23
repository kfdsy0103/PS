#include <bits/stdc++.h>
using namespace std;

struct room {
    long long t;
    long long a;
    long long h;
};

const int dy[4] = { -1,1,0,0 };
const int dx[4] = { 0,0,-1,1 };
long long n, atk, ret, lo, hi;
room arr[123457];

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

bool check(long long mid) {
    long long attack = atk;
    long long hp = mid;
    for (int i = 0; i < n; i++) {
        if (arr[i].t == 1) {
            long long cnt = arr[i].h / attack;
            if (arr[i].h % attack) cnt++;
            hp -= arr[i].a * (cnt - 1);
        }
        else {
            attack += arr[i].a;
            hp = min(mid, hp + arr[i].h);
        }
        if (hp <= 0) return false;
    }
    return true;
}

int main() {
    init();
    cin >> n >> atk;

    for (int i = 0; i < n; i++) {
        cin >> arr[i].t >> arr[i].a >> arr[i].h;
    }

    lo = 1;
    hi = 1e18;
    while (lo <= hi) {
        long long mid = (lo + hi) / 2;
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