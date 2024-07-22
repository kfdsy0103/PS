// 쌍 or 짝을 이룬다 >> stack 떠올리기
// 혹은 문자열 메서드 사용하여 풀이 (substring, erase)
#include <bits/stdc++.h>

using namespace std;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
string a, b, ret;
stack<char> st;

int main() {
	cin >> a >> b;

	for (char c : a) {
		ret += c;
		if (ret.size() >= b.size() && ret.substr(ret.size() - b.size(), b.size()) == b) {
			ret.erase(ret.end() - b.size(), ret.end());
		}
	}
	
	cout << (ret == "" ? "FRULA" : ret);

	/*
	for (int i = 0; i < a.size(); i++) {
		st.push(a[i]);
		if (st.size() >= b.size() && b.back() == st.top()) {
			string cmp;
			for (int i = 0; i < b.size(); i++) {
				cmp += st.top();
				st.pop();
			}
			reverse(cmp.begin(), cmp.end());
			if (cmp != b) {
				for (char c : cmp) {
					st.push(c);
				}
			}
		}
	}

	if (st.size() == 0) {
		cout << "FRULA\n";
	}
	else {
		string ret = "";
		while (!st.empty()) {
			ret += st.top();
			st.pop();
		}
		reverse(ret.begin(), ret.end());
		cout << ret;
	}
	*/

	return 0;
}