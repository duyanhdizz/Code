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
const int N = 9 + 1e6;
const int INF = 1e9;

int n;

int32_t main() {
#define TASKNAME ""
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n;
	int a[n][n];
	int dong = n, cot = n, k = 1, p = 0, i, j;
	while(k <= n * n) {
		for(i = p; i < cot; i++) /*Loop to access the first row of the array*/
			a[p][i] = k++;
		for(i = p + 1; i < dong; i++) /*Loop tp access the last column of the array*/
			a[i][cot - 1] = k++;
		if (p != dong - 1) {
			for(i = cot - 2; i >= p; i--) /*Loop to access the last row of the array*/
				a[dong - 1][i] = k++;
		}
		if(p != cot - 1) {
			for(i = dong - 2; i > p; i--) /*Loop to access the first column of the array*/
				a[i][p] = k++;
		}
		p++;
		dong--;
		cot--;
	}
	REP(i, 0, n) {
		REP(j, 0, n) {
			cout << a[i][j] << ' ';
		}
		cout << '\n';
	}
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
