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

string s;
int k, d[N];

int32_t main() {
#define TASKNAME "XAUCON"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> k >> s;
	d[0] = 1;
	int res = 0;
	ll res2 = 0;
	for (int i = 0; i < s.size(); i++) {
		if(s[i] == '1') res++;
		if(res >= k) res2 += d[res - k];
		d[res]++;
	}
	cout << res2;
	return 0;
}
/*
INPUT
1
1010
---
2
1010
---
3
1010011110
---
3
1111
OUTPUT
6
---
2
---
8
---
2
*/
