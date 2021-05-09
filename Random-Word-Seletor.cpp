#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <direct.h>


using namespace std;

int main() {
	
	srand(time(nullptr));
	vector<string> i = { "Tenant","Postpone","Renovate","Archeological","Generate","Relic","Accommodate","Enterprise","Structure","Print","Correction","Issue","Mandatory","Obtainment","Fledging","Highly","Soar","Sanitation","Post","Salaried","Wage","Acquirement","Compensation","Rely on","Objective" };
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

	_mkdir("c:\\WORD TEST");
	ofstream print;
	print.open("c:\\WORD TEST\\WORD TEST.txt");
	p = r.size();
	while (p --> 0) {

		const char* i = (r[p]+=string(" | \n")).c_str();
		print.write( i, r[p].length() );

	}print.close();



}