#include<bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i=(a), _b=(b); i<_b; ++i)
#define fi first
#define se second
#define pb push_back
#define ll long long
#define all(a) a.begin(),a.end()
const int N = 9 + 2e6;
const int mod = 1e9 + 7;
const int p = 167;
const int INF = 1e9;

int get_hash(vector <int> &h, int i, int j, vector <int> &pow){
    return (h[j] - (long long) h[i - 1] * pow[j - i + 1] % mod + mod) % mod;
}

ll k, temp, temp1, temp2, m, n, k1, k2;
string s;

int32_t main() {
#define TASKNAME ""
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> s;
	n = s.size();
	vector <int> a(n + 1, 0);
	vector <int> pw(n + 1, 1);
	for(int i = 1; i <= s.size(); ++i) {
		pw[i] = (ll)pw[i - 1] * p % mod;
		a[i] = (s[i - 1] + (ll)p * a[i - 1] % mod) % mod;
	}
	cin >> s;
	int hh = 0;
	for(int i = 0; i < s.size(); ++i) {
		hh = (s[i] + (ll)p * hh % mod) % mod;
	}
	int counter = 0;
	for(int i = s.size() - 1; i <= n; ++i) {
		if(get_hash(a, (int)(i - s.size() + 1), i, pw) == hh) {
			++counter;
		}
	}
	cout << counter;
	return 0;
}
