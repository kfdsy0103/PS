#include <bits/stdc++.h>
using namespace std;

const int dy[4] = { -1,1,0,0 };
const int dx[4] = { 0,0,-1,1 };
int t, n;
int sung[] = { 6, 2,5,5,4,5,6,3,7,6 };
string dp[101];
string MAX = "11111111111111111111111111111111111111111111111111";

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

string minStr(string a, string b) {
    if (a.size() == b.size()) return a < b ? a : b;
    if (a.size() > b.size()) return b;
    return a;
}

string make_min(int num) {
    if (num == 0) return "";

    string& ret = dp[num];
    if (ret != MAX) return ret;
    
    for (int i = 0; i < 10; i++) {
        if (num - sung[i] < 0) continue;
        if (num == n && i == 0) continue;
        ret = minStr(ret, to_string(i) + make_min(num - sung[i]));
    }

    return ret;
}

string make_max(int num) {
    string ret = "";
    if (num & 1) {
        ret += "7";
        num -= 3;
    }
    while (num) {
        ret += "1";
        num -= 2;
    }
    return ret;
}

int main() {
    cin >> t;

    while (t--) {
        cin >> n;
        fill(dp, dp + 101, MAX);
        cout << make_min(n) << " " << make_max(n) << "\n";
    }
    
    return 0;
}