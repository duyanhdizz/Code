#include<bits/stdc++.h>
using namespace std;

long long MOD, MOD2;

long long PoW(long long a, long long b)
{
    long long res = 1;
    while (b) {
        if (b & 1) res = (res * a) % MOD;
        b >>= 1; a = a * a % MOD;
    }
    return res;
}

long long phi(long long n) {
    long long ans = n;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0)
        {
            while (n % i == 0)
            {
                n /= i;
            }
            ans -= ans / i;
        }
    }
    if (n > 1) {
        ans -= ans / n;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s, t; cin >> s >> t >> MOD;
    long long a = 0, b = 0;
    MOD2 = phi(MOD);
    for (int i = 0; i < s.size(); ++i) a = (a * 10 + s[i] - '0') % MOD;
    for (int i = 0; i < t.size(); ++i) b = (b * 10 + t[i] - '0') % MOD2;
    //b = (b + MOD2);
    //cout << PoW(a, b) << '\n';
    //cout << MOD2;
}

/*
3
2
7
*/