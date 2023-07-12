#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast","unroll-loops")
#define FOR(i, a, b) for(int i=(a), _b=(b); i<_b; ++i)
#define fi first
#define se second
#define pb push_back
#define ll long long
#define all(a) a.begin(),a.end()
typedef pair<int, int> pii;
const int N = 9 + 1e6;
const int INF = 1e9;

int n, a[N], cnt[N], f[N];

int32_t main() {
#define TASKNAME "bedao_g06_lds"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		cnt[a[i]] = i;
		f[i] = 1;
	}
	int res = 0;
	for (int i = 1; i <= n; i++) {
		res = max(res, f[a[i]]);
		for (int j = a[i]; j <= n; j += a[i])
			if (cnt[j] > i)
				f[j] = max(f[j], f[a[i]] + 1);
	}
	cout << res;
	return 0;
}
/*
INPUT
OUTPUT
*/
