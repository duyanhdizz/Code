#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast","unroll-loops")
#define FOR(i, a, b) for(int i=(a), _b=(b); i<_b; ++i)
#define fi first
#define se second
#define pb push_back
#define ll long long
#define all(a) a.begin(),a.end()
typedef pair<ll, ll> pii;
const int N = 9 + 1e7;
const int INF = 1e9;

ll n, m, p[N];
vector<pii> v;

int32_t main() {
#define TASKNAME "bedao_m08_pairs"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n >> m;
	for (int i = 1; i <= n; i++) p[i] = i;
	for (int i = 2; i * i <= n; i++) {
		for (int j = i * i; j <= n; j += i * i)
			p[j] = j / (i * i);
	}
	for(int i = 1; i <= n; i++) v.pb({p[i], i});
	sort(all(v));
	ll i = 0;
	ll res = 0;
	while(i < n) {
		ll j = i + 1;
		while(j < n && v[j].fi == v[i].fi && v[j].se * v[i].se <= m) {
			j++;
		}
		res += (j - i - 1ll) * (j - i) / 2ll;
		i = j;
	}
	cout << res;
	//for(int i = 1; i <= n; i++) cout << p[i] << '\n';
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
