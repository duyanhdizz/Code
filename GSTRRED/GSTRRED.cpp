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

int t;
int ans;
bool m[109];

void dequy(string s) {
	bool work = false;
	FOR(i, 0, s.size() - 2) {
		if(s[i] != s[i + 1]) {
			work = true;
			if(s[i] == 'a') {
				if(s[i + 1] == 'b') {
					s[i] = 'c';
					s.erase(s.begin() + i + 1, s.begin() + i + 2);
				//	m[i + 1] = true;
				    dequy(s);
				    //m[i + 1]
				} else {
					s[i] = 'b';
					s.erase(s.begin() + i + 1, s.begin() + i + 2);
					dequy(s);
				}
			} else if(s[i] == 'b') {
				if(s[i + 1] == 'a') {
					s[i] = 'c';
					s.erase(s.begin() + i + 1, s.begin() + i + 2);
					dequy(s);
				} else {
					s[i] = 'a';
					s.erase(s.begin() + i + 1, s.begin() + i + 2);
					dequy(s);
			}
			} else {
				if(s[i + 1] == 'a') {
					s[i] = 'b';
					s.erase(s.begin() + i + 1, s.begin() + i + 2);
					dequy(s);
				} else {
					s[i] = 'a';
					s.erase(s.begin() + i + 1, s.begin() + i + 2);
					dequy(s);
				}
			}
			//dequy(s);
		}
	}
	if(work == false) ans = min(ans, (int)(s.size()));
}

void solve() {
	string s;
	cin >> s;
	ans = INF;
	//FOR(i, 0, s.size()) m[i] = false;
	dequy(s);
	cout << ans << '\n';
}

int32_t main() {
#define TASKNAME "GSTRRED"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	int tbegin = clock();
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> t;
	while(t--)
		solve();
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
