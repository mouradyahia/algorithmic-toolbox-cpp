#include<iostream>
#include<algorithm>

using namespace std;

int main(){
	int change[1005], money;

	cin >> money;
	change[0]=0;
	change[1]=1;
	change[2]=2;
	change[3]=1;
	change[4]=1;
	
	for(int i=5; i<=money;  i++){ // the dp logic
		change[i] = min(min(change[i-1], change[i-3]), change[i-4]) + 1;
	}
	
	cout << change[money];
	return 0;
}
