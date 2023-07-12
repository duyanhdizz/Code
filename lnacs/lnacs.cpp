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
const int N = 9 + 1e3;
const int INF = 1e9;

int a[N], b[N], f[N][N];

void SaKaTa() {
	int m, n;
	cin >> m >> n;
	FOR(i, 0, m - 1) cin >> a[i];
	FOR(i, 0, n - 1) cin >> b[i];
	FOR(i, 0, m) FOR(j, 0, n)
	if ( i == 0 || j == 0 ) f[i][j] = 0;
	else if ( i == 1 || j == 1 ) f[i][j] = a[i-1] == b[j-1] ? 1 : f[i-1][j] > f[i][j-1] ? f[i-1][j] : f[i][j-1];
	else f[i][j] = a[i-1] == b[j-1] ? f[i-2][j-2] + 1 : f[i-1][j] > f[i][j-1] ? f[i-1][j] : f[i][j-1];
	cout << f[m][n];
}

int32_t main() {
#define TASKNAME "lnacs"
	ios_base::sync_with_stdio (false);
	cin.tie (nullptr);
	cout.tie (nullptr);
	int tbegin = clock();
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	int testcase = 1;
//    cin >> testcase;
	while(testcase--)
		SaKaTa();
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
