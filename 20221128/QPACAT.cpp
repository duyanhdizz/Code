#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#pragma GCC optimize("Ofast","unroll-loops")
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

int n, m;
string s[N], t[N];
map<string, int> cnt;

int32_t main() {
#define TASKNAME "QPACAT"
    ios_base::sync_with_stdio (0);
    cin.tie (0);
    if ( fopen( TASKNAME".inp", "r" ) ) {
        freopen (TASKNAME".inp", "r", stdin);
        freopen (TASKNAME".out", "w", stdout);
    }
    cin >> n >> m;
    FOR(i, 1, n) cin >> s[i];
    FOR(i, 1, m) cin >> t[i];
    FOR(i, 1, n) {
    	cnt[s[i]]++;
    	string res = "";
    	FORD(j, s[i].size() - 1, 0) {
    		res = s[i][j] + res;
    		//cout << res << '\n';
    		cnt[res]++;
		}
	}
	//cout << (2ll << 30);
    return 0;
}
/*
==================================+
INPUT:                            |
------------------------------    |
3 4
aba baba oba
ba abac ab aaa
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |

------------------------------    |
==================================+
*/