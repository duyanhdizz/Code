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
#define ll unsigned long long
#define all(a) a.begin(),a.end()
typedef pair<int, int> pii;
const int N = 9 + 2e3;
const int INF = 1e9;
const ll MOD = 1e9 + 7;

ll n, k;
string s;
ll dp[N][N];

ll power(ll x, ll n) {
	if(n == 0) return 1;
	if(n == 1) return x;
	ll mid = power(x, n / 2);
	mid *= mid;
	mid %= MOD;
	if(n % 2 == 1) mid *= x;
	return mid;
}

int32_t main() {
#define TASKNAME "cvp_powstr2"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n >> k >> s;
	if(k == 1) cout << power(2, n);
	else {
		memset(dp, 0, sizeof dp);
		s = 'H' + s;
		FOR(i, 1, n) {
			FOR(j, 1, n) {
				dp[i][j] = (s[i] == s[j] ? (dp[i - 1][j - 1] + 1) % MOD : 0);
				dp[i][j] = (dp[i][j] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + MOD) % MOD;
			}
		}
		cout << (dp[n][n] + 1) % MOD;
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
