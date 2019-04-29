#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


bool bigger(string a, string b){
	
	return (a+b) > (b+a);
}


int main(){
	int n;
	string aux;
	vector<string> vec;

	cin >> n;
	for(int i=0; i<n;i++){
		cin >> aux;
		vec.push_back(aux);	
	}
	
	sort(vec.begin(), vec.end(), bigger);
	
	aux = "";
	for(int i=0; i<n; i++){
		aux = aux + vec[i];
	}
	
	cout << aux;
	
	return 0;
}
