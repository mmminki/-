// -�� ������ ���� - �� ���Ë����� ������ ���� ������?

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
vector<string> split(string input, char delimiter);
using namespace std;

int main() {
	string s;
	cin >> s;

	int length = sizeof(s);
	int index = 0;

	for (int i = 0; i < length; i++) {
		if (s[i] == '-') {

		}
	}
}

vector<string> split(string input, char delimiter) {
	vector<string> result;
	stringstream mystream(input);
	string splitdata;

	while (getline(mystream, splitdata, delimiter)) {
		result.push_back(splitdata);
	}
	return result;
}
