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
const int N = 9 + 1e6;
const int INF = 1e9;

int32_t main() {
#define TASKNAME "SPIRAL"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	int tbegin = clock();
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	int m, n;
	cin >> m >> n;
	int a[m][n];
	int dong = m, cot = n, k = 1, p = 0, i, j;
	while(k <= m*n) {
		for(i = p; i < cot; i++) /*Loop to access the first row of the array*/
			a[p][i] = k++;
		for(i = p+1; i < dong; i++) /*Loop tp access the last column of the array*/
			a[i][cot-1] = k++;
		if ( p != dong-1) {
			for(i = cot-2; i >=p; i--) /*Loop to access the last row of the array*/
				a[dong-1][i] = k++;
		}
		if(p!=cot-1) {
			for(i = dong-2; i > p; i--) /*Loop to access the first column of the array*/
				a[i][p] = k++;
		}
		p++;
		dong --;
		cot --;
	}
	for(i = 0; i < m; i++) {
		for(j = 0; j < n; j++)
			cout << a[i][j] << " ";
		cout << endl;
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
