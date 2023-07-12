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

int solve(string s) {
	stack<int> st;
	istringstream iss(s);
	string token;
	while (iss >> token) {
		if (token == "+" || token == "-" || token == "*") {
			int v = st.top();
			st.pop();
			int a = st.top();
			st.pop();
			if (token == "+") {
				st.push(a + v);
			} else if (token == "-") {
				st.push(a - v);
			} else if (token == "*") {
				st.push(a * v);
			}
		} else {
			int p;
			istringstream(token) >> p;
			st.push(p);
		}
	}
	return st.top();
}

void SaKaTa() {
	string s;
	getline(cin, s);
	int result = solve(s);
	cout << result << endl;
}

int32_t main() {
#define TASKNAME "ALDS1_3_A"
	ios_base::sync_with_stdio (false);
	cin.tie (nullptr);
	cout.tie (nullptr);
	int tbegin = clock();
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	int testcase = 1;
//    cin >> testcase;
	while(testcase--)
		SaKaTa();
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
