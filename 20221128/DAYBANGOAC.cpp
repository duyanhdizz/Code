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

int n;
stack<char> st;

bool solve(string s) {
	st = {};
	int n = (int)s.size();
	for (int i = 0; i < n; ++i) {
		if (s[i] == '(' || s[i] == '[' || s[i] == '{') st.push(s[i]);
		else {
			if (st.empty()) return false;
			if(st.top() == '(' && s[i] != ')') return false;
			if(st.top() == '[' && s[i] != ']') return false;
			if(st.top() == '{' && s[i] != '}') return false;
			//cout << st.top();
			st.pop();
		}
	}
	if (!st.empty()) return false;
	return true;
}

int32_t main() {
#define TASKNAME "DAYBANGOAC"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n;
	while(n--) {
		string s;
		cin >> s;
		cout << (solve(s) == true ? "YES" : "NO") << '\n';
	}
	return 0;
}
/*
==================================+
INPUT:                            |
------------------------------    |
4
{[()()[]()]}()
[(])
([{}]){[()]}
{{{}}
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |

------------------------------    |
==================================+
*/
