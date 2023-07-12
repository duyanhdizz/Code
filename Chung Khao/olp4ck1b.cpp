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
typedef pair<ll, ll> pii;
const int N = 9 + 1e6;
const int INF = 1e9;

struct GIFT {
	ll w, v, c;
};

void IU() {
	ll n, s;
	cin >> n >> s;
	vector<GIFT> a(n);
	vector<pii> pick, don_pick;
	ll sum = 0, chiudung = 0;
	each(x, a) {
		cin >> x.w >> x.v >> x.c;
		if(x.c == 0) don_pick.pb({x.w, x.v});
		else pick.pb({x.w, x.v}), sum += x.v, chiudung += x.w;
	}
	ll ans = sum;
	each(x, pick) {
		each(x_x, don_pick) {
			if(chiudung + x_x.fi - x.fi <= s) {
				ans = max(ans, sum + x_x.se - x.se);
			}
		}
	}
	cout << ans;
}

int32_t main() {
#define TASKNAME "olp4ck1b"
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
