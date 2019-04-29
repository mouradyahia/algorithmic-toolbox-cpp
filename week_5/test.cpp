#include <iostream>
#include <algorithm>

using namespace std;
int comp(int a, int b){
	return (a < b);
}

int main(){
	cout << max({-1, 
				 19, 
				 5, 
				 123, 
				 17, 
				 9}, comp);
	return 0;
}
