#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast","unroll-loops")
#define FOR(i, a, b) for(int i=(a), _b=(b); i<_b; ++i)
#define fi first
#define se second
#define pb push_back
#define int long long
#define all(a) a.begin(),a.end()
typedef pair<int, int> pii;
const int N = 9 + 2e5;
const int INF = 1e18;

int t, a[N];
int pos = 0;

void BEAUTY() {
	for(int i = 1; i <= 1e18; i *= 2)
		for(int j = 1; j * i <= 1e18; j *= 3)
			for(int k = 1; k * i * j <= 1e18; k *= 5)
				a[++pos] = i * j * k;
	sort(a + 1, a + pos + 1);
	//cout << pos << '\n';
	//for(int i = 0; i < 17; i++) cout << a[i] << ' ';
}

void solve() {
	int n;
	cin >> n;
	int res = upper_bound(a + 1, a + pos + 1, n) - a - 1;
	if (a[res] == n) cout << res << '\n';
	else cout << -1 << '\n';
}

int32_t main() {
#define TASKNAME "cvp_sxtk20"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	BEAUTY();
	cin >> t;
	while(t--)
		solve();
	return 0;
}
/*
INPUT
11
1
2
6
7
8
9
10
11
12
13
14
OUTPUT
1
2
6
Not in sequence
7
8
9
Not in sequence
10
Not in sequence
Not in sequence
*/
