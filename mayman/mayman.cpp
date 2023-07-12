#include <bits/stdc++.h>
using namespace std;
 
int main(int argc, char* argv[])
{
  //registerGen(argc, argv, 0);
  vector <int> shirt_winners = {};
  vector <int> bag_winners = {};
 
  for (int i = 6; i <= 20; i++) shirt_winners.push_back(i);
  for (int i = 21; i <= 70; i++) bag_winners.push_back(i);
 
  sort(shirt_winners.begin(), shirt_winners.end());
  sort(bag_winners.begin(), bag_winners.end());
 
  // list of shirt winners
  //cout << ""===== Rank of SHIRT WINNERS =====\n"";
  for (int i = 0; i < 5; i++) {
    cout << shirt_winners[i] << ' ';
  }
  cout << "\n";
 
  // list of bag winners
  //cout << ""===== Rank of BAG WINNERS =====\n"";
  for (int i = 0; i < 10; i++) {
    cout << bag_winners[i] << ' ';
  }
  //cout << ""\n"";
}