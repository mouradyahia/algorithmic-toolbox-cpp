#include <iostream>

using namespace std;

int gcd(long long a, long long b){
	long long max_, min_, res;
	if(a == 0)
	return b;
	max_ = max(a,b);
	min_ = min(a,b);
	res = max_ % min_;
	return gcd(res, min_);
}

int main(){
	long long a,b;
	cin >> a >> b;
	cout << gcd(a,b);

	return 0;
} 
