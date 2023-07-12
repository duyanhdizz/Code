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
const ll MOD = 1e9 + 7;

int t;

ll nhan(ll a, ll b, ll m) {
    a %= m;
    ll res = 0;
    while (b > 0) {
        if (b & 1)
            res = (res + a) % m;
        a = (a + a) % m;
        b >>= 1;
    }
    return res;
}

ll power(ll a, ll b, ll m) {
	a %= m;
	ll res = 1;
	while (b > 0) {
		if (b & 1)
			res = nhan(res, a, m);
		a = nhan(a, a, m);
		b >>= 1;
	}
	return res;
}
void solve() {
	ll a, b, n;
	cin >> a >> b >> n;
	ll ans;
	if (a < b) swap(a, b);
	ll res = a - b;
	if (res == 0) {
		ans = power(a, n, MOD);
		ans += power(b, n, MOD);
		ans %= MOD;
	} else {
		ll x = power(a, n, res);
		x += power(b, n, res);
		x %= res;
		//cout << x;
		ans = __gcd(x, res);
		ans %= MOD;
	}
	cout << ans << '\n';
}

int32_t main() {
#define TASKNAME "GCDMOD"
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
2
10 1 1
9 1 5
OUTPUT
1
2
*/
