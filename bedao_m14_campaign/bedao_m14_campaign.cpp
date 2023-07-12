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
const int N = 9 + 1e6;
const int INF = 1e9;

int n;
ll sum[N], mi[N];

int32_t main() {
#define TASKNAME "bedao_m14_campaign"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n;
	vector<pii> v(n);
	for(int i = 0; i < n; i++) cin >> v[i].fi >> v[i].se;
	sort(all(v));
	ll ans = 0;
	mi[0] = v[0].se;
	for(int i = 0; i < n; i++) {
		//ll res = INF;
		if(i > 0) mi[i] = min(mi[i - 1], v[i].se);
		for(int j = 0; j <= i; j++) sum[j] += v[i].se;
		sum[i] += mi[i];
	}

	for(int i = 0; i < n; i++) {
		if(i > 0) sum[i] = max(sum[i], sum[i - 1]);
		ans = max(ans, sum[i] - v[i].fi);
		//cout << sum[i] - v[i].fi;
	}
	cout << ans;
	return 0;
}
/*
INPUT
3
2 3
10 2
4 5
OUTPUT
6
*/
