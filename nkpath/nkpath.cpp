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
const int N = 2106 / 10 + 1e2;
const int INF = 2106 + 1e9;

int a[N][N], f[N][N];

const int mod = 1e9;

void SaKaTa() {
	int m, n;
	cin >> m >> n;
	FOR(i, 0, m - 1) FOR(j, 0, n - 1) cin >> a[i][j];
	int res = 0;
	FOR(i, 0, m - 1)
	FOR(j, 0, n - 1) {
		FOR(u, 0, i)
		FOR(v, 0, j)
		if(u + v < i + j && v < n - 1) {
			int x = a[i][j], y = a[u][v];
			if(__gcd(x, y) > 1
			  ) f[i][j] = (f[i][j] + f[u][v]) % mod;
		}
		if(j == 0) f[i][j] = (1 + f[i][j]) % mod;
		if(j == n - 1) res = (res + f[i][j]) % mod;
	}
	cout << res;
}

int32_t main() {
#define TASKNAME ""
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
