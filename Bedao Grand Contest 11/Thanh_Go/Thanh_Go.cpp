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
#define ll long long
#define all(a) a.begin(),a.end()
typedef pair<int, int> pii;
const int N = 9 + 1e3;
const int INF = 1e9;

ll n, a[N], b[N], c[N];
map<ll, ll> cnt;

bool cp(ll n) {
	ll t = sqrt(n);
	return t * t == n;
}

bool kt(ll a, ll b, ll c) {
	return(a < b + c && b < c + a && c < a + b);
}

int32_t main() {
#define TASKNAME "Thanh_Go"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n;
	FOR(i, 1, n) cin >> a[i];
	FOR(i, 1, n) cin >> b[i];
	FOR(i, 1, n) cin >> c[i], cnt[c[i]]++;
	ll ans = 0;
	FOR(i, 1, n) {
		FOR(j, 1, n) {
			ll res = a[i] * a[i] + b[i] * b[i];
			ll res_2 = a[i] * a[i] - b[i] * b[i];
			res_2 = abs(res_2);
			if(cp(res) == true && kt(a[i], b[i], sqrt(res))) ans += cnt[sqrt(res)];
			if(cp(res_2) == true && kt(a[i], b[i], sqrt(res_2))) ans += cnt[sqrt(res_2)];
		}
	}
	cout << ans;
	return 0;
}
/*
==================================+
INPUT:                            |
------------------------------    |

------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |

------------------------------    |
==================================+
*/
