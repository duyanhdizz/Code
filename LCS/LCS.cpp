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
const int N = 9 + 5e3;
const int INF = 1e9;

int dp[N][N];

void SaKaTa() {
	string s, t;
	cin >> s >> t;
	int n = s.size(), m = t.size();
	FOR(i, 0, n) {
		FOR(j, 0, m) {
			if(!i || !j) {
				dp[i][j] = 0;
				continue;
			}
			if(s[i - 1] == t[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			} else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	string ans = "";
	while(n && m) {
		if(s[n - 1] == t[m - 1]) {
			ans += s[n - 1];
			n--;
			m--;
		} else if(dp[n - 1][m] > dp[n][m - 1]) n--;
		else m--;
	}
	reverse(all(ans));
	cout << ans;
}

int32_t main() {
#define TASKNAME "LCS"
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
