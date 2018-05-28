#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
bool sorting_method(string &s1, string &s2);
bool array_method(string &s1, string &s2);

int main() {
	cout << "Cracking the Coding Interview - 1.2 Solution [O(n) complexity]:\n";
	cout << "Given two strings, write a method to decide if one is a permutation of the other.\n\n";

	string first, second;
	cout << std::boolalpha << "Input 1st string: ";
	cin >> first;
	cout << "Input 2nd string: ";
	cin >> second;

	if(first.length() != second.length())
		cout << "Permutation?: " << false << "\n";
	else {
		//bool permutation = sorting_method(first, second);
		bool permutation = array_method(first, second);
		cout << "Permutation?: " << permutation << "\n";
	}


	return 0;
}

bool sorting_method(string &s1, string &s2) { //O(n log(n)) complexity because sorting. Everything else is less.
	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());
	//cout << s1 << " " << s2 << "\n";

	if(s1 == s2)
		return true;

	return false;
}

bool array_method(string &s1, string &s2) { //O(n) complexity because two for loops.
	int all_chars[128];

	for(size_t i = 0; i < s1.length(); ++i) {
		int char_value = s1[i];
		all_chars[char_value]++;
	}
	for(size_t i = 0; i < s2.length(); ++i) {
		int char_value = s2[i];
		all_chars[char_value]--;

		if(all_chars[char_value] < 0)
			return false;

	}
	return true;
}

