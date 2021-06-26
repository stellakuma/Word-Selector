#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <direct.h>
#include <windows.h>

using namespace std;

const char* VERSION_NAME = "DEVELOPMENT VERSION 2";
const char* REVISION_NUMBER = "3";
const char* TLINE = "\nTyping line >> ";

void line( const char* c ) {
	
	short sw = 119;

	while (sw --> 0) {
	
		cout << c;
	
	}cout << "\n\n" << flush;

}

void printTitle() {

	line("=");
	cout << "RANDOM WORD SELECTOR - " << VERSION_NAME << " REVISION " << REVISION_NUMBER << "\n";
	line("=");

}

bool menu() {

	bool inp = 0;
	cout << "Select the menu (type proper number)\n0 : MAKE PAPER\n1 : HOW TO USE\n" << TLINE << flush;
	cin >> inp;
	if (inp > 1) {
		
		cout << "PLEASE TYPE THE PROPER NUMBER\n" << TLINE << flush;
		cin >> inp;
	
	}

	return inp;

}

void menuTask(bool inp) {

	while (inp != 0){

		if (inp == 1) {

			line("#");
			cout << "First, you need to write list of words at C:\\WORD LIST folder with which name word list.txt\n(Example of word list : hi hello apple charcoal banana land mountain born... like this, you can seperate word with type space bar.)\n\nSecond, just turn on this program and type 0 with enter.\nThan, you will see \"type amount of words\". you can adjust how much words randomly selected.\n\nThird. you can adjust paper's width. surely, this is a english word test paper, so 1 words need 2 blanks.(words itself, write meaning blank)\nSo, this is why you can type width only in even number.\nAfter that, result will save in C:\\WORD LIST folder in with name like WORD TEST.md.\n\nIf there's be any issue, please report bug at cyanpen13@gmail.com.\n";
			line("#");

		}inp = menu();
	
	}

}

int main() {
	
	printTitle();
	srand(time(nullptr));
	_mkdir("c:\\WORD TEST");

	menuTask(menu());

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
	
		cout << "\nAny word list.txt file detected.\nPlease check your c:\\WORD TEST folder." << flush;
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
		
		cout << "\n" << i.size() << " words detected in your word list file. \n";
		line("-");

	}else {
	
		cout << "\nAny words detected in word list.txt file.\nPlease check your C:\\WORD TEST folder." << flush;
		exit(1);
	
	}
	int p = 0;
	cout << "Please type the amount of word as you want.\n" << flush;
	while ( !((p <= i.size()) and (p > 0)) ) {

		cout << TLINE << flush;
		cin >> p;

	}
	line("-");

	int w = 0;
	cout << "Please type the test paper's width(MUST BE EVEN NUMBER)\n" << flush;
	while (true) {
		cout << TLINE << flush;
		cin >> w;
		if (w % 2 == 0) break;
	}
	line("-");

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