#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#pragma GCC optimize("Ofast,O3,unroll-loops")
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

int n, k, a[N][N];

int32_t main() {
#define TASKNAME "PHANTHUONG"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n >> k;
	FOR(i, 1, n) {
		FOR(j, 1, n) {
			cin >> a[i][j];
			a[i][j] += a[i][j - 1];
		}
	}
	int i = 1;
	ll ans = -INF;
	while(i + k - 1 <= n) {
		for(int j = 1; j + k - 1 <= n; j++) {
			ll sum = 0;
			int z = i;
			while(z <= i + k - 1) sum += (a[z][j + k - 1] - a[z][j - 1]), z++;
			ans = max(ans, sum);
		}
		i++;
	}
	cout << ans;
	return 0;
}
/*
==================================+
INPUT:                            |
------------------------------    |
4 3
1 9 1 1 
9 9 9 9 
1 9 9 9 
1 9 9 14
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |

------------------------------    |
==================================+
*/