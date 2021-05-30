#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <direct.h>

using namespace std;

int main() {
	
	srand(time(nullptr));
	_mkdir("c:\\WORD TEST");

	/* LIST READ PART */
	string temp;
	
	ifstream readFile;
	readFile.open("c:\\WORD TEST\\words.txt");
	if (readFile.is_open()){

		while (!readFile.eof()){

			getline(readFile, temp);

		}

		readFile.close();
	
	}else {
	
		cout << "Any words.txt file detected.\nPlease check your c:\\WORD TEST folder." << flush;
		exit(1);
	
	}

	/* LIST BUILD PART */
	//TODO :: Create vector of word using "temp" string
	vector<string> i;
	string word = "";
	string tempw = "";

	for (int j = 0; j < temp.length(); j++) {
	
		if (int(temp[j]) != 32) {
		
			tempw = temp[j];
			word += tempw;
		
		}else {
		
			i.push_back(word);
			word = "";

		}

	}

	cout << i.size() << " words detected.\n";

	vector<string>::iterator iter = i.begin();

	int p = 0;
	cout << "Write down the amount of word as you want." << "\n" << flush;
	cin >> p;
	//result vector
	vector<string> r(p);

	while (p --> 0) {
		
		int a = rand() % (i.size() - 1);
		r[p] = i[a];
		i.erase(iter+a);

	}

	/* LIST PRINT PART */
	ofstream print;
	print.open("c:\\WORD TEST\\WORD TEST.md");
	p = r.size();
	short nlc = 0;

	while (p --> 0) {
		
			const char* j = (r[p] += string("|\n")).c_str();
			print.write(j, r[p].length());

	}print.close();

}