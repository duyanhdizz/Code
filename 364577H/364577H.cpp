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

int n, k;
ll a[N];
map<ll, int> ans;

ll power(ll n, ll x) {
	ll res = 1;
	while(x > 0) {
		if(x & 1) res *= n;
		n *= n;
		x >>= 1;
	}
	return res;
}

/*
void sinh(int x) {
	int v = 1;
	while(power(x, v) < 1e14) ans[power(x, v)]++, v++;
}
*/

int32_t main() {
#define TASKNAME "364577H"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> a[i], a[i] += a[i - 1];
	sinh(k);
	ll res = 0;
	for(int i = n; i >= 0; i--) {
		ll r = 1;
		while(r < 1e14) res += ans[a[i] + r], r *= k;
		ans[a[i]]++;
	}
	cout << res;
	return 0;
}
/*
==================================+
INPUT:                            |
------------------------------    |
4 2
2 2 2 2
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |
8
------------------------------    |
==================================+
*/
