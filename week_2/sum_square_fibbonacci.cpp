#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int main(){
	
	long long int fib[60], sum=0, n;
	fib[0] = 0;
	fib[1] = 1;
	
	for(int i=2; i<60; i++){
		fib[i] = (fib[i-1] + fib[i-2]);
	}
		
	for(int i=0; i<60; i++){
		fib[i] = (fib[i] % 10);
		fib[i] *= fib[i];
	}

	cin >> n;
	n = n % 60;
	
	for(int i=0; i<=n; i++){
		sum += fib[i];
	}
	cout  << sum % 10;
	return 0;
}
