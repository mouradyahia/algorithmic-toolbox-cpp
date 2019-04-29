#include <iostream>

using namespace std;

int main(){
	size_t n, l, u, m;
	while(cin >> n >> l >> u){
		m = l;
		for(int i=l; i<=u; i++){
			if((n|i)>(n|m)){
				m = i;
			}
		}
		cout << m << "\n";
	}
	return 0;
}
