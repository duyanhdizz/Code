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

int n;
string s;
vector<char> db {'!','@','#','$','%','^','&','*','<','(',')','-','+'};

int32_t main() {
#define TASKNAME "cvp_strongpwd"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n;
	cin >> s;
	int len = 0;
	bool ktra = true, ktra2 = true, ktra3 = true, ktra4 = true;
	each(x, s) {
		if(x >= 'A' && x <= 'Z') ktra = false;
		if(x >= 'a' && x <= 'z') ktra2 = false;
		if(x >= '0' && x <= '9') ktra3 = false;
		if(ktra4 == true) ktra4 = !(binary_search(all(db), x));
	}
	cout << ktra + ktra2 + ktra3 + ktra4 + (n + ktra + ktra2 + ktra3 + ktra4 < 6 ? 6 - (n + ktra + ktra2 + ktra3 + ktra4) : 0);
	return 0;
}
/*
==================================+
INPUT:                            |
------------------------------    |
3
Ab1
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |

------------------------------    |
==================================+
*/
