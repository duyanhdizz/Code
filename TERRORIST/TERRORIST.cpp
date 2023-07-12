#include <bits/stdc++.h>
#include <cstring>
using namespace std;
#define FOR(i, a, b) for (int i = (a); i <= (int) (b); ++i)
int n;
string s;

bool check(string s) {
	FOR(i, 0, s.size() - 2) {
		if(s[i] == 'F' && s[i + 1] == 'C') {
			return false;
		}
	}
	return true;
}

bool check_(string s) {
	FOR(i, 0, s.size() - 2) {
		if(s[i] == 'C' && s[i + 1] == 'F') {
			return false;
		}
	}
	return true;
}

int main() {
	cin >> n >> s;
	string ss = s;
	reverse(ss.begin(), ss.end());
	int ans = 0;
	while(check(s) == false) {
		FOR(i, 0, s.size() - 2) {
			if(s[i] == 'F' && s[i + 1] == 'C') {
				swap(s[i], s[i + 1]);
				ans++;
				break;
			}
		}
	}
	int ans_ = 0;
	while(check_(ss) == false) {
		FOR(i, 0, ss.size() - 2) {
			if(ss[i] == 'C' && ss[i + 1] == 'F') {
				swap(ss[i], ss[i + 1]);
				ans_++;
				break;
			}
		}
	}
	cout << min(ans, ans_);
	return 0;
}
