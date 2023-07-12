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

string s;

int32_t main() {
#define TASKNAME "DUPPAREN"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> s;
	int len = 0;
	FOR(i, 0, s.size() - 2) {
		if(s[i] == s[i + 1] && s[i] == '(') {
			FOR(j, i + 2, s.size() - 2) {
				if(s[j] == s[j + 1] && s[j] == ')') {
					len++;
				}
			}
		}
	}
	cout << len;
	return 0;
}
/*
==================================+
INPUT:                            |
------------------------------    |
)((()())())
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |
4
------------------------------    |
==================================+
*/
