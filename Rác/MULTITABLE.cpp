#include<bits/stdc++.h>
using namespace std;
const int maxN = 50 + 5;
int n;
int a[maxN][maxN];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= n; j++) 
		cin >> a[i][j];

	for (int i = 1; i <= n; i++) 
		cout << (int)sqrt(a[i][i]) << ' ';
}