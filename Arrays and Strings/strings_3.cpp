#include <iostream>
#include <string>

using namespace std;

void replace_spaces(string &s, int &length);

int main() {
	cout << "Cracking the Coding Interview - 1.3 Solution [O(n) complexity]:\n";
	cout << "Write a method to replace all spaces in a string with \"%20\". You may assume that the string " << 
	"has sufficient space at the end to hold additional characters, and that you are given the true length of the " << 
	"string.\n\n";

	//Manually put in the string since it is very finicky due to the way cin inputs are read in c++.
	string s = "Hello Mr Way    ";
	int length = 12;

	cout << "Input string: " << s << "\n";

	replace_spaces(s, length);

	cout << "Modified string: " << s << "\n";
	return 0;
}

void replace_spaces(string &str, int &length) {
	int spaces = 0;
	for(int i = 0; i < length; ++i) { //this loop determines the amount of spaces in the string.
		if(str[i] == ' ') {
			spaces++;
		}
	}

	int extended_length = (length + (2*spaces)) - 1; //length + extra space needed which is 2*spaces, -1 to start at the end and not null char.

	for(int j = length - 1; j >= 0; --j) { //starts from the LAST character of the string, and works backwards.
		if(str[j] != ' ') {
			str[extended_length--] = str[j];
		}
		else {
			str[extended_length--] = '0';
			str[extended_length--] = '2';
			str[extended_length--] = '%';
		}
	}



}
