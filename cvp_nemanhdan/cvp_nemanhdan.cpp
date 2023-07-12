#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#pragma GCC optimize("Ofast,O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define FOR(i, a, b) for (int i = (a); i <= (int) (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= (int) (b); --i)
#define REP(i, a, b) for (int i = (a); i < (int) (b); ++i)
#define each(a, x) for (auto &a : x)
#define fi first
#define se second
#define pb push_back
#define ll unsigned long long
#define all(a) a.begin(),a.end()
typedef pair<int, int> pii;
const int N = 9 + 1e2;
const int INF = 1e9;

int n;
ll a[N], b[N], m;

bool check(ll mid) {
	ll count = 0;
	FOR(i, 1, n) count += ((mid / (b[i] + 1)) * b[i] * a[i] + mid % (b[i] + 1) * a[i]);
	return (count >= m);
}

int32_t main() {
#define TASKNAME "cvp_nemanhdan"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n >> m;
	FOR(i, 1, n) cin >> a[i] >> b[i];
	ll lo = 1, hi = 1e18;
	ll res = 1e18;
	while(lo <= hi) {
		ll mid = (lo + hi) / 2;
		if(check(mid)) {
			hi = mid - 1;
			res = min(res, mid);
		} else lo = mid + 1;
	}
	cout << res;
	return 0;
}
/*
==================================+
INPUT:                            |
------------------------------    |
2 30
2 5
1 9
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |
11
------------------------------    |
==================================+
*/
