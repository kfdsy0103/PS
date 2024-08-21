#include <bits/stdc++.h>
using namespace std;

const int dy[4] = { -1,1,0,0 };
const int dx[4] = { 0,0,-1,1 };
int n, m, t, ret;
int a[20001], b[20001];

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    init();
    cin >> t;
    while (t--) {
        ret = 0;
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }
        sort(b, b+m);
        for (int i = 0; i < n; i++) {
            ret += (int)(lower_bound(b, b + m, a[i]) - b);
        }
        cout << ret << "\n";
    }

    return 0;
}