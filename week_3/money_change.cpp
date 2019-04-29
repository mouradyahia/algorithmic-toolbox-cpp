#include <iostream>

using namespace std;


int main(){
	int n, coins=0;
	cin >> n;
	
	while(n>=10){
		n -= 10;
		coins += 1;
	}
	while(n>=5){
		n-=5;
		coins += 1;
	}
	while(n>=1){
		n -= 1;
		coins +=1;
	}
	
	cout << coins;
	return 0;
}
