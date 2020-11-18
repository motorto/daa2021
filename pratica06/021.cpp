#include<iostream>
#include<set>
#include<string.h>

using namespace std;

int main()
{
	int aditions,removals;
	int valor;
	char tmp[3];
	multiset<int> s;

	cin >> aditions;
	cin >> removals;

	for(int i=0;i<aditions+removals;i++){
		cin >> tmp; 
		if (strcmp("BAK",tmp) == 0) {
			cin >> valor;
			s.insert(valor);
		}
		else {
			if (strcmp(tmp,"MAX") == 0) {
				cout << *(--s.end()) << endl;
				s.erase(--s.end());
			}
			else if (strcmp(tmp,"MIN") == 0){
				cout << *(s.begin()) << endl;
				s.erase(s.begin());
			}
		}
	}
	return 0;
}
