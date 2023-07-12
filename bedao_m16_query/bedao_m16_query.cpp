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
const int N = 9 + 5e5;
const int INF = 1e9;

int n, q, a[N];

int32_t main() {
#define TASKNAME "bedao_m16_query"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	int tbegin = clock();
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n >> q;
	FOR(i, 1, n) cin >> a[i];
	while(q--) {
		int test;
		cin >> test;
		if(test == 3) {
			int l, r;
			cin >> l >> r;
			int res = a[l];
			FOR(i, l + 1, r) res |= a[i];
			cout << res << '\n';
		} else {
			int l, r, x;
			cin >> l >> r >> x;
			if(test == 2) {
				FOR(i, l, r) a[i] = x;
			} else {
				FOR(i, l, r) a[i] &= x;
			}
		}
	}
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
