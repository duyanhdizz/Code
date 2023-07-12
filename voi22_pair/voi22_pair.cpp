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

int n, d, a[N];
map<int, int> m, mm, mmm;

int32_t main() {
#define TASKNAME "PAIR"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n >> d;
	ll res = 0;
	for(int i = 0; i < n; i++) cin >> a[i], res += a[i], m[a[i]]++, mm[a[i]]++, mmm[a[i]]++;
	res /= n;
	res *= 2;
	ll ans = 0, anss = 0, ansss = 0;
	for(int i = 0; i < n; i++) {
		if(m[res - a[i]] > 0) {
			if(res == 2 * a[i] && m[res - a[i]] <= 1) continue;
			m[a[i]]--;
			m[res - a[i]]--;
			ans++;
		}
	}
	res--;
	for(int i = 0; i < n; i++) {
		if(mm[res - a[i]] > 0) {
			if(res == 2 * a[i] && mm[res - a[i]] <= 1) continue;
			mm[a[i]]--;
			mm[res - a[i]]--;
			anss++;
		}
	}
	res += 2;
	for(int i = 0; i < n; i++) {
		if(mmm[res - a[i]] > 0) {
			if(res == 2 * a[i] && mmm[res - a[i]] <= 1) continue;
			mmm[a[i]]--;
			mmm[res - a[i]]--;
			ansss++;
		}
	}
	cout << max({ans, anss, ansss});
	//cout << ans;
	return 0;
}
/*
==================================+
INPUT:                            |
------------------------------    |
7 1
9 1 2 4 5 6 8
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |
3
------------------------------    |
==================================+
*/
