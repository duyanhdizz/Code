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

string s;
stack<int> st, st1;

int32_t main() {
#define TASKNAME ""
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	int tbegin = clock();
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> s;
	int ans = 0;
	REP(i, 0, s.size()) {
		if(!st.empty()) {
			int top = st.top();
			if(s[top] == '(' && s[i] == ')') st.pop();
			else st.push(i);
		} else {
			if(s[i] == '(') st.push(i);
			else {
				ans++;
				s[i] = '(';
				st.push(i);
			}
		}
	}
	if(st.size() > 0) {
		int n = st.size() / 2;
		ans += n;
		string pp;
		FOR(i, 1, n) pp = '(' + pp;
		FOR(i, 1, n) pp = pp + ')';
		int n_n = pp.size() - 1;
		while(!st.empty()) {
			int top = st.top();
			if(s[top] != pp[n_n]) s[top] = pp[n_n];
			n_n--;
			st.pop();
		}
	}
	cout << ans << '\n' << s;
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
