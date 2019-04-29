#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


int main(){
	int T, n, total_count;
	string field;
	
	cin >> T;
	
  	for(int w=1; w<=T; w++){ 
		cin >> n;
		cin >> field;

		for(int i=0; i<n-2 ; i++){
  			if( field[i]=='.'){
				field[i] = 'e';
				field[i+1] = 's';
				field[i+2] = 'e';
			}
		}

		if(field[n-1]=='.' || field[n-2]=='.'){
			field[n-1] = 's';
			field[n-2] = 'e';
		}

		total_count = count(field.begin(), field.end(), 's') ;
		printf("Case %d: %d\n", w, total_count);		
			
	}

	return 0;
}
