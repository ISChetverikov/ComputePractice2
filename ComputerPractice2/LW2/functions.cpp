#include <vector>
#include <map>
#include <iostream>
#include <sstream>
#include <regex>
#include <algorithm>
#include "functions.h"

using namespace std;


void sortNumbers(string &src) {
	vector<int> numbers;
	regex number_regex("\\d+");
	smatch base_match;
	string result;

	string s = src;
	while (regex_search(s, base_match, number_regex)) {
		numbers.push_back(stoi(base_match.str()));
		s = base_match.suffix();
	}
	sort(numbers.begin(), numbers.end());

	int i = numbers.size() - 1;
	auto callback = [&](string const& chunk) {
		istringstream iss(chunk);
		int n;
		if (iss >> n)
		{
			result += to_string(numbers[i]);
			i--;
		}
		else
		{
			result += chunk;
		}
	};

	sregex_token_iterator
		begin(src.begin(), src.end(), number_regex, { -1,0 }),
		end;
	for_each(begin, end, callback);

	/*string::iterator it;
	for (auto v : numbers)
	{
		cout << v << endl;
		it = regex_replace(result, it, src.end(), number_regex, to_string(v), regex_constants::format_first_only);
	}*/
	src = result;
	
}

void incrementEquals(string &src) {
	vector<int> numbers;
	map<int, vector<int>> frequencies;
	
	regex number_regex("\\d+");
	smatch base_match;
	string result;

	// Get all numbers
	string s = src;
	while (regex_search(s, base_match, number_regex)) {
		numbers.push_back(stoi(base_match.str()));
		s = base_match.suffix();
	}

	// Create map <number, indexes in the numbers vector>
	for (int i = 0; i < numbers.size(); i++) {
		int key = numbers[i];
		frequencies[key].push_back(i);
	}

	// Create mask for repeated numbers
	vector<bool> mask(numbers.size());
	for (auto map_item : frequencies) {
		int n = map_item.second.size();
		if (n== 1)
			continue;

		for (auto vector_item : map_item.second) {
			mask[vector_item] = true;
		}
	}
	
	int i = 0;
	auto callback = [&](string const& chunk) {
		istringstream iss(chunk);
		int n;
		if (iss >> n)
		{
			result += to_string(numbers[i] + mask[i]);
			i++;
		}
		else
		{
			result += chunk;
		}
	};

	sregex_token_iterator
		begin(src.begin(), src.end(), number_regex, { -1,0 }),
		end;
	for_each(begin, end, callback);

	src = result;
}