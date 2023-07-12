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
const int MOD = 1e9 + 7;

int n, k;
ll a[N];

int32_t main() {
#define TASKNAME "MinGroup"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n;
	ll res = 0;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] += a[i - 1];
	}
	ll ans = INF;
	res = a[n];
	for(int i = res; i < n; i++) ans = min(ans, a[i] - a[i - res]);
	cout << res - ans;
	return 0;
}
/*
INPUT
5
1 0 1 0 1
1 1 2 2 3
---
6
1 0 1 0 1 1
1 1 2 2 3 4
OUTPUT
2
---
2
*/