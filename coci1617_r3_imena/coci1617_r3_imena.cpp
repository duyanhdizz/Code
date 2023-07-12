#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
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

int t;

bool bu(char c) {
	return c == '.' || c == '?' || c == '!';
}

bool check(string s) {
	return bu(s[s.size() - 1]);
}

bool k(string s) {
	if( s[0] < 'A' || s[0] > 'Z' ) {
		return false;
	}
	for(int i = 1; i < s.size(); i++) {
		if((s[i] < 'a' || s[i] > 'z') && bu(s[i]) == false) {
			return false;
		}
	}
	return true;
}

void solve() {
	string s;
	int ans = 0;
	while(check(s) == false) {
		cin >> s;
		if(k(s)) ans++;
	}
	cout << ans << '\n';
}

int32_t main() {
#define TASKNAME "coci1617_r3_imena"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> t;
	while(t--)
		solve();
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
