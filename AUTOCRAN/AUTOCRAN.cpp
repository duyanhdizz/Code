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

int n, h[N];
map<int, int> m;

int32_t main() {
#define TASKNAME "AUTOCRAN"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	int tbegin = clock();
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n;
	vector<int> a(n);
	each(x, a) cin >> x;
	FOR(i, 0, n - 1) {
		if(i == 0) {
			if(a[i] <= a[i + 1]) {
				m[i]++;
			}
			continue;
		}
		if(i == n - 1) {
			if(a[i] <= a[i - 1]) {
				m[i]++;
			}
			continue;
		}
		if(a[i] <= a[i + 1]) {
			m[i]++;
		}
		if(a[i] <= a[i - 1]) {
			m[i]++;
		}
	}
	int ans = 0;
	vector<int> DA;
	while(a.size() != 1) {
		int mi = INF;
		int pos;
		FOR(i, 0, a.size() - 1) {
			if(m[i] < mi) {
				mi = m[i];
				pos = i;
			}
		}
//		cout << mi;
		vector<int> adu;
		if(a[pos - 1] <= a[pos]) adu.pb(m[pos - 1] - 1);
		if(a[pos + 1] <= a[pos]) adu.pb(m[pos + 1] - 1);
		if(pos + 2 <= a.size() - 1) FOR(i, pos + 2, a.size() - 1) adu.pb(m[i]);
		DA.pb(pos);
		ans += m[pos];
		a.erase(a.begin() + pos, a.begin() + pos + 1);
		int p = -1;
		FOR(i, pos - 1, a.size() - 1) m[i] = adu[++p];
//		each(x, a) cout << x;
	}
	cout << ans << '\n';
	each(x, DA) cout << x << ' ';
	cerr << '\n' << "Runtime: " << (clock() - tbegin) << " ms\n";
	return 0;
}
/*
==================================+
INPUT:                            |
------------------------------    |
6
1 1 2 2 3 3
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |
3
2 1 4 3 5 6
------------------------------    |
==================================+
*/
