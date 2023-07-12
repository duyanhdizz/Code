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

int n;

vector<int> ans;

void print(const vector<int> &a) {
	int res = 0;
	bool ktra = true;
	for (int i = 0; i < a.size(); i++) {
		if(i == 0 && (a[i] == 2 || a[i] == 5)) {
			ktra = false;
			break;
		}
		res = res * 10 + a[i];
	}
	if(ktra == true) ans.pb(res);
}

void permute(vector<int> &a, int k) {
	if (k == 1) return print(a);
	for (int i = 0; i < k - 1; i++) {
		permute(a, k - 1);
		if (k % 2 == 0) swap(a[i], a[k - 1]);
		else swap(a[0], a[k - 1]);
	}
	permute(a, k - 1);
}

int32_t main() {
#define TASKNAME "NGUYENTO"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n;
	vector<int> v(n);
	int i = n;
	while(i > 0) {
		FOR(j, 0, i - 1) v[j] = 2;
		int j = n - i;
		if(j == 0) permute(v, i);
		while(j > 0) {
			FOR(z, i - 1, i - 1 + j) v[z] = 3;
			int z = n - i - j;
			if(z == 0) permute(v, j);
			while(z > 0) {
				FOR(k, i - 1 + j, i - 1 + j + z) v[k] = 5;
				int k = n - i - j - z;
				if(k == 0) permute(v, k);
				while(k > 0) {
					FOR(kk, i - 1 + j + z, i - 1 + j + z + k) v[kk] = 7;
					permute(v, v.size());
					k--;
				}
				z--;
			}
			j--;
		}
		i--;
	}
	for(auto i : ans) cout << i << '\n';
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
