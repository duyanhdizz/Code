#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast","unroll-loops")
#define FOR(i, a, b) for(int i=(a), _b=(b); i<_b; ++i)
#define fi first
#define se second
#define pb push_back
#define ll long long
#define all(a) a.begin(),a.end()
typedef pair<int, int> pii;
const int N = 9 + 1e6;
const int INF = 1e9;

int n;
string s;

bool check(string res) {
	char c = res[1];
	for(int i = 0; i < res.size() / 2; i++) {
		if((i + 1) % 2 == 0) {
			if(res[i] != c) return false;
		}
		if(res[i] != res[res.size() - i - 1]) return false;
	}
	int i = res.size() / 2;
	if(i % 2 == 0) i++;
	for(; i < res.size(); i += 2)
		if(res[i] != c) return false;
	return true;
}

int32_t main() {
#define TASKNAME "bedao_r12_papalind"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n >> s;
	int ans = 0;
	if(check(s)) {
		for(int i = 0; i < s.size(); i++) {
			for(int j = 2; j + i - 1 < s.size(); j++) {
				if(n - (i + 1) * 2 != j) {
					string res = s.substr(i, j);
					if(check(res)) ans++;
				}
			}
		}
	} else {
		for(int i = 0; i < s.size(); i++) {
			for(int j = 2; j + i - 1 < s.size(); j++) {
				string res = s.substr(i, j);
				if(check(res)) ans++;
			}
		}
	}
	cout << ans + n;
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
