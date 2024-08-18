#include <bits/stdc++.h>
using namespace std;

const int dy[4] = { -1,1,0,0 };
const int dx[4] = { 0,0,-1,1 };
long long x, y, z, ret = -1, lo, hi;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    init();

    cin >> x >> y;

    z = y * 100 / x;
    lo = 1, hi = 1e9;

    while (lo <= hi) {
        long long game = (lo + hi) / 2;
        if (((y + game) * 100 / (x + game)) > z) {
            ret = game;
            hi = game - 1;
        }
        else {
            lo = game + 1;
        }
    }

    cout << ret;
   
    return 0;
}