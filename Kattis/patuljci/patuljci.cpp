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

int a[9];

int32_t main() {
#define TASKNAME "patuljci"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	for(int i = 0; i < 9; i++) cin >> a[i];
	for(int i = 0; i < 9; i++)
		for(int j = i + 1; j < 9; j++)
			for(int z = j + 1; z < 9; z++)
				for(int k = z + 1; k < 9; k++)
					for(int m = k + 1; m < 9; m++)
						for(int n = m + 1; n < 9; n++)
							for(int h = n + 1; h < 9; h++)
								if(a[i] + a[j] + a[z] + a[k] + a[m] + a[n] + a[h] == 100) return cout << a[i] << '\n' << a[j] << '\n' << a[z] << '\n' << a[k] << '\n' << a[m] << '\n' << a[n] << '\n' << a[h] << '\n', 0;
	return 0;
}
/*
INPUT
7
8
10
13
15
19
20
23
25
OUTPUT
7
8
10
13
19
20
23
*/
