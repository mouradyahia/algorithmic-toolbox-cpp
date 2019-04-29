#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std;


int main(){
	long long n, d, r, aux, overtime;
	vector<long long> morning, noon;
	
	cin >> n >> d >> r;
	while(n || r || d){
		overtime = 0;

		for(int i=0; i<n; i++){
			cin >> aux;
			morning.push_back(aux);	
		}

		for(int i=0; i<n; i++){
			cin >> aux; 	
			noon.push_back(aux);
		}
		
		sort(morning.begin(), morning.end(), greater<long long>());
		sort(noon.begin(), noon.end(), less<long long>());
	
		for(int i=0; i<n; i++){
			if((morning[i] + noon[i]) > d){
				overtime += (morning[i] + noon[i] - d);
			}
		}		
		cout << (long long)(r * overtime) << endl;

		cin >> n >> d >> r;
		morning.clear();
		noon.clear();
	}

	return 0;
}
