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
const int N = 9 + 1e3;
const int INF = 1e9;

int n, k;
int a[N];
int m[N];

int huong(int x) {
	memset(m, 0, sizeof m);
	int len = 0;
	REP(i, 0, n) {
		len += (a[i] / x);
		m[a[i] % x]++;
	}
	len -= k;
	if(len < 0) return 0;
	int ans = min(len, k) * x, p_x = x - 1;
	while(len < k) {
		ans += min(m[p_x], (k - len)) * p_x;
		len += min(m[p_x], k - len);
		p_x--;
	}
	cerr << len << '\n';
	return ans;
}

int32_t main() {
#define TASKNAME "CHERRYHV"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	int tbegin = clock();
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n >> k;
	k /= 2;
	REP(i, 0, n) cin >> a[i];
	int ans = -15062106;
	FOR(i, 1, 1000) ans = max(ans, huong(i));
	cout << ans;
	cerr << '\n' << "Runtime: " << (clock() - tbegin) << " ms\n";
	return 0;
}
/*
==================================+
INPUT:                            |
------------------------------    |
5 4
3 6 8 4 2
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |
8
------------------------------    |
==================================+
*/
