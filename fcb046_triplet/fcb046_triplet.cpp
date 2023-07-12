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

int n, s;
unordered_map<int, int> m;

int32_t main() {
#define TASKNAME "fcb046_triplet"
    ios_base::sync_with_stdio (0);
    cin.tie (0);
    if ( fopen( TASKNAME".inp", "r" ) ) {
        freopen (TASKNAME".inp", "r", stdin);
        freopen (TASKNAME".out", "w", stdout);
    }
    cin >> n >> s;
    for(int i = 0; i <= n; i++) {
    	for(int j = 0; j <= n; j++) {
    		m[i + j]++;
		}
	}
	int res = 0;
	for(int i = 0; i <= n; i++) res += m[s - i];
	cout << res;
    return 0;
}
/*
==================================+
INPUT:                            |
------------------------------    |
3 7
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |
6
------------------------------    |
==================================+
*/
