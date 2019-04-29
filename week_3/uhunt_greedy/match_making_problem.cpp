#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
	int b=1, s=1, cas=1;
	int b_arr[10000], s_arr[10000];

	while( b!=0 && s!=0){
		cin >> b >> s;
		
		if(b==0 && s==0){
			return 0;
		}


		for(int i=0; i<b; i++){
			cin >> b_arr[i];
		}
		for(int i=0; i<s; i++){
			cin >> s_arr[i];
		}

		if(b<=s){
			printf("Case %d: 0\n", cas);
			cas++;
			continue;
		}

		sort(b_arr, b_arr+b, greater<int>());
		
		printf("Case %d: %d %d\n", cas, b-s, b_arr[b-1]);
		cas++;
	}

	return 0;
}
