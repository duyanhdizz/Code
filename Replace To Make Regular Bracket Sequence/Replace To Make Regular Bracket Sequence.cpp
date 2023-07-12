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

string st;
stack<char> S;
int ans;

int get_type(char c) {
	if (c == '<' || c == '{' || c == '[' || c == '(') return 1;
	return 2;
}

bool paired(char a, char b) {
	if (a == '<' && b == '>') return true;
	if (a == '(' && b == ')') return true;
	if (a == '[' && b == ']') return true;
	if (a == '{' && b == '}') return true;
	return false;
}

void YeuHuong() {
	cin >> st;
	for (int i = 0; i < st.size(); i++) {
		if (get_type(st[i]) == 1) {
			S.push(st[i]);
			continue;
		}
		if (S.size() == 0) {
			cout << "Impossible";
			return;
		}
		char val = S.top();
		if (!paired(val, st[i])) ans++;
		S.pop();
	}

	if (S.size()) {
		cout << "Impossible";
		return;
	} else cout << ans;
}

int32_t main() {
#define TASKNAME "Replace To Make Regular Bracket Sequence"
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
		YeuHuong();
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
