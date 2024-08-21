#include <bits/stdc++.h>
using namespace std;

const int dy[4] = { -1,1,0,0 };
const int dx[4] = { 0,0,-1,1 };
int n, m, num, ret;
map<int, int> mp;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    init();
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> num;
        mp[num]++;
    }
    for (int i = 0; i < m; i++) {
        cin >> num;
        mp[num]++;
    }
    for (auto it : mp) {
        if (it.second == 1) ret++;
    }

    cout << ret;

    return 0;
}