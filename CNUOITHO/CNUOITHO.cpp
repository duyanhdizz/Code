#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#pragma GCC optimize("Ofast,O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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
const int N = 9 + 50;
const int INF = 1e9;

int n, k, a[N], b[N];

bool check(int x) {
	ll res = 0, carot[N];
	FOR(i, 1, n) carot[i] = a[i] + b[i] * (x - 1);
	sort(carot + 1, carot + n + 1);
	FOR(i, 1, x) res += carot[i];
	return (res <= k);
}

int32_t main() {
#define TASKNAME "CNUOITHO"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	int tbegin = clock();
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n >> k;
	FOR(i, 1, n) cin >> a[i] >> b[i];
	int lo = 1, hi = n;
	int res;
	while(lo <= hi) {
		int mid = lo + hi >> 1;
		if(check(mid)) {
			res = mid;
			lo = mid + 1;
		} else hi = mid - 1;
	}
	cout << res;
	cerr << '\n' << "Runtime: " << (clock() - tbegin) << " ms\n";
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
