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

struct BUFFET {
	int p, f, t;
};

map<int, int> d, cnt;

int32_t main() {
#define TASKNAME "BUFFET"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	int tbegin = clock();
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	int m, n, p, q;
	cin >> m >> n >> p >> q;
	vector<BUFFET> a(p);
	each(x, a) cin >> x.p >> x.f >> x.t;
	vector<int> mon;
	FOR(i, 1, q) {
		int ng, time;
		cin >> ng >> time;
		each(x, a) {
			if(x.p == ng && time > x.t) {
				d[x.f]++;
				if(d[x.f] == q) mon.pb(x.f);
			}
		}
	}
	each(x, mon) cerr << x << ' ';
	cerr << '\n';
	int ans = 0;
	each(x, mon) {
		each(p, a) {
			if(x == p.f) {
				cnt[p.p]++;
				if(cnt[p.p] == 1) ans++;
			}
		}
	}
	cout << ans;
	cerr << '\n' << "Runtime: " << (clock() - tbegin) << " ms\n";
	return 0;
}
/*
==================================+
INPUT:                            |
------------------------------    |
6 8 10 2
1 4 10
4 5 4
5 6 2
1 6 2
5 7 8
3 5 2
3 3 2
4 4 8
1 7 3
4 7 5
1 10
5 8
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |
3 --- WA
2 --- AC
------------------------------    |
==================================+
*/
