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

int n;
string s;

int32_t main() {
#define TASKNAME "364577A"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n >> s;
	for(int i = n - 2; i >= 0; i -= 2) cout << s[i];
	int i = 0;
	if(n % 2 == 0) i++;
	for(; i < n; i += 2) cout << s[i];
	return 0;
}
/*
==================================+
INPUT:                            |
------------------------------    |
5
logva
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |
volga
------------------------------    |
==================================+
*/
