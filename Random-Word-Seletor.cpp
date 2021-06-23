#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <direct.h>
#include <windows.h>

using namespace std;

int main() {
	
	srand(time(nullptr));
	_mkdir("c:\\WORD TEST");

	/* LIST READ PART */
	string temp;
	
	ifstream readFile;
	readFile.open("c:\\WORD TEST\\word list.txt");
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
	
		cout << "Any words detected in word list.txt file.\nPlease check your C:\\WORD TEST folder." << flush;
		exit(1);
	
	}
	int p = 0;
	cout << "Please type the amount of word as you want.\n";
	cout << "Amount : " << flush;
	cin >> p;
	
	int w = 0;
	cout << "Please type the test paper's width(MUST BE EVEN NUMBER)\n" << flush;
	while (true) {
		cout << "Width : " << flush;
		cin >> w;
		if (w % 2 == 0) break;
	}

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

	/* TABLE BUILD PART */
	//temporary write
	string tw = "";
	string tablearr[3] = {"|word|meaning", "|-|-", "| | "};
	short wcounter = 0;

	for (int i = 0; i < 2; i++) {
		while (wcounter != w) { tw += tablearr[i]; wcounter++; }
		tw += "|\n"; wcounter = 0;
	}

	print.write(tw.c_str(), tw.length());
	tw = "";
	
	while (p --> 0) {

			tw += "|" + r[p] + "| ";
			wcounter++;

			if (wcounter == w) { tw += "|\n"; print.write(tw.c_str(), tw.length()); wcounter = 0; tw = ""; }
			if (p == 0) { 
				
				short a = w - wcounter;
				while ( a != 0 ) {
				
					tw += tablearr[2];
					a--;
				
				}
				tw += "|\n";
				
				print.write(tw.c_str(), tw.length());
			
			}

	}
	print.write("\n", string("\n").length());
	print.close();



	cout << "Printing done! Check your c:\\WORD TEST folder.\n\n\n\n\n";
	cout << "This program will be automatically shutdown after 5 seconds...." << flush;
	Sleep(5000);
	exit(1);
}