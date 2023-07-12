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

string s;

int32_t main() {
#define TASKNAME "A"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	getline(cin, s);
	while(s[0] == ' ') s.erase(0, 1);
	for(int i = 0; i + 1 < s.size(); i++) {
		if(i == 0) s[0] -= 'a', s[0] += 'A';
		if((s[i] == ' ' && s[i + 1] != ' ')) {
			if(s[i + 1] >= 'a' && s[i + 1] <= 'z') {
				s[i + 1] -= 'a';
				s[i + 1] += 'A';
			}
		}
	}
	for(int i = 0; i < s.size(); i++) {
		if(s[i] != ' ') cout << s[i];
	}
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
