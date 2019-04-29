#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main(){
	long long n, aux, T, sum_;
	cin >> T;

	while(T--){

		vector<long> coins, coins_clean ;
			
		cin >> n;

		for(int i=0; i<n; i++){
			cin >> aux;
			coins.push_back(aux);	
		}
		
		if(coins.size() == 1){
			cout << 1;
			return 0;
		}	

		// In all cases, the smallest element and the biggets elements are used.
		coins_clean.push_back(1);

		for(int i=1; i<n-1; i++){
			sum_ = accumulate(coins_clean.begin(), coins_clean.end(), 0);
			if(sum_ + coins[i] < coins[i+1]){
				coins_clean.push_back(coins[i]);
			}
	
		}

		coins_clean.push_back(coins[coins.size()-1]);

		cout << coins_clean.size()<< endl;
	}
	return 0;
}
