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
const int N = 2106 + 1e6;
const int INF = 2106 + 1e9;

void SaKaTa() {
	int n, m;
	cin >> n >> m;
	vector<int> _, __;
	FOR(i, 1, n) {
		int x;
		cin >> x;
		if(x > 0) _.pb(x);
		else __.pb(x);
	}
	sort(all(_));
	sort(all(__), greater<int>());
	int ans = 0;
	int i = 0;
	while(i < _.size()) {
		if(i + m - 1 < _.size()) {
			ans += _[i + m - 1] * 2;
			i += m;
		} else {
			ans += _[_.size() - 1] * 2;
			break;
		}
	}
	i = 0;
	while(i < __.size()) {
		if(i + m - 1 < __.size()) {
			ans += abs(__[i + m - 1]) * 2;
			i += m;
		} else {
			ans += abs(__[__.size() - 1]) * 2;
			break;
		}
	}
	cout << ans;
}

int32_t main() {
#define TASKNAME "B"
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
