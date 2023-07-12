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

int t, d[26], d1[26];

int32_t main() {
#define TASKNAME "cvp_twostr"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> t;
	while(t--) {
		string s, s1;
		cin >> s >> s1;
		fill(d, d + 26, 0);
		fill(d1, d1 + 26, 0);
		for(int i = 0; i < s.size(); i++) d[s[i] - 'a']++;
		for(int i = 0; i < s1.size(); i++) d1[s1[i] - 'a']++;
		bool ktra = false;
		REP(i, 0, 26) {
			if(d[i] > 0 && d1[i] > 0) {
				cout << "YES" << '\n';
				ktra = true;
				break;
			}
		}
		if(ktra == false) cout << "NO" << '\n';
	}
	return 0;
}
/*
==================================+
INPUT:                            |
------------------------------    |
4
and
art
be
cat
hello
world
hi
world
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |

------------------------------    |
==================================+
*/
