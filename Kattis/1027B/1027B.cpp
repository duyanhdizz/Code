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

ll n;
int q;

int32_t main() {
#define TASKNAME ""
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n >> q;
	while(q--) {
		ll a, b;
		cin >> a >> b;
		ll res = (a - 1) / 2 * n + (b + 1) / 2;
		if(a % 2 == 0) {
			if((a + b) % 2 == 0) res += ((n + 1) / 2);
			else res += (n / 2);
		}
		if ((a + b) % 2 == 0) cout << res << '\n';
		else cout << (n * n + 1) / 2 + res << '\n';
	}
	return 0;
}
/*
INPUT
4 5
1 1
4 4
4 3
3 2
2 4
OUTPUT
1
8
16
13
4
*/
