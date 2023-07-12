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
const int N = 9 + 50;
const int INF = 1e9;

int n;
int d[26], d_2[26];
string s[N];
vector<string> hoanvi;

int chuyendoi(string s, string t) {
	if(s == t) return 0;
	int len = t.size();
	while(len--) {
		t += t[0];
		t.erase(0, 1);
		if(s == t) return (int)t.size() - len;
	}
	return 0;
}

int32_t main() {
#define TASKNAME "BROTAT"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n;
	FOR(i, 1, n) {
		cin >> s[i];
		if(i == 1) {
			FOR(j, 0, s[i].size() - 1) {
				d[s[i][j] - 'a']++;
			}
		} else {
			FOR(j, 0, s[i].size() - 1) {
				d_2[s[i][j] - 'a']++;
			}
			FOR(j, 0, 25) {
				if(d[j] != d_2[j]) {
					return cout << -1, 0;
				}
			}
		}
		fill(d_2, d_2 + 27, 0);
	}
	string fi = s[1];
	hoanvi.pb(fi);
	int len = fi.size();
	while(len--) {
		fi += fi[0];
		fi.erase(0, 1);
		hoanvi.pb(fi);
	}
	int ans = INF;
	each(x, hoanvi) {
		int res = 0;
		FOR(i, 1, n) {
			res += chuyendoi(x, s[i]);
		}
		ans = min(ans, res);
	}
	cout << ans;
	return 0;
}
/*
==================================+
INPUT:                            |
------------------------------    |
4
xzzwo
zwoxz
zzwox
xzzwo
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |
5
------------------------------    |
==================================+
*/
