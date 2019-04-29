#include <iostream>

using namespace std;

int main(){
	
	long long int n, fib_1, fib_2, actual, sum=0;
	
	fib_1 = 1;
	fib_2 = 0;
	
	cin >> n;
	n = n % 60;
	
	if(n<2){
		cout << n;
		return 0;
	}	
	sum = 1;
	for(int i=2; i<=n; i++){
		actual = (fib_1 + fib_2) % 10;
		sum += actual;
		sum = sum % 10;
		fib_2 = fib_1 % 10;
		fib_1 = actual;
	}

	cout << sum;

	return 0;
}
