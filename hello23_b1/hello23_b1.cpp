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

string trans(int x) {
	if(x == 0) return "0";
	string s;
	while(x > 0) {
		s += char(x % 10 + 48);
		x /= 10;
	}
//	cout << s;
	reverse(all(s));
	return s;
}

void YeuHuong() {
	stack <int> st;
	int n;
	cin >> n;
	int ans = 0;
	FOR(i, 1, n) {
		int x;
		cin >> x;
		if(st.size() >= 3) {
			int a = st.top();
			st.pop();
			int b = st.top();
			st.pop();
			int c = st.top();
			st.pop();
			if(c == 2 && b == 0 && a == 2 && x == 3) ans++;
			else {
				st.push(c);
				st.push(b);
				st.push(a);
				st.push(x);
			}
		} else st.push(x);
	}
	cout << (ans != 0 ? (ans & 1 ? "Bedao" : "Bemai") : ":(") << "\n";
}

int32_t main() {
#define TASKNAME "hello23_b1"
	ios_base::sync_with_stdio (false);
	cin.tie (nullptr);
	cout.tie (nullptr);
	int tbegin = clock();
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	int testcase;
	cin >> testcase;
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
