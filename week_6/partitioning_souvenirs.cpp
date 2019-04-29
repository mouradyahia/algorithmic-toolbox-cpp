#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


vector<int> dp_fun(int n, int sum, vector<int> v){

	/* Returns the list of elements with the sum at last */
	
	int dp[5000][21] = {{0}}, val, aux;
	vector<int> elems;

	for(int i=1; i<=n; i++){
		for(int s=1; s<= sum; s++){
			dp[s][i] = dp[s][i-1];

			if(v[i] <= s){
				val = dp[s-v[i]][i-1] + v[i];
				if(dp[s][i] < val){
					dp[s][i] = val;
				}
			}
		}
	}

	int s=sum, i=n, flag=0;
	while(i-- && s >= 0 && i >= 0){
		for(int j=1; j<=n; j++){
			if((s-v[i]>=0) && (dp[s][i] == dp[s-v[i]][i-1] + v[i])){
				elems.push_back(v[i]);
				s = s-v[i];
				i = i-1;
				flag=1;
			}
		}
		if(!flag)
			i = i-1;
		flag=0;
	}
	
	elems.push_back(dp[sum][n]);

	return elems;
}

int main(){
	int n, sum=0, aux, first_sum;
	vector<int> v;

	cin >> n;
	v.reserve(n+1);
	v.push_back(0);
	for(int i=1; i<=n; i++){
		cin >> aux;
		v.push_back(aux);
		sum += aux;
	}

	if(sum % 3){
		cout <<  0;
		return 0;
	}

	sum = sum / 3;
	
	vector<int> first_elems = dp_fun(n, sum, v);
	first_sum = first_elems.back();
	first_elems.pop_back();


	if(first_sum != sum){
		cout << 0;
		return 0;
	}

	vector<int> v_aux;

	for(int i=0; i<first_elems.size(); i++)
		for(int j=1; j<=n; j++)
			if(v[j] == first_elems[i]){
				v[j] = -99;
				break;
			}
	
	v_aux.push_back(0);

	for(int j=1; j<v.size(); j++){
		if(v[j] != -99)
		v_aux.push_back(v[j]);
	}
		

	vector<int> second_elems = dp_fun(v.size()-1, sum, v_aux);

	if(second_elems.back() == sum)
		cout << 1;
	else
		cout << 0;
	
	return 0;
}
