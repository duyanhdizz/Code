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
const int N = 9 + 1e4;
const int INF = 1e9;

int n, x[N], y[N];
map<int, int> cnt_x, cnt_y;

int32_t main() {
#define TASKNAME "RIGHTRIA"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	int tbegin = clock();
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n;
	FOR(i, 1, n) {
		cin >> x[i] >> y[i];
		cnt_x[x[i]]++;
		cnt_y[y[i]]++;
	}
	int ans = 0;
	FOR(i, 1, n) {
		if(cnt_x[x[i]] > 1 && cnt_y[y[i]]>1) {
			int cgv1 = -INF, cgv2 = -INF;
			FOR(j, 1, n)
			if(x[j] == x[i] && y[j] != y[i])
				cgv1 = max(cgv1, abs(y[j] - y[i]));
			FOR(j, 1, n)
			if(y[j] == y[i] && x[j] != x[i])
				cgv2 = max(cgv2, abs(x[j] - x[i]));
			ans = max(ans, cgv1 * cgv2);
		}
	}
	cout << ans;
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
