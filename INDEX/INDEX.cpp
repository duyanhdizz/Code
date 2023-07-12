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
const int N = 9 + 5e2;
const int INF = 1e9;

int n;
map<int, bool> m;

struct INDEX {
	int h, bd;
};

INDEX a_a[N];
deque<int> g[N];
vector<pii> ans;

int32_t main() {
#define TASKNAME "INDEX"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n;
	vector<INDEX> a(n);
	each(x, a) cin >> x.h >> x.bd;
	sort(all(a), [&] (INDEX l, INDEX r) {
		if(l.h == r.h) return l.bd < r.bd;
		return l.h < r.h;
	});
	each(x, a) g[x.h].pb(x.bd);
	int pos = -1;
	FOR(i, 0, a.size() - 1) {
		if(i == 0 || a[i].h != a[i - 1].h) {
			pos++;
			a_a[pos].h = g[a[i].h].size();
			a_a[pos].bd = a[i].h;
		}
	}
	int danhdau = 0;
	REP(i, 0, a.size()) {
		sort(a_a, a_a + pos + 1, [&] (INDEX l, INDEX r) {
			if(l.h == r.h) return l.bd < r.bd;
			return l.h > r.h;
		});
		int p = 0;
		while(danhdau == a_a[p].bd) p++;
		danhdau = a_a[p].bd;
		ans.pb({danhdau, g[danhdau].front()});
		g[danhdau].pop_front();
		a_a[p].h--;
	}
	each(x, ans) cout << x.fi << ' ' << x.se << '\n';
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
