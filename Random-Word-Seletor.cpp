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
	if (i.size() != 0) {

		cout << i.size() << " words detected.\n";

	}else {
	
		cout << "Any words detected in word.txt file.\nPlease check your c:\\WORD TEST folder." << flush;
		exit(1);
	
	}
	int p = 0;
	cout << "Please type the amount of word as you want.\n" << flush;
	cin >> p;
	
	int w,width = 0;
	cout << "Please type the test paper's width\n";
	cout << "Width : " << flush;
	cin >> w;
	

	//result vector
	vector<string> r(p);

	while (p --> 0) {
		
		if (i.size() == 1) {
			r[p] = i[0];
			continue;
		}
		int a = rand() % (i.size()-1);
		r[p] = i[a];
		i.erase(i.begin()+a);

	}

	/* LIST PRINT PART */
	ofstream print;
	print.open("c:\\WORD TEST\\WORD TEST.md");
	p = r.size();
	short nnc = 0;

	const char* stick = string("|").c_str();
	const char* nls = string("|\n").c_str();
	const char* bar = string("-").c_str();
	const char* nl = string("\n").c_str();
	const char* tt = string(" ").c_str();

	while (p --> 0) {
		
			string j = ("|" + r[p] + "| |\n");
			print.write(j.c_str(), j.length());
			

	}
	print.write(nl, string("\n").length());
	print.close();

}