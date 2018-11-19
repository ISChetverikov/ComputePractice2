#include <iostream>
#include <vector>
#include "functions.h"

using namespace std;

int main() {

	string s = "134 bottles of beer on 45 tables in 34 bars in 45 cities in 3 countries in 567continents";
	string s2 = "23 34 45 23 23 23 23 34 5 6 78 8 88 8 8";
	cout << s << endl;
	sortNumbers(s);
	//incrementEquals(s);
	cout << s << endl;

	return 0;
}