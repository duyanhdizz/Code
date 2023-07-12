#include <bits/stdc++.h>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	int N; cin >> N;

	if (N % 4 == 0) cout << 0 << '\n';
	else if (N % 4 == 2) cout << 1 << '\n';
	else cout << 2 << '\n';
}