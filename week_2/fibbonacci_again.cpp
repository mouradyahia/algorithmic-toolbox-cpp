#include <iostream>

using namespace std;


long long period_length(long long m){

	long long fib_1 = 1;
    long long fib_2 = 0;
	long long  i = 2;
    long long actual;

	while(true){
        
		actual = (fib_1 + fib_2) % m;
        
    	if(actual == 1 && fib_1 == 0)
			return i-1;

        fib_2 = fib_1 % m;
        fib_1 = actual % m ;

		i++;
	}
	return 0;
}

int main(){
	long long int fib_1, fib_2, n, m, actual;
	
	fib_1 = 1;
	fib_2 = 0;

	cin >> n >> m;
	n = n % period_length(m);

	if(n < 2){
	cout << n;
	return 0;
	}
	for(int i=2; i<=n; i++){
		actual = (fib_1 + fib_2) % m;
		fib_2 = fib_1 % m;
		fib_1 = actual % m;
	}	
	
	cout << actual;

	return 0;
}
