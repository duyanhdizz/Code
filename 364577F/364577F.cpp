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
map<int, int> res;

int32_t main() {
#define TASKNAME "364577F"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> s;
	ll n = s.size();
	for(ll i = 0; i < n - 1; i++)
		if(s[i] != s[i + 1]) res[i] = 1;
		else res[i] = 0;
	if(s[n - 1] == 'a') res[n - 1] = 1;
	for(ll i = 0; i < n; i++) cout << res[i] << ' ';
	return 0;
}
/*
==================================+
INPUT:                            |
------------------------------    |
aaaaa
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |
1 0 0 0 1
------------------------------    |
==================================+
*/
