#include <iostream>
#include <functional>
#include <algorithm>

using namespace std;


int main(){
	long long n, x, y, sum=0;
	vector<long> a,b;
	
	cin >> n;
	
	for(int i=0; i<n; i++){
		cin >> x;
		a.push_back(x);
	}

	for(int i=0; i<n; i++){
		cin >> y;
		b.push_back(y);
	}
	
	sort(a.begin(), a.end(), greater<long long>());
	sort(b.begin(), b.end(), greater<long long>());

	for(int i=0; i<n; i++){
		sum += (a[i] * b[i]);
	}
	
	cout << sum;

	return 0;
}
