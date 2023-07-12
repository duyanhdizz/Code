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
const int N = 9 + 1e5;
const int INF = 1e9;

int n, m, a[N];

int32_t main() {
#define TASKNAME "dtl22_e"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n >> m;
	fill(a + 1, a + n + 1, 1);
	int j = 1;
	for(int i = 0; i < m; i++) {
		int x;
		cin >> x;
		int res = 0;
		x--;
		while(x--) {
			if(x > 1) {
				if(a[j] == 1) {
					cout << j << ' ' ;
					res += j;
					a[j] = 0;
				} else {
					while(a[j] == 0) j++;
					cout << j << ' ' ;
					res += j;
					a[j] = 0;
				}
				j++;
			} else {
				if(a[j] == 1) {
					if((res + j) % n == 0) {
						j++;
						while(a[j] == 0) j++;
						cout << j << ' ';
						res += j;
						a[j] = 0;
						j++;
						continue;
					}
					cout << j << ' ' ;
					res += j;
					a[j] = 0;
					j++;
				} else {
					while(a[j] == 0) j++;
					if((res + j) % n == 0) {
						j++;
						while(a[j] == 0) j++;
						cout << j << ' ';
						res += j;
						a[j] = 0;
						j++;
						continue;
					}
					cout << j << ' ' ;
					res += j;
					a[j] = 0;
					j++;
				}
			}
		}
		//cout << res << '\n';
		for(int z = 1; z <= n; z++) {
			if((res + z) % n == 0 && a[z] == 1) {
				cout << z << ' ';
				a[z] = 0;
				break;
			}
		}
		cout << '\n';
	}
	return 0;
}
/*
==================================+
INPUT:                            |
------------------------------    |
7 3
2 2 2
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |
3 4
2 5
1 6
------------------------------    |
==================================+
*/
