#include<bits/stdc++.h>
using namespace std;
#define baitoan "sbt"
typedef long long int lli;
char a[1000],n;
lli F[50][200][2000];

lli thu(int i, bool gh,int sum, int tbp) { //XXX - 0969156825 - thnam@thptccva.edu.vn
	bool ghm;
	if (i <0) {
		if (__gcd(sum,tbp)==1) return 1;
		else return 0;
	}

	if(gh == false&& F[i][sum][tbp] >= 0)
		return F[i][sum][tbp];

	lli kq = 0;
	char maxc = (gh ? a[i] : 9);
	for (char c = 0; c <= maxc; c++) {
		ghm = gh && (c == maxc);
		kq += thu(i-1, ghm, sum+c, tbp+c*c);
	}
	if (gh==false) F[i][sum][tbp] = kq;
	return kq;
}

lli G(lli x) {
	a[0] = 0;
	n = 0;
	while (x) {
		a[n] = x % 10;
		x /= 10;
		n++;
	}
	return thu(n-1,true,0,0);
}

int t;

int main() {
	cin >> t;
	memset(F, -1, sizeof(F));
	lli A, B;
	while(t--) cin >> A >> B, cout << G(B) - G(A-1) << '\n';
	return 0;
}
