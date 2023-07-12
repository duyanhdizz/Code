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
const int N = 9 + 1e5;
const int INF = 1e9;

int k, n, ans[N];
vector<pii> v;
map<pii, bool> m;

int32_t main() {
#define TASKNAME "QUEENS_sub1"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> k >> n;
	for(int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.pb({a, b});
		m[ {a, b}] = true;
	}
	for(int i = 0; i < n; i++) {
		// ngang
		int mi = 1, ma = k;
		bool ktra = false, ktraa = false;
		for(int j = 0; j < n; j++) {
			if(i != j && v[i].fi == v[j].fi) {
				if(v[j].se < v[i].se) mi = max(mi, v[j].se), ktra = true;
				if(v[j].se > v[i].se) ma = min(ma, v[j].se), ktraa = true;
			}
		}
		//cout << ktraa << '\n';
		ans[i] += (ma - mi - ktra - ktraa);
		// doc
		mi = 1, ma = k;
		ktra = false, ktraa = false;
		for(int j = 0; j < n; j++) {
			if(i != j && v[i].se == v[j].se) {
				if(v[j].fi < v[i].fi) mi = max(mi, v[j].fi), ktra = true;
				if(v[j].fi > v[i].fi) ma = min(ma, v[j].fi), ktraa = true;
			}
		}
		ans[i] += (ma - mi - ktra - ktraa);
		// cheo trai -> phai
		int res = 0;
		int trai = v[i].fi, phai = v[i].se;
		while(trai > 1 && phai < k) {
			trai--;
			phai++;
			if(m[ {trai, phai}] == true) break;
			res++;
		}
		trai = v[i].fi, phai = v[i].se;
		while(trai < k && phai > 1) {
			trai++;
			phai--;
			if(m[ {trai, phai}] == true) break;
			res++;
		}
		ans[i] += res;
		// cheo phai -> trai
		res = 0;
		trai = v[i].fi, phai = v[i].se;
		while(trai > 1 && phai > 1) {
			trai--;
			phai--;
			if(m[ {trai, phai}] == true) break;
			res++;
		}
		trai = v[i].fi, phai = v[i].se;
		while(trai < k && phai < k) {
			trai++;
			phai++;
			if(m[ {trai, phai}] == true) break;
			res++;
		}
		ans[i] += res;
	}
	for(int i = 0; i < n; i++) cout << ans[i] << '\n';
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
