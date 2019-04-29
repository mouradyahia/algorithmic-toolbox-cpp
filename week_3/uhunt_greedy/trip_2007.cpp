#include <iostream>
#include <algorithm>
#include <functional>
#include <cstring>
#include <fstream>
#include <vector>

using namespace std;

int main(){

	//ifstream cin("input");
	
	long long n;
	cin >> n;

	while(true){
		
		long long array[n], max=1, temp=1;

		for(int i=0; i<n; i++){
			cin >> array[i];
		}

		sort(array, array+n, less<long long>());

		for(int i=0; i<n-1; i++){
			if(array[i] == array[i+1]){
				temp++;
			}else{
				temp = 1;
			}
			if(temp > max){
				max = temp;
			}
		}

		cout << max << "\n";
		
		for(int i=0; i<max; i++){
			temp = i;
			while(temp < n-max){
				cout << array[temp] << " ";
				temp += max;
			}
			cout << array[temp] <<"\n";
		}
		cin >> n;
		if(!n){
			break;
		}
		cout << "\n";
	}
	
	return 0;
}
