#include <iostream>

using namespace std;

int main(){
	long long n, l, u, m, aux;
	
	while(cin >> n >> l >>u){
		
		m=0;
	
		for(int i=31; i>=0; i--){
			aux = (1LL << i);
			if( n & aux){
				if (m + aux <= l)
					m += aux;
			}else{
				if (m + aux <= u)
					m += aux;
			}
			
		}
	
		cout << m << "\n";
		
	}
	return 0;
}
