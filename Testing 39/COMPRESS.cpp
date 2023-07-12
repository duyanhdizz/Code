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

string s;

int32_t main() {
#define TASKNAME "COMPRESS"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> s;
	int n = s.size(), k;
	for(int i = 1; i < n - 1; i++) {
		if(s.substr(0, i) == s.substr(i, i) && s.substr(i, i) == s.substr(n - i, i)) {
			k = i;
			break;
		}
		if(i == n - 1) {
			cout << '1' << s;
			return 0;
		}
	}
	cout << n / k << s.substr(0, k);
	return 0;
}
/*
INPUT
abcabc
OUTPUT
*/
