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

stack<int> st;

bool solve(string s) {
	int n = (int)s.size();
	for (int i = 0; i < n; ++i) {
		if (s[i] == '(')
			st.push(i);
		else if(s[i] == ')') {
			if (st.empty()) return false;
			st.pop();
		} else return false;
	}
	if (!st.empty()) return false;
	return true;
}

void so() {
	st = {};
	string s;
	cin >> s;
	cout << (solve(s) ? "YES" : "NO") << '\n';
}

int32_t main() {
#define TASKNAME "CHKSTR"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	int tbegin = clock();
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	int t;
	cin >> t;
	while(t--) so();
	cerr << '\n' << "Runtime: " << (clock() - tbegin) << " ms\n";
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
