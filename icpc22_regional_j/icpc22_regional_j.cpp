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
const int N = 9 + 1e6;
const int INF = 1e9;

int f[5][150111];

int32_t main() {
#define TASKNAME "icpc22_regional_j"
    ios_base::sync_with_stdio (0);
    cin.tie (0);
    if ( fopen( TASKNAME".inp", "r" ) ) {
        freopen (TASKNAME".inp", "r", stdin);
        freopen (TASKNAME".out", "w", stdout);
    }
    string s;
    while(cin >> s) {
    	if(s == "$") return 0;
    	int n = s.size();
    	s = " " + s + " ";
    	FOR(i, 1, n) f[1][i] = (s[i] == 'I' ? 1 : 0);
    	partial_sum(f[1], f[1] + n + 1, f[1]);
    	FOR(i, 3, n) f[2][i] = (s[i] == 'C' ? f[1][i - 2] : 0);
    	partial_sum(f[2], f[2] + n + 1, f[2]);
    	FOR(i, 5, n) f[3][i] = (s[i] == 'P' ? f[2][i - 2] : 0);
    	partial_sum(f[3], f[3] + n + 1, f[3]);
    	FOR(i, 7, n) f[4][i] = (s[i] == 'C' ? f[3][i - 2] : 0);
    	partial_sum(f[4], f[4] + n + 1, f[4]);
    	cout << f[4][n] << '\n';
	}
    return 0;
}
/*
==================================+
INPUT:                            |
------------------------------    |

------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |

------------------------------    |
==================================+
*/
