#include <iostream>

using namespace std;

int main(){
	
	long long int fib[61], n, m, sum=0;

	fib[0] = 0;
	fib[1] = 1;

	for (int i=2; i<=60; i++){
		fib[i] = (fib[i-1] + fib[i-2]) % 10;
	}
	
	cin >> m >> n;
	
	m = m % 60;
	n = n % 60;
	for(int i=m; i<=n;i++){
		sum += fib[i];
		sum = sum % 10;
	}
	cout << sum;
	
	/*
	for(int i=0; i<60; i++){
		sum += fib[i] % 10;
	}

	cout << sum % 10;
	
	*/
	return 0;
}
