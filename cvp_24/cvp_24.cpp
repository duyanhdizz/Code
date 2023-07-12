#include<bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i=(a), _b=(b); i<_b; ++i)
#define fi first
#define se second
#define pb push_back
#define ll long long
#define all(a) a.begin(),a.end()
const int N = 9 + 1e6;
const int INF = 1e9;

ll n, q, a[N];
map<ll,ll> d;

int32_t main() {
#define TASKNAME "A"
    ios_base::sync_with_stdio (0);
    cin.tie (0);
    if ( fopen( TASKNAME".inp", "r" ) ) {
        freopen (TASKNAME".inp", "r", stdin);
        freopen (TASKNAME".out", "w", stdout);
    }
    cin >> n >> q;
    while(q--) {
    	ll i, k;
    	cin >> i >> k;
    	a[i] += k;
    	d[i]++;
	}
	ll res = 0;
	for(ll i = 1; i <= n; i++) {
		ll r = res;
		res += a[i];
		a[i] += r;
		res -= d[i];
		d[i + 1] += d[i];
	}
	for(ll i = 1; i <= n; i++) cout << a[i] << ' ';
    return 0;
}
