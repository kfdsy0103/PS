#include <bits/stdc++.h>
using namespace std;

const int dy[4] = { -1,1,0,0 };
const int dx[4] = { 0,0,-1,1 };
int t, n, m, num;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    init();

    cin >> t;
    while (t--) {
        map<int, int> mp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> num;
            mp[num] = 1;
        }
        cin >> m;
        for (int i = 0; i < m; i++) {
            cin >> num;
            if (mp[num]) cout << 1 << "\n";
            else cout << 0 << "\n";
        }
    }
   
    return 0;
}