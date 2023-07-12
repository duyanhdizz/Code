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

int n, step, dpL[N], dpR[N], a[N];
bool check[N];

void sang() {
	fill(check, check + N, true);
	check[0] = check[1] = false;
	for(int i = 2; i <= N; i++) {
		if(check[i]) {
			for(int j = 2 * i; j <= N; j += i) check[j] = false;
		}
	}
}

int32_t main() {
#define TASKNAME "fc143_subprime"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	sang();
	cin >> n >> step;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) {
		if(a[i] != 1) dpL[i] = 0;
		else dpL[i] = (i - step > 0) ? dpL[i - step] + 1 : 1;
	}
	for(int i = n; i >= 1; i--) {
		if(a[i] != 1) dpR[i] = 0;
		else dpR[i] = (i + step <= n) ? dpR[i + step] + 1 : 1;
	}
	ll ans = 0;
	dpR[n + 1] = 0;
	for(int i = 1; i <= n; i++)
		if(check[a[i]])
			ans += (dpL[max(i - step, 0)] + 1) * (dpR[min(i + step, n + 1)] + 1) - 1;
	cout << ans;
	return 0;
}
/*
==================================+
INPUT:                            |
------------------------------    |
3 2
1 2 1
---
3 1
1 2 1
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |
0
--- 
3
------------------------------    |
==================================+
*/
