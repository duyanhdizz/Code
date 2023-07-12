#include<bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i=(a), _b=(b); i<_b; ++i)
#define fi first
#define se second
#define pb push_back
#define ll long long
#define all(a) a.begin(),a.end()
typedef pair<int, int> pii;
const int N = 9 + 1e5;
const int INF = 1e9;

int n, t;
ll a[N], bit[N];

void update(int id, ll val) {
	for(; id <= n; id += id & (-id))
		bit[id] += val;
}

ll sum(int id) {
	ll res = 0;
	for(; id > 0; id -= id & (-id))
		res += bit[id];
	return res;
}

int32_t main() {
#define TASKNAME "fc109_swap"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n >> t;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		update(i, a[i]);
	}
	while(t--) {
		int k, u, v;
		cin >> k >> u >> v;
		if(k == 0) {
			update(u, a[v] - a[u]);
			update(v, a[u] - a[v]);
			swap(a[u], a[v]);
		} else cout << sum(v) - sum(u - 1) << '\n';
	}
	return 0;
}
