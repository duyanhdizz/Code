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

int32_t main() {
#define TASKNAME ""
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	string str;
	getline(cin, str);
	str.insert(0, " ");
	str.insert(str.size(), " ");
	REP(i, 1, str.size()) {
		if (str[i] == 'k' && str[i-1] == ' ' && str[i+1] == ' ')
			str.replace(i, 1, "khong");
		if (str[i] == 'k' && str[i-1] == ' ' && str[i+1] == 'o' && str[i+2] == ' ')
			str.replace(i, 2, "khong");
		if (str[i] == 'n' && str[i-1] == ' ' && str[i+1] == ' ')
			str.replace(i, 1, "nhieu");
		if (str[i] == 'n' && str[i-1] == ' ' && str[i+1] == 'g' && str[i+2] == ' ')
			str.replace(i, 2, "nguoi");
		if (str[i] == 'd' && str[i-1] == ' ' && str[i+1] == 'c' && str[i+2] == ' ')
			str.replace(i, 2, "duoc");
		if (str[i] == 'h' && str[i-1] == ' ' && str[i+1] == 'o' && str[i+2] == 'k' && str[i+3] == ' ')
			str.replace(i, 3, "khong");
		if (str[i] == 'n' && str[i-1] == ' ' && str[i+1] == 't' && str[i+2] == 'n' && str[i+3] == ' ')
			str.replace(i, 3, "nhu the nao");
		if (str[i] == 'k' && str[i-1] == ' ' && str[i+1] == 'q' && str[i+2] == ' ')
			str.replace(i, 2, "ket qua");
		if (str[i] == 'j')
			str.replace(i, 1, "gi");
		if (str[i] == 'w')
			str.replace(i, 1, "qu");
		if (str[i] == 'f')
			str.replace(i, 1, "ph");
		if (str[i] == 'd' && str[i+1] == 'z')
			str.replace(i, 2, "d");
		if (str[i] == 'z')
			str.replace(i, 1, "d");
	}
	REP(i, 1, str.size() - 1) cout << str[i];
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
