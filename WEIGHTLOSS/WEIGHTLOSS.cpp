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

int n, k, m[N];

int32_t main() {
#define TASKNAME "WEIGHTLOSS"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	int tbegin = clock();
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n >> k;
	FOR(i, 1, n) cin >> m[i];
	vector<int> v;
	FOR(i, 1, n - 1) v.pb(abs(m[i] - m[i + 1]));
	sort(all(v));
	int solan = k / n, le = k % n;
	int ans = v[v.size() - 1] / pow(2, (solan + 1));
	FOR(i, 0, v.size() - le - 1) ans = max(ans, v[i] / (int)pow(2, solan));
	cout << ans;
	cerr << '\n' << "Runtime: " << (clock() - tbegin) << " ms\n";
	return 0;
}
/*
==================================+
INPUT:                            |
------------------------------    |
3 1
100 200 230
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |
50
------------------------------    |
==================================+
*/
