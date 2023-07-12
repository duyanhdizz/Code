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
const int MOD = 3210121;

string s, t;
int dp[123][123][123][123];

int DA(int la, int ra, int lb, int rb) {
	if(la > ra && lb > rb || la > ra && lb == rb || la == ra && lb > rb) {
		return 1;
	}
	int &res(dp[la][ra][lb][rb]);
	if(res != -1) {
		return res;
	}
	res = 0;
	if(la < ra && s[la] == s[ra]) {
		res = (res + DA(la + 1, ra - 1, lb, rb)) % MOD;
	}
	if(lb < rb && s[lb] == t[lb]) {
		res = (res + DA(la, ra, lb + 1, rb - 1)) % MOD;
	}
	if(la <= ra && lb <= rb) {
		if(s[la] == t[rb]) {
			res = (res + DA(la + 1, ra, lb, rb - 1)) % MOD;
		}
		if(s[lb] == t[ra]) {
			res = (res + DA(la, ra - 1, lb + 1, rb)) % MOD;
		}
	}
	return res;
}

int32_t main() {
#define TASKNAME "tpcpalin"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> s >> t;
	s = '*' + s;
	t = '*' + t;
	memset(dp, -1, sizeof dp);
	cout << DA(1, s.size() - 1, 1, t.size() - 1);
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
