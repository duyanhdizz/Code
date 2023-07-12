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

int n, m, a[N];

int32_t main() {
#define TASKNAME ""
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		if(a[i] != 0) a[i] = 1;
		a[i] += a[i - 1];
	}
	while(m--) {
		int l, r;
		cin >> l >> r;
		cout << (r - l + 1) - (a[r] - a[l - 1]) << '\n';
	}
	return 0;
}
/*
INPUT
5 2
1 0 1 0 0
1 5
3 4
OUTPUT
3 1
*/