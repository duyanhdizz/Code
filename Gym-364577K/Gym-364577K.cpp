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

vector<int> DA;

void sinh(int num, int len, int _0) {
	if(len == 18) {
		DA.pb(num);
		return;
	}
	sinh(num * 10, len + 1, _0);
	if(_0 < 3) {
		for(int j = 1; j <= 9; j++) sinh(num * 10 + j, len + 1, _0 + 1);
	}
}

void IU() {
	sinh(0, 0, 0);
	DA.pb(1e18);
	int t;
	cin >> t;
	while(t--) {
		int l, r;
		cin >> l >> r;
		auto pos = upper_bound(all(DA), r);
		auto poss = lower_bound(all(DA), l);
		cout << pos - poss << '\n';
	}
}

int32_t main() {
#define TASKNAME "Gym-364577K"
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
		IU();
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
