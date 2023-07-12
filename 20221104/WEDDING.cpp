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

int n, m;

int32_t main() {
#define TASKNAME "WEDDING"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n >> m;
	vector<int> a(n), b(m);
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < m; i++) cin >> b[i];
	sort(all(a));
	sort(all(b));
	int res = 0;
	for(int i = 0; i < n; i++) {
		if(a[i] > b[0]) {
			b.erase(b.begin(), b.begin() + 1);
			bool ktra = false;
			for(int j = b.size() / 2; j < b.size(); j++)
				if(a[i] < b[j]) {
					b.erase(b.begin() + j, b.begin() + j + 1);
					ktra = true;
					break;
				}
			if(ktra == true) res++;
			else break;
		}
	}
	cout << res;
	return 0;
}
/*
INPUT
4 4
3 4 1 3
2 1 7 0
---
6 10
2 3 4 5 6 7
1 2 3 4 5 6 7 8 9 10
---
5 10
2 3 4 5 6
1 2 3 4 5 6 7 8 9 10
---
5 9
1 4 5 7 9
1 4 6 8 10 12 14 15 18
---
10 20
2 4 5 6 7 8 9 1 11 13
4 5 6 7 8 9 7 6 5 4 3 2 1 3 44 55 66 77 66 100
OUTPUT
2
---
5
---
5
---
4
---
9
*/