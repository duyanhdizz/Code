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

int n, k;
string s;
map<string, int> m;

int32_t main() {
#define TASKNAME "meo"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n >> k;
	cin >> s;
	string ss = s;
	int kk = k;
	while(k--) {
		REP(i, 0, n) {
			char fi = s[i], se;
			if(i == n - 1) se = s[0];
			else se = s[i + 1];
			if(fi > se) swap(fi, se);
			if(fi != se) {
				if(fi == 'G' && se == 'R') {
					fi = 'W';
					se = 'W';
				} else if(fi == 'G' && se == 'W') {
					fi = 'R';
					se = 'R';
				} else {
					fi = 'G';
					se = 'G';
				}
			}
			s[i] = fi;
			if(i == n - 1) s[0] = se;
			else s[i + 1] = se;
		}
	}
	m[s]++;
	FOR(i, 1, kk) {
		REP(i, 0, n) {
			char fi = ss[i], se;
			if(i == n - 1) se = ss[0];
			else se = ss[i + 1];
			if(fi > se) swap(fi, se);
			if(fi != se) {
				if(fi == 'G' && se == 'R') {
					fi = 'W';
					se = 'W';
				} else if(fi == 'G' && se == 'W') {
					fi = 'R';
					se = 'R';
				} else {
					fi = 'G';
					se = 'G';
				}
			}
			ss[i] = fi;
			if(i == n - 1) ss[0] = se;
			else ss[i + 1] = se;
		}
		//if(m[ss]) cout << i << '\n';
	}
	cout << s;
	return 0;
}
/*
==================================+
INPUT:                            |
------------------------------    |
3 1
GRR
---
3 2
GRR
---
5 1
WRWRW
---
5 2
WRWRW
---
5 3
WRWRW
---
5 4
WRWRW
---
5 5
WRWRW
---
5 100
WRWRW
---
6 100
WRWRGW
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |
RGR
---
RGR
---
GGGWG
---
RGGGR
---
RRWGR
---
GRRGG
---
RGRWR
---
WRGGW
---
WWRGRW
------------------------------    |
==================================+
*/
