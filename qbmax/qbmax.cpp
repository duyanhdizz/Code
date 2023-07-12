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
const int N = 9 + 1e2;
const int INF = 1e9;

int a[N][N], dp[N][N];

void SaKaTa() {
	int n, m;
	cin >> m >> n;
	FOR(i, 1, m) {
		FOR(j, 1, n) {
			cin >> a[i][j];
		}
	}
	memset(dp, -INF, sizeof dp);
	FOR(i, 1, m) dp[0][i] = a[i][0];
	FOR(j, 1, n) {
		FOR(i, 1, m) {
			dp[j][i] = max({dp[j - 1][i + 1], dp[j - 1][i - 1], dp[j - 1][i]}) + a[i][j];
		}
	}
	int ans = -INF;
	FOR(i, 1, m) ans = max(ans, dp[n][i]);
	cout << ans;
}

int32_t main() {
#define TASKNAME "qbmax"
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
