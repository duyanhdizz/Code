#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast","unroll-loops")
#define FOR(i, a, b) for(int i=(a), _b=(b); i<_b; ++i)
#define fi first
#define se second
#define pb push_back
#define int long long
#define all(a) a.begin(),a.end()
typedef pair<int, int> pii;
const int N = 9 + 1e5;
const int INF = 1e9;

int n, k, b[N], c[N];
unordered_map<int, int> cheotrai, mahang, macot, cheophai, m2, m3;
map<pii, int> m;
vector<pii> a;

int32_t main() {
#define TASKNAME "QUEENSS"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> k >> n;
	for(int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		a.pb({x, y});
		m[ {x, y}] = i;
	}
	sort(all(a));
	for(int i = 0; i < n; i++) {
		m2[m[ {a[i].fi, a[i].se}]] = i;
		b[i] = min(a[i].fi, a[i].se) - cheotrai[abs(a[i].fi - a[i].se)] + a[i].fi - macot[a[i].se] + a[i].se - mahang[a[i].fi] + min(k - a[i].se, a[i].fi) - cheophai[a[i].fi + a[i].se];
		cheotrai[abs(a[i].fi - a[i].se)] = max(cheotrai[abs(a[i].fi - a[i].se)], min(a[i].fi,a[i].se));
		macot[a[i].se] = max(macot[a[i].se], a[i].fi);
		mahang[a[i].fi] = max(mahang[a[i].fi], a[i].se);
		cheophai[a[i].fi + a[i].se] = max(cheophai[a[i].fi + a[i].se], min(k - a[i].se, a[i].fi));
	}
	cheotrai.clear();
	cheophai.clear();
	mahang.clear();
	macot.clear();
	for(int i = n - 1; i >= 0; i--) {
		m3[m[ {a[i].fi,a[i].se}]] = i;
		a[i].fi = k - a[i].fi;
		a[i].se = k - a[i].se;
		c[i] = min(a[i].fi, a[i].se) - cheotrai[abs(a[i].fi - a[i].se)] + a[i].fi - macot[a[i].se] + a[i].se - mahang[a[i].fi] + min(k - a[i].se, a[i].fi) - cheophai[a[i].fi + a[i].se];
		cheotrai[abs(a[i].fi - a[i].se)] = max(cheotrai[abs(a[i].fi - a[i].se)], min(a[i].fi, a[i].se));
		macot[a[i].se] = max(macot[a[i].se], a[i].fi);
		mahang[a[i].fi] = max(mahang[a[i].fi], a[i].se);
		cheophai[a[i].fi + a[i].se] = max(cheophai[a[i].fi + a[i].se], min(k - a[i].se, a[i].fi));
	}
	for(int i = 0; i < n; i++) cout << c[m3[i]] + b[m2[i]] - n << '\n';
	return 0;
}
/*
==================================+
INPUT:                            |
------------------------------    |
8 7
1 1
1 7
3 4
4 4
4 7
6 2
7 7
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |
14
11
20
16
16
19
15
------------------------------    |
==================================+
*/
