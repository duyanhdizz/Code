#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#pragma GCC optimize("Ofast","unroll-loops")
#define FOR(i, a, b) for (int i = (a); i <= (int) (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= (int) (b); --i)
#define REP(i, a, b) for (int i = (a); i < (int) (b); ++i)
#define each(a, x) for (auto &a : x)
#define fi first
#define se second
#define pb push_back
#define ll long long
#define all(a) a.begin(),a.end()
typedef pair<int, int> pii;
const int N = 9 + 1e6;
const int INF = 1e9;

int n;
int d[29];
vector<string> s;

int32_t main() {
#define TASKNAME "LCARDS"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n;
	s.pb("");
	s.pb("");
	FOR(i, 1, n) {
		string a, b;
		cin >> a >> b;
		FORD(i, s.size() - 1, s.size() - (2ll << (i - 1))) {
			s.pb(s[i] + a);
			s.pb(s[i] + b);
		}
	}
	fill(d, d + 29, 0);
	FORD(i, s.size() - 1, s.size() - (2ll << (n - 1))) {
		map<char, int> m;
		FOR(j, 0, s[i].size() - 1) m[s[i][j]]++;
		each(x, m) d[x.fi - 'a'] = max(d[x.fi - 'a'], x.se);
	}
	REP(i, 0, 26) cout << d[i] << ' ';
	return 0;
}
/*
==================================+
INPUT:                            |
------------------------------    |
3
fox box
dog cat
car bus
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |
2 2 2 1 0 1 1 0 0 0 0 0 0 0 2 0 0 1 1 1 1 0 0 1 0 0
------------------------------    |
==================================+
*/