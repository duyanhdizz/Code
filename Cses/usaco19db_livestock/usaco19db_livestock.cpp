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

map<string, bool> m;
vector<string> s = {"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};
map<string, vector<string>> ans_;

void SaKaTa() {
	int n;
	cin >> n;
	sort(all(s));
	each(x, s) cout << x << '\n';
	each(x, s) m[x] = true;
	FOR(i, 1, n) {
		int cnt = 6;
		string _, __;
		FOR(j, 1, cnt) {
			string s;
			cin >> s;
			if(j == 1) {
				_ = s;
			}
			if(j == cnt) {
				__ = s;
			}
		}
		if(_ < __) ans_[_].pb(__);
		else ans_[__].pb(_);
	}
	each(x, s) {
		if(m[x] == true) {
			if(ans_[x].size() == 2) {
				sort(all(ans_[x]));
				cout << ans_[x][0] << '\n' << x << '\n' << ans_[x][1] << '\n';
				m[x] = false;
				m[ans_[x][0]] = false;
				m[ans_[x][1]] = false;
			} else if(ans_[x].size() == 1) {
				if(ans_[x][0] < x) cout << ans_[x][0] << '\n' << x << '\n';
				else cout << x << '\n' << ans_[x][0] << '\n';
				m[x] = false;
				m[ans_[x][0]] = false;
			} else {
				cout << x << '\n';
				m[x] = false;
			}
		}
	}
}


int32_t main() {
#define TASKNAME "usaco19db_livestock"
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
