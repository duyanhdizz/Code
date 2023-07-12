#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("unroll-loops,02,no-stack-protector")
#define FOR(i, a, b) for(int i=(a), _b=(b); i<=_b; ++i)
#define fi first
#define se second
#define pb push_back
#define ll long long
#define all(a) a.begin(),a.end()
typedef pair<int, int> pii;
const int N = 9 + 3e2;
const int INF = 1e9;

ll n, a[N], f[N];

int32_t main() {
#define TASKNAME "cvp_huong9"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n;
	FOR(i, 1, n) {
		cin >> a[i];
		f[i] = 1;
	}
	sort(a + 1, a + n + 1);
	ll res = 1;
	FOR(i, 1, n) {
		FOR(j, i + 1, n) {
			if(a[j] % a[i] == 0) f[j] = max(f[j], f[i] + 1);

			res = max(res, f[j]);
		}
	}
	cout << res;
	return 0;
}