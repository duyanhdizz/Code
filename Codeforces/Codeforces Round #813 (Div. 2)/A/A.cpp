#include<bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i=(a), _b=(b); i<_b; ++i)
#define fi first
#define se second
#define pb push_back
#define int long long
#define all(a) a.begin(),a.end()
const int N = 9 + 2e5;
const int INF = 2e6;

int n, k;
int cnt[INF][9];
int a[N];

int scs(int n) {
	int res = 0;
	while(n > 0) {
		res++;
		n /= 10;
	}
	return res;
}

int power(int x, int n) {
	if(n == 0) return 1;
	if(n == 1) return x;
	int tg = power(x, n / 2);
	tg *= tg;
	if(n % 2 == 1) tg *= x;
	return tg;
}

int32_t main() {
#define TASKNAME "A"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n >> k;
	int r = 0;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		for(int j = 1; j <= 6; j++) {
			cnt[(a[i] * power(10, j)) % k][j]++;
		}
	}
	for(int i = 0; i < n; i++)
		if((a[i] * power(10, scs(a[i])) + a[i]) % k == 0) r++;
	int res = 0;
	for(int i = 0; i < n; i++)
		if(k - (a[i] % k) == 11) res += cnt[0][scs(a[i])];
		else res += cnt[k - (a[i] % k)][scs(a[i])];
	cout << res - r;
	return 0;
}
/*
6 11
45 1 10 12 11 7
*/
