#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

bool unique_string(string &s);

int main() {
	cout << "Cracking the Coding Interview - 1.1 Solution [O(n) complexity]:\n";
	cout << "Implement an algorithm to determine if a string has all unique characters.\n" <<
		"What if you cannot use additional data structures?\n\n";

	while (1) {
		cout << "Input a string (type \"QUIT\" to exit): ";
		string input;
		cin >> input;
		if (input == "QUIT")
			return 0;
		bool is_unique = unique_string(input);
		cout << std::boolalpha << "Is the string unique?: " << is_unique << "\n\n";
	}

	return 0;
}
/*
bool unique_string(string &s) { //bool array solution (technically O(1))
	bool char_set[128];
	for (size_t i = 0; i < s.length(); ++i) {
		int value = s[i];
		if (char_set[value] == true) {
			return false;
		}
		char_set[value] = true;
	}
	return true;
}
*/
bool unique_string(string &s) { //hashmap solution (O(n) time and O(n) space)
	unordered_map<char, bool> mymap;
	for (size_t i = 0; i < s.length(); ++i) {
		mymap[s[i]];
		if (mymap[s[i]] == true) {
			return false;
		}
		mymap[s[i]] = true;
	}
	return true;
}

