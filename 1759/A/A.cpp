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
string m;

void solve() {
	string s;
	cin >> s;
	cout << (m.find(s) == -1 ? "NO" : "YES") << '\n';
}

int32_t main() {
#define TASKNAME "A"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> t;
	for(int i = 0; i < 40; i++) m += "Yes";
	while(t--)
		solve();
	return 0;
}
/*
==================================+
INPUT:                            |
------------------------------    |
12
YES
esYes
codeforces
es
se
YesY
esYesYesYesYesYesYe
seY
Yess
sY
o
Yes
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |
NO
YES
NO
YES
NO
YES
YES
NO
NO
YES
NO
YES
------------------------------    |
==================================+
*/
