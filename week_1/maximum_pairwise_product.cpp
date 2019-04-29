#include <iostream>
#include <cmath>
#include <vector>
#include <stdlib>
#include <string>
using namespace std;


int main() {
	vector<int> numbers;
	long long max_1 = 0;
	int index_1 = -1;
	long long max_2 = 0;
	int index_2 = -1;
	int aux;
	int n = 0;

	cin >> n;
	
	for(int i=0; i<n; i++){
		cin >> aux;
		numbers.push_back(aux);
	}
	
	for(int i=0; i<n; i++){
		if(numbers[i] >= max_1){
			max_1 = numbers[i];
			index_1 = i;
		}
	}
	
	for(int i=0; i<n; i++){
	 if((numbers[i] >= max_2) && (i != index_1)){
		max_2 = numbers[i];
		index_2 = i;	
	 }
	}
	cout << (max_1 * max_2); 
    return 0;
}
