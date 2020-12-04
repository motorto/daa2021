#include <iostream>
#include <list>

#define MAX 26

using namespace std;

int n;
bool adj[MAX][MAX];
bool visited[MAX];
bool exists[MAX];

string palavras[100];
list<char> answer;

void createAjd(){
	int j=0;
	for (int i = 0 ; i < n-1 ; i++ ){
		j=i+1;
		int size1=(int)palavras[i].length();
		int size2=(int)palavras[j].length();
		for (int a = 0; a < size1 && a < size2 ; a++) {
			if( palavras[i].at(a) != palavras[j].at(a) ) {
				adj[palavras[i].at(a)-'A'][palavras[j].at(a) - 'A'] = true;
				exists[palavras[i].at(a)-'A'] = true;
				exists[palavras[j].at(a)-'A'] = true;
				break;
			}
		}
	}
}

void dfs(int v) {
	visited[v] = true;
	for (int j = 0;  j < MAX ; j++){
		if (adj[v][j] && !visited[j]) {
			dfs(j);
		}
	}
	answer.push_front(v);
}

int main(){
	cin >> n;
	for (int i = 0 ; i < n ; i++)
		cin >> palavras[i];

	createAjd();

	for (int i = 0 ; i < MAX ; i++)
		if (exists[i] && !visited[i])
			dfs(i);

	for (int j : answer)
		cout << (char)(j+'A');

	cout << endl;
	return 0;
}
