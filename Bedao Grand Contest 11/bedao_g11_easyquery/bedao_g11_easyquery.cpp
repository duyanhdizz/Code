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
const int N = 9 + 1e6;
const int INF = 1e9;

int n, q, a[N];

struct Item {
	int in, l, r, x;
}

vector<Item> v;

struct It {
	int in, ii;
}

vector<It> vv;

int32_t main() {
#define TASKNAME "bedao_g11_easyquery"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n >> q;
	FOR(i, 1, n) cin >> a[i];
	FOR(j, 1, q) {
		int test;
		cin >> test;
		if(test == 1) {
			int l, r, x;
			cin >> l >> r >> x;
			v.pb({j, l, r, x});
			FOR(i, l, r) a[i] += x;
		} else if(test == 3) {
			ll sum = 0;
			int l, r;
			cin >> l >> r;
			FOR(i, l, r) sum += a[i];
			cout << sum << '\n';
		} else {
			int i;
			cin >> i;
            
		}
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
