#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	int T, n;
	string field;

	cin >> T;
	
  	while(T--){
		cin >> n;
		cin >> field;

		for(int i=0; i<n-1 ; i++){
  			if( field[i]=='.' && field[i+1] =='.'){
				field[i+1] = 's';
			}

			if(field[i]=='.' && field[i+1]=='#' && i>0 && field[i-1] != 's'){
				field[i] = 's';
			}
		}

		if(field[n-1]=='.' && field[n-2]=='#'){
			field[n-1] = 's';
		}
		
		cout << count(field.begin(), field.end(), 's') << endl;		
			
	}

	return 0;
}
