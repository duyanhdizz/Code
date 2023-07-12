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
#define TASKNAME "lineup"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n;
	vector<string> a(n), b(n);
	for(int i = 0; i < n; i++) cin >> a[i], b[i] = a[i];
	sort(all(a));
	bool ktra = true;
	for(int i = 0; i < n; i++)
		if(a[i] != b[i]) {
			ktra = false;
			break;
		}
	if(ktra == true) cout << "INCREASING";
	else {
		sort(all(a), greater<>());
		ktra = true;
		for(int i = 0; i < n; i++)
			if(a[i] != b[i]) {
				ktra = false;
				break;
			}
		if(ktra == true) cout << "DECREASING";
		else cout << "NEITHER";
	}
	return 0;
}
/*
INPUT
OUTPUT
*/
