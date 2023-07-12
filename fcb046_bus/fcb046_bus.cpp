#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#pragma GCC optimize("Ofast","unroll-loops")
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
const int N = 9 + 1e5;
const int INF = 1e9;

int n, m, p, a[N], b[N];

bool check(int Time) {
	int ans = 0;
	for(int i = 1; i <= n; i++) ans += (b[i] <= Time + a[i] - 1);
	return ans >= m;
}

int32_t main() {
#define TASKNAME "fcb046_bus"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n >> m >> p;
	for(int i = 1; i <= n; i++) cin >> a[i] >> b[i];
	int lo = 1, hi = 1e9;
	while(lo <= hi) {
		int mid = lo + hi >> 1;
		if(check(mid)) hi = mid - 1;
		else lo = mid + 1;
	}
	cout << lo;
	return 0;
}
/*
==================================+
INPUT:                            |
------------------------------    |
7 4 5
1 1
2 4
4 10
5 8
3 5
5 6
4 7
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |
3
------------------------------    |
==================================+
*/
