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

int s, n, a[N];

int32_t main() {
#define TASKNAME "Stamps"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> s >> n;
	int res = 0;
	for(int i = 0; i < n; i++) cin >> a[i], res += a[i];
	if(res < s) cout << "impossible";
	else {
		sort(a, a + n, greater<int>());
		int ans = 0;
		for(int i = 0; i < n; i++) {
			if(s <= 0) break;
			s -= a[i];
			ans++;
		}
		cout << ans;
	}
	return 0;
}

/*
INPUT
100 6
13 17 42 9 23 57
OUTPUT
3
*/