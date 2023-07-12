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
const int N = 9 + 1e6;
const int INF = 1e9;

void SaKaTa() {
	int n;
	cin >> n;
	vector<int> a(n);
	each(x, a) cin >> x;
	vector<int> dp(n, 1);
	vector<int> p(n, -1);
	int len = 1;
	int last = 0;
	FOR(i, 1, n - 1) {
		FOR(j, 0, i - 1) {
			if(a[i] >= a[j] && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
				p[i] = j;
			}
		}
		if (dp[i] > len) {
			len = dp[i];
			last = i;
		}
	}

	vector<int> ans;
	while(last != -1) {
		ans.push_back(a[last]);
		last = p[last];
	}
	reverse(all(ans));
	each(x, ans) cout << x << ' ';
}

int32_t main() {
#define TASKNAME "DC"
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
