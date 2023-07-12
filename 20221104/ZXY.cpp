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

ll n, m, a[N];

bool check(ll s) {
	ll soluong = 0, tong = 0;
	for(int i = 1; i <= n; i++) {
		if(tong + a[i] > s) {
			soluong++;
			tong = a[i];
		}
		else tong += a[i];
	}
	return (soluong + 1) <= m;
}

int32_t main() {
#define TASKNAME "ZXY"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	ll l = 0, r = 1e14;
	while(l < r) {
		ll mid = (l + r) / 2;
		if(check(mid) == true) {
			r = mid;
		} else l = mid + 1;
	}
	cout << l;
	return 0;
}
/*
INPUT
10 5
1
1
26
7
9
21
10
5
12
13
OUTPUT
28
*/
