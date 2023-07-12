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
const int N = 9 + 1e2;
const int INF = 1e9;

int n, dem1chuso1[N], dem1chuso2[N], dem1chuso3[N];
int dem2chuso1[N][N], dem2chuso2[N][N], dem2chuso3[N][N];
int demhet[N][N][N];

int32_t main() {
#define TASKNAME "ONETHIRD"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	int tbegin = clock();
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n;
	ll res = 0;
	FOR(i, 1, n) {
		int a, b, c;
		cin >> a >> b >> c;
		res += dem1chuso1[a] - dem2chuso1[a][b] - dem2chuso3[c][a];
		res += dem1chuso2[b] - dem2chuso1[a][b] - dem2chuso2[b][c];
		res += dem1chuso3[c] - dem2chuso3[c][a] - dem2chuso2[b][c];
		res += 3 * demhet[a][b][c];
		dem1chuso1[a]++;
		dem1chuso2[b]++;
		dem1chuso3[c]++;
		dem2chuso1[a][b]++;
		dem2chuso2[b][c]++;
		dem2chuso3[c][a]++;
		demhet[a][b][c]++;
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
