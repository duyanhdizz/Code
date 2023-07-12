#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(s) s.begin(), s.end()

int t;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for(int i = 0; i < n; i++) cin >> a[i], b[i] = a[i];
	sort(all(b));
	int i = 0;
	while (i + 1 < n) {
		if (a[i] <= a[i + 1]) i++;
		else break;
	}
	if ((i + 1) != n) {
		i++;
		while (i + 1 < n) {
			if (a[i] >= a[i + 1]) i++;
			else break;
		}
	}
	int res = 0, res1 = 0;
	for (int i = 0; i < n; i++)
		if (a[i] == b[i])
			res++;
	reverse(all(b));
	for (int i = 0; i < n; i++)
		if (a[i] == b[i])
			res1++;
	bool ktra = (res == n || res1 == n);
	if(ktra || (i + 1 == n)) cout << "YES" << '\n';
	else cout << "NO" << '\n';
}

int main() {
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	cin >> t;
	while(t--)
		solve();
	return 0;
}
