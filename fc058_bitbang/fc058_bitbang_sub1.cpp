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

int n, vtri = 1;
unordered_map<string, int> d;

bool check(string s) {
	for(int i = 0; i < s.size(); i++)
		if(s[i] == '1')
			return false;
	return true;
}

void solve() {
	string s;
	cin >> s;
	d[s]++;
	vector<string> v;
	v.pb(s);
	while(d[s] == 1) {
		string ss = s;
		for(int i = 0; i < s.size(); i++) {
			if(s[i] == '0') {
				int dem1 = 0;
				if((i >= 1 && s[i - 1] == '1')) dem1++;
				if((i < (s.size() - 1) && s[i + 1] == '1')) dem1++;
				if(dem1 == 1) ss[i] = '1';
				//cout << dem1;
			} else {
				int dem1 = 0;
				if((i >= 1 && s[i - 1] == '1')) dem1++;
				if((i < (s.size() - 1) && s[i + 1] == '1')) dem1++;
				if(dem1 != 1) ss[i] = '0';
				//cout << dem1 << '\n';
			}
		}
		d[ss]++;
		if(check(ss) == true) {
			cout << "NO" << '\n';
			//cout << vtri << '\n';
			return;
		}
		s = ss;
		v.pb(ss);
		//cout << s << '\n';
	}
	cout << "YES" << '\n';
	//cout << vtri << '\n';
	//vtri++;
	for(auto i : v) d[i] = 0;
}

int32_t main() {
#define TASKNAME "fc058_bitbang"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n;
	while(n--)
		solve();
	return 0;
}
/*
INPUT
3
01
0010100
11011
OUTPUT
YES 
NO
YES

*/