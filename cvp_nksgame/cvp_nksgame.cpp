#include<bits/stdc++.h>
#include <cstdio>
#include <algorithm>
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
const int N = 9 + 1e5;
const int INF = 1e9;

int n, a[N], b[N];

int bsearch( int * a, int x ) {
	if ( a[0] > x ) return a[0];
	if ( a[n-1] < x ) return a[n - 1];
	int l = 0, h = n - 1;
	while( l <= h ) {
		int mid = (l + h)/2;
		if ( a[mid] == x ) return a[mid];
		else if ( a[mid] < x ) l = mid + 1;
		else h = mid - 1;
	}
	if ( abs(a[l] - x) < abs(a[h] - x) ) return a[l];
	return a[h];
}


int32_t main() {
#define TASKNAME "cvp_nksgame"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n;
	FOR(i, 0, n - 1) cin >> a[i];
	FOR(i, 0, n - 1) cin >> b[i];
	sort(b, b + n);
	int res = INF;
	REP(i, 0, n) {
		int x = bsearch(b, -a[i]);
		int x2 = abs(a[i] + x);
		if ( x2 == 0 ) return cout << '0', 0;
		if ( x2 < res ) res = x2;
	}
	cout << res;
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
