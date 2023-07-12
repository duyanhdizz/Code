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

bool check_(string a, string b) {
	if(a.size() <= b.size()) {
		if((b.substr(0, a.size()) == a) || (a[0] == 'a' && b[0] == 'b')) return true;
		else return false;
	} else return (a[0] == 'a' && b[0] == 'b');
}

bool check(string a, string b, string c) {
	return (a != "" && b != "" && c != "") && ((check_(a, b) && check_(c, b)) || (check_(b, a) && check_(b, c)));
}

void IU() {
	string s;
	cin >> s;
	for(int i = 0; i < s.size(); i++) {
		for(int j = i; j < s.size(); j++) {
			string res = s.substr(i, j - i + 1);
			for(int z = j + 1; z < s.size(); z++) {
				for(int k = z; k < s.size(); k++) {
					string res_s = s.substr(z, k - z + 1);
					string res_s_s = s.substr(k + 1);
					if(check(res, res_s, res_s_s)) {
						cout << res << ' ' << res_s << ' ' << res_s_s << '\n';
						return;
					}
				}
			}
		}
	}
	cout << ":(" << '\n';
}

int32_t main() {
#define TASKNAME "A1"
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
		IU();
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
