#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast","unroll-loops")
#define FOR(i, a, b) for(int i=(a), _b=(b); i<_b; ++i)
#define fi first
#define se second
#define pb push_back
#define ll long long
#define all(a) a.begin(),a.end()
typedef pair<int, int> pii;
const int N = 9 + 1e6;
const int INF = 1e9;

int t;

void solve() {
	string s;
	char c;
	cin >> s >> c;
	while(true) {
		int i = 0;
		s += c;
		for(; i + 1 < s.size(); i++)
			if(s[i] > s[i + 1])
				break;
		if(i == s.size() - 1) {
			s.erase(s.end() - 1, s.end());
			break;
		}
		s = s.substr(0, i) + s.substr(i + 1, s.size() - i);
	}
	cout << s << '\n';
}

int32_t main() {
#define TASKNAME "CHDIGER"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> t;
	while(t--)
		solve();
	return 0;
}
/*
INPUT
3
35 4
42 4
24 9
OUTPUT
34
24
24
*/
