#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

int main() {
	
	srand(time(nullptr));
	vector<string> i = { "Tenant","Postpone","Renovate","Archeological","Generate","Relic","Accommodate","Enterprise","Structure","Print","Correction","Issue","Mandatory","Obtainment","Fledging","Highly","Soar","Sanitation","Post","Salaried","Wage","Acquirement","Compensation","Rely on","Objective" };
	vector<string>::iterator iter = i.begin();

	int p = 0;
	cout << "Write down the amount of word as you want." << "\n" << flush;
	cin >> p;
	vector<string> r(p);

	while (p --> 0) {
		
		int a = rand() % (i.size() - 1);
		r[p] = i[a];
		i.erase(iter+a);

	}
	
	p = r.size();
	while ( p --> 0 ) { cout << [p] << '\n'; }cout.flush();

}