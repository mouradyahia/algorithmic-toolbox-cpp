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
	long long a,b,x,y, max_, min_, gcd_;
	cin >> a >> b;
	
	max_ = max(a,b);
	min_ = min(a,b);
	
	gcd_ = gcd(max_, min_);

	if (gcd_ == 1){
		cout << max_ * min_;
	
	}else{
		if (gcd_ == min_){
			cout << max_;
		}else{
			cout << (max_ / gcd_) * min_;
		}
	}
	
	
	return 0;
}
