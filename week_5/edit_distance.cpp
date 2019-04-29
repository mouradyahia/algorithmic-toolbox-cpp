#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main(){
	
	string a,b;	
	int ed[105][105], aux;
	
	cin >> a >> b;
	
	for(int i=0; i <= a.size(); i++)
		ed[i][0] = i;
	
	for(int i=0; i <= b.size(); i++)
		ed[0][i] = i;
	
	for(int i=1; i<= a.size(); i++){
		for(int j=1; j <= b.size(); j++){
			aux = ed[i-1][j-1];
			
			if(a[i-1] != b[j-1])
				aux += 1;

			ed[i][j] = min(min(aux, ed[i-1][j] + 1), ed[i][j-1] + 1);
		}
	}

	cout << ed[a.size()][b.size()];
	
	return 0;
}
