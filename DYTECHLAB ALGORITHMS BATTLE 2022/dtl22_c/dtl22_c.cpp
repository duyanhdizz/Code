#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast","unroll-loops")
#define FOR(i, a, b) for(int i=(a), _b=(b); i<_b; ++i)
#define fi first
#define se second
#define pb push_back
#define all(a) a.begin(),a.end()
typedef pair<int, int> pii;
const int N = 9 + 1e6;
const int INF = 1e9;

int t, s, c, k, l, d;

int32_t main() {
#define TASKNAME "dtl22_c"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> t >> s >> c >> k >> l >> d;
	int cc = c;
	int res = 0, vtoc = 0, ress = 0, ss = s, ccc = c, kk = k, ll = l, dd = d, tt = t;
	while(t--) {
		if(c >= l && vtoc < s) {
			c -= l;
			vtoc++;
			res += vtoc;
		} else if(c >= k) {
			res += vtoc;
			c -= k;
		} else if(vtoc > 1) {
			c += d;
			if(c > cc) c = cc;
			vtoc--;
			res += vtoc;
		} else break;
		//cout << vtoc << ' ' << c << '\n';
	}
	vtoc = 0;
	while(tt--) {
		if(vtoc == ss) break;
		if(ccc >= ll && vtoc < ss) {
			ccc -= ll;
			vtoc++;
			ress += vtoc;
		} else if(vtoc > 1) {
			ccc += dd;
			if(ccc > cc) ccc = cc;
			vtoc--;
			ress += vtoc;
		} //else break;
		//cout << vtoc << ' ' << c << '\n';
	}
	while(tt--) {
		if(ccc >= ll && vtoc < ss) {
			ccc -= ll;
			vtoc++;
			ress += vtoc;
		} else if(ccc >= kk) {
			ress += vtoc;
			ccc -= kk;
		} else if(vtoc > 1) {
			ccc += dd;
			if(ccc > cc) ccc = cc;
			vtoc--;
			ress += vtoc;
		} //else break;
		//cout << vtoc << ' ' << c << '\n';
	}
	cout << max(res, ress);
	return 0;
}
/*
==================================+
INPUT:                            |
------------------------------    |
6 3
8 1 3 2
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |
9
------------------------------    |
==================================+
*/
