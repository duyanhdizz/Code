#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string password;
  cin >> password;

  const string SPECIAL = "!@#$%^&*()-+";
  bool upper = false, lower = false, digit = false, special = false, adj = false;
  char last = 0;
  for (char c : password) {
    upper |= isupper(c);
    lower |= islower(c);
    digit |= isdigit(c);
    special |= (SPECIAL.find(c) != string::npos);
    adj |= (c == last);
    last = c;
  }

  if (password.length() >= 8 && upper && lower && digit && special && !adj) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }

  return 0;
}
