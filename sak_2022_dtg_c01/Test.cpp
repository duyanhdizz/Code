#include <iostream>
#include <map>
using namespace std;

int main()
{

	map<char, int> mp = {
		{ 'e', 1 },
		{ 'b', 2 },
		{ 'c', 3 },
		{ 'f', 4 },
		{ 'a', 5 },
	};

	cout << "Map contains "
		<< "following elements in"
		<< " reverse order"
		<< endl;

	for (auto i = mp.rbegin(); i != mp.rend(); ++i) {

		cout << i->first
			<< " = "
			<< i->second
			<< endl;
	}

	return 0;
}
