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
const int INF = 0x3c3c3c;

int a, b;
vector<bool> prime(73, true);

void sang() {
	prime[0] = prime[1] = false;
	for(int i = 2; i <= 73; i++) {
		if(prime[i]) {
			for(int j = 2 * i; j <= 73; j += i) prime[j] = false;
		}
	}
}

int scs(int n) {
	int sum = 0;
	while(n > 0) {
		sum += (n % 10);
		n /= 10;
	}
	return sum;
}

int32_t main() {
#define TASKNAME "TNT"
    ios_base::sync_with_stdio (0);
    cin.tie (0);
    if ( fopen( TASKNAME".inp", "r" ) ) {
        freopen (TASKNAME".inp", "r", stdin);
        freopen (TASKNAME".out", "w", stdout);
    }
    sang();
    cin >> a >> b;
    int res = scs(a - 1);
    int ans = 0;
    for(int i = a; i <= b; i++) {
        res++;
        res = res - (res >= 10 ? 9 : 0);
        //cout << res << '\n';
        if(prime[res] == true) {
        	ans++;
		}
	}
	cout << ans;
    return 0;
}
/*
==================================+
INPUT:                            |
------------------------------    |
7 20
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |
6
------------------------------    |
==================================+
*/
