#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
	int fib [46] = {0,1};
	cin >>n;
	for(int i=2; i<=n; i++){
	fib[i] = fib[i-1] + fib[i-2];
	}
	cout << fib[n];
return 0;
}
