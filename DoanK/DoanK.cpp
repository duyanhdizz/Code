#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast","unroll-loops")
#define FOR(i, a, b) for(int i=(a), _b=(b); i<_b; ++i)
#define fi first
#define se second
#define pb push_back
#define int long long
#define all(a) a.begin(),a.end()
typedef pair<int, int> pii;
const int N = 9 + 1e6;
const int INF = 1e9;

int n, k, a[N], sum[N];

bool check(int mid) {
	for(int i = mid - 1; i <= n; i++)
		if(sum[i] - sum[i - mid + 1] > k)
			return false;
	return true;
}

int32_t main() {
#define TASKNAME "DoanK"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n >> k;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		sum[i] += (sum[i - 1] + a[i]);
	}
	int lo = 1, hi = n;
	int res = 0;
	while(lo <= hi) {
		int mid = (lo + hi + 1) / 2;
		if(check(mid) == true) {
			lo = mid + 1;
			res = max(res, mid);
		} else hi = mid - 1;
	}
	if(res != 1) cout << res - 1;
	else cout << -1;
	return 0;
}
/*
INPUT
4 8
1 2 3 4
---
4 8
1 2 10 4
OUTPUT
2
---
-1
*/