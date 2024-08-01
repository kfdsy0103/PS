#include <bits/stdc++.h>

using namespace std;

string str;
bool isP[2501][2501];
int dp[2501];
const int INF = 987654321;

int go(int here) {
    if (here >= str.size()) return 0;
    int& ret = dp[here];
    if (ret != INF) return ret;
    // dp[here] => here부터 end까지 탐색영역을 넓히며 묶었을 때 최솟값
    for (int i = 0; here + i < str.size(); i++) {
        if (isP[here][here+i]) {
            ret = min(ret, go(here+i+1) + 1);
        }
        //탑다운은 재귀로 작성 + [here][here+i]는 팰린드롬이라는 뜻이므로 개수 1개추가
    }
    return ret;
}

int main() {
    fill(dp, dp + 2501, INF);
    cin >> str;

    for (int i = 0; i < str.size(); i++) {
        isP[i][i] = 1;
    }

    for (int i = 1; i < str.size(); i++) {
        if (str[i - 1] == str[i]) isP[i-1][i] = 1;
    }

    for (int size = 3; size <= str.size(); size++) {
        for (int i = 0; i + size <= str.size(); i++) {
            int end = size + i - 1;
            if (str[i] == str[end] && isP[i + 1][end - 1]) {
                isP[i][end] = 1;
            }
        }
    }
    cout << go(0);

    return 0;
}