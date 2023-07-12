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
#define int long long
#define all(a) a.begin(),a.end()
typedef pair<int, int> pii;
const int N = 9 + 2e7;
const int INF = 1e9;

int n;
vector<pair<int, int>> v;

int32_t main() {
#define TASKNAME "cust"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n;
	FOR(i, 1, n) {
		int x, y;
		cin >> x >> y;
		v.pb({x, false});
		v.pb({y, true});
	}
	sort(all(v));
	int ans = 0, solg = 0, i = 1, vtri;
	each(x, v) {
		if(x.se == false) {
			solg++;
			if(solg > ans) {
				ans = solg;
				vtri = i;
			}
		} else solg--;
		i++;
	}
	cout << vtri << ' ' << ans;
	return 0;
}
/*
==================================+
INPUT:                            |
------------------------------    |
3
1 5
2 4
5 6
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |

------------------------------    |
==================================+
*/