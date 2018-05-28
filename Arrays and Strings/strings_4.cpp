#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

void createHashTable(string &input, unordered_map<int, int> &mymap);
bool isPalindrome(string &input);

int main() {
	//take the inputted string, and if there's an even number of all characters except for 1 odd number, it is a palindrome.
	string input;
	input = "racecar";
	cout << "Input: " << input << "\n";
	//cin >> input;
	cout << "Is Permutation?: " << std::boolalpha << isPalindrome(input) << "\n";

	return 0;
}

void createHashTable(string &input, unordered_map<int, int> &string_chars) {
	for(size_t i = 0; i < input.length(); ++i) {
		if(input[i] == ' ')
			continue;
		string_chars[tolower(input[i])]++;
	} //inserts every char and its frequency into the table.
}

bool isPalindrome(string &input) {
	unordered_map<int, int> string_chars;
	createHashTable(input, string_chars);

	bool odd_value = false;
	for(auto frequency : string_chars) {
		cout << (char)frequency.first << " " << frequency.second << "\n";
		if(frequency.second % 2 == 1) {
			if(odd_value)
				return false;
			odd_value = true;
		}
	} //checks if it's a possible palindrome.


	return true;
}