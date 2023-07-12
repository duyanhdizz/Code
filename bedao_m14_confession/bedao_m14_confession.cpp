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
const int INF = 1e9;

int t, d[N], dd[N];

bool check(string s) {
	for(int i = 0; i < s.size() / 2; i++)
		if(s[i] != s[s.size() - i - 1])
			return false;
	return true;
}

void solve() {
	int n, k;
	string s;
	cin >> n >> k >> s;
	fill(d, d + 26, 0);
	fill(dd, dd + 26, 0);
	string ss, sss;
	string ress = s.substr((s.size() + 1) / 2, s.size() - (s.size() + 1) / 2);
	string resss = ress;
	reverse(all(ress));
	string ressss = "";
	if(n % 2 == 1) ressss = s[s.size() / 2];
	sort(s.begin(), s.begin() + k);
	sort(s.end() - k, s.end(), greater<>());
	string res = s;
	reverse(all(res));
	if(res == s) cout << "Yes" << '\n' << ress << ressss << resss << '\n';
	else cout << "No" << '\n';
}

int32_t main() {
#define TASKNAME "bedao_m14_confession"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> t;
	while(t--)
		solve();
	return 0;
}
/*
INPUT
2
6 2
bacbca
6 3
bacbca
OUTPUT
No
Yes
acbbca
*/
