#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>

cout << "********" << endl;
            cout << stk << endl;
            cout << rpt << endl;
            cout << r[stk] << endl;
            cout << a[rpt] << endl;
            cout << "********" << endl;

using namespace std;

int tof(){
	
	return static_cast<int>(2*(rand()*(1.0/(RAND_MAX+1.0))));
	
}

int main(){
	
	//list size
	int ls = 25;
	//test word list... TODO :: load list from text file
	string a[ls] = {"Tenant","Postpone","Renovate","Archeological","Generate","Relic","Accommodate","Enterprise","Structure","Print","Correction","Issue","Mandatory","Obtainment","Fledging","Highly","Soar","Sanitation","Post","Salaried","Wage","Acquirement","Compensation","Rely on","Objective"};
	
	srand(time(NULL));
    int tg = 0;
    cout << "출력할 단어의 갯수롤 입력해주세요." << endl;
	cin >> tg;
	
	int stk = 0;
	int rpt = 0;
	
	//result word list
	string r[tg] = {"a", };
	
    
	while( stk < tg ){
		cout << "A" << endl;
		if( ls-stk <= tg ){
		    cout << ls-stk << endl;
		
			if( tof() ){
			
				r[stk] = a[rpt];
				stk++;
			
			}
			rpt++;

		}else{
			
			r[stk] = a[rpt];
			rpt++;
			stk++;
			
		}
	}
	
	for( int i = 0; i < tg; i++ ){
		
		cout << r[i] << endl; 
		
	}
   
}