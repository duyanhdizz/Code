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
const int N = 9 + 1e4;
const int INF = 1e9;

int a[N];

int32_t main() {
#define TASKNAME "BALLSHOT"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	int tbegin = clock();
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	int n;
	cin >> n;
	FOR(i, 1, n) cin >> a[i];
	a[++n] = -1;
	int vtri = 1;
	int cnt = 1;
	vector<pii> ans;
	FOR(i, 2, n) {
		if(a[i] == a[i - 1]) {
			cnt++;
		} else {
			ans.pb({a[i - 1], i - vtri});
			vtri = i;
			cnt = 1;
		}
	}
	while(true) {
		if(ans.size() == 0) break;
		int res = -1;
		int pos;
		REP(i, 0, ans.size()) {
			if(ans[i].se >= 3 && ans[i].se > res) {
				res = ans[i].se;
				pos = i;
			}
		}
		if(res < 0) break;
		else {
			ans.erase(ans.begin() + pos);
			while(true) {
				if(pos <= 0) break;
				if(ans[pos].fi == ans[pos - 1].fi) {
					if(ans[pos].se + ans[pos - 1].se >= 3) {
						ans.erase(ans.begin() + pos - 1, ans.begin() + pos + 1);
						pos--;
					} else {
						ans[pos - 1].se += ans[pos].se;
						ans.erase(ans.begin() + pos);
						break;
					}
				} else break;
			}
		}
	}
	ll sum = 0;
	REP(i, 0, ans.size()) sum += ans[i].se;
	cout << sum << '\n';
	REP(i, 0, ans.size()) {
		FOR(j, 1, ans[i].se) cout << ans[i].fi << ' ';
	}
	cerr << '\n' << "Runtime: " << (clock() - tbegin) << " ms\n";
	return 0;
}
/*
==================================+
INPUT:                            |
------------------------------    |
19
5 1 3 3 2 2 2 2 3 1 1 5 6 4 4 4 4 4 7
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |

------------------------------    |
==================================+
*/