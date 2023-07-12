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

int t;
int m[9 * 18 + 1];

bool check(int n) {
	memset(m, 0, sizeof m);
	int sum = n;
	//m[sum]++;
	int sum_ = 0;
	while(sum > 0) {
		sum_ += (sum % 10) * (sum % 10);
		sum /= 10;
	}
	if(sum_ == 1) return false;
	m[sum = sum_]++;
	while(m[sum] == 1) {
		int sum_ = 0;
		while(sum > 0) {
			sum_ += (sum % 10) * (sum % 10);
			sum /= 10;
		}
		if(sum_ == 1) return false;
		m[sum = sum_]++;
	}
	return true;
}

void solve() {
	int l, r;
	cin >> l >> r;
	int ans = 0;
	FOR(i, l, r) {
		if(check(i)) {
			ans++;
		}
	}
	cout << ans << '\n';
}

int32_t main() {
#define TASKNAME "pearlnum"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> t;
	while(t--)
		solve();
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
