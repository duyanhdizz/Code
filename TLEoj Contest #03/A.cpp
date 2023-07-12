#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
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

int a[N];

void SaKaTa() {
	int n;
	cin >> n;
	FOR(i, 1, n) cin >> a[i];
	int i = 1;
	vector<pii> ans;
	a[n + 1] = INF;
	while(i <= n) {
		int j = i;
		vector<int> v;
		v.pb(a[j]);
		while(j <= n && a[j] >= a[j + 1]) j++, v.pb(a[j]);
		if(j >= n) break;
		sort(all(v));
		int pos = 0;
		FOR(p, i, j) a[p] = v[pos++];
		ans.pb({i, j});
		i = j + 1;
	}
	bool check = true;
	FOR(i, 1, n - 1) {
		if(a[i] >= a[i + 1]) {
			check = false;
			break;
		}
	}
	if(check == false) {
		cout << -1;
		return;
	}
	cout << ans.size() << '\n';
	each(x, ans) cout << x.fi << ' ' << x.se << '\n';
}

int32_t main() {
#define TASKNAME "A"
	ios_base::sync_with_stdio (false);
	cin.tie (nullptr);
	cout.tie (nullptr);
	int tbegin = clock();
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	int testcase = 1;
//	cin >> testcase;
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
