#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

struct PersonInfo {
	string name;
	vector<string> phones;
};

int main() {

	string line, word;
	vector<PersonInfo> people;
	while (getline(cin, line)) {
		PersonInfo info;
		istringstream record(line);
		record >> info.name;
		while (record >> word)
			info.phones.push_back(word);
		people.push_back(info);
	}

	for (auto p = people.begin(); p != people.end();++p) {
		cout << p->name << " ";
		for (int i = 0; i < p->phones.size(); ++i) {
			cout << p->phones[i] << " ";
		}
		cout << endl;
	}

	return 0;
}