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
const int N = 9 + 1e3;
const int NM = 9 + 1e6;
const int INF = 1e9;

int n, a[N];
unordered_map<int, int> cnt;

int32_t main() {
#define TASKNAME "CINDEX"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n;
	ll fans = 0;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		for(int j = 1; j < i; j++)
			cnt[a[i] + a[j]]++;
	}
	for(int i = 1; i <= n; i++) {
		for(int j = i + 1; j <= n; j++)
			cnt[a[i] + a[j]]--;
		for(int j = 1; j < i; j++)
			fans += cnt[a[i] + a[j]];
	}
	cout << fans;
	return 0;
}
/*
INPUT
OUTPUT
*/