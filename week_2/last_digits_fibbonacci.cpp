#include <iostream>

using namespace std;

int main(){
	long long n;
	int fib_1, fib_2, actual;
	fib_1 = 1;
	fib_2 = 0;
	
	cin >> n;
	
	for(long long i=2; i<=n; i++){
		actual = (fib_1 + fib_2) % 10;
		fib_2 = fib_1;
		fib_1 = actual;

	}
	
	cout << actual;
	return 0;
}
