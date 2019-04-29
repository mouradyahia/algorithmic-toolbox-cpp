#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
	int n, m, knights[20000], heads[20000], flag=0, k=0;
	long long sum=0;
		cin >> n >> m;
	do{

		if(m < n){
			cout << "Loowater is doomed!\n";
			continue;
		}

		for(int i=0; i<n ;i++){
			cin >> heads[i];
		}
		
		for(int i=0; i<m; i++){
			cin >> knights[i];
		}
		
		sort(knights, knights+m, less<int>());
		sort(heads, heads+n, less<int>());
		
		
		for(int i=0; i<n; i++){

			while((k < m-1) && (knights[k] < heads[i])){
				k++;
			}

			if((k >= m-1) && (knights[k] < heads[i])){
				flag = 1;
				break;
			}

			sum += knights[k];
			k++;
		}

		if(!flag){
			cout << sum << "\n";
		}
		else{
			cout << "Loowater is doomed!\n";
		}

		flag=0;
		sum=0;
		k=0;
		
		cin >> n >> m;
	}while((m!=0) || (n!=0));

	return 0;
}
