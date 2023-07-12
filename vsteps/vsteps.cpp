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
const int N = 9 + 1e5;
const int INF = 1e9;

int dp[N];

const int MOD = 14062008;

void SaKaTa() {
	int n, k;
	cin >> n >> k;
	dp[1] = 1;
	dp[2] = 1;
	FOR(i, 1, k) {
		int a;
		cin >> a;
		dp[a] = -1;
	}
	if(dp[1] == 0 && dp[2] == 0) {
		cout << 0;
		return;
	}
	FOR(i, 3, n) {
		if(dp[i] != -1) {
			if(dp[i - 1] != -1) dp[i] += dp[i - 1], dp[i] %= MOD;
			if(dp[i - 2] != -1) dp[i] += dp[i - 2], dp[i] %= MOD;
		}
	}
	cout << dp[n];
}

int32_t main() {
#define TASKNAME "vsteps"
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
