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

int32_t main() {
#define TASKNAME "akcija"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n;
	vector<int> a(n);
	for(int &x : a) cin >> x;
	sort(all(a), greater<int>());
	int ans = 0;
	for(int i = 0; i < n; i++)
		if((i + 1) % 3) ans += a[i];
	cout << ans;
	return 0;
}
/*
INPUT
4
3
2
3
2
OUTPUT
8
*/
