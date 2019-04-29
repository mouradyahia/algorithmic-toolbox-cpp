#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <assert.h>

using namespace std;

int main(){
	long long t, n, d, zz, max_, index, available[105], next_step, i, cas=1;
	char aux;
	pair<long long, int> stones[105], a, b;

	cin >> t;
	
	
	while(t--){
	
		cin >> n >> d;
		
		for(int i=0; i<=n+1; i++){
			available[i] = 1;
		}
		
		stones[0] = make_pair(0, 1);
		for(int i=1; i<=n ;i++){
			zz = scanf(" %c-%lld ", &aux, &stones[i].first);
			stones[i].second = aux == 'B'? 1: 0;	
		}
		stones[n+1] = make_pair(d, 1);

		max_ = 0;
		index = 0;
	
		for(i=0; i<=n-1;){
			a = stones[i+1];
			b = stones[i+2];

			if(!a.second && !b.second){
				max_ = max(max_, b.first-index);
				index = b.first;
				available[i+2]=0;
				i+=2;
			}
			
			if(!a.second && b.second){
				// all stay available
				max_ = max(max_, b.first-index);
				i+=2;
				index = b.first;
			}

			if(a.second && !b.second){
				// use a, don't know what next..
				max_ = max(max_, a.first-index);
				i++;
				index = a.first;
			}

			if(a.second && b.second){
				// use a and b, both stay available
				max_ = max(max_, max(b.first-a.first, a.first-index)),
				i+=2;
				index=b.first;
			}

		
		}
		
		if (i==n){
			max_ = max(max_, stones[n+1].first-index);
		}

		// cout << max_ << " after left -> right\n";
	
		for(index=n+1; index>0; ){
			for(next_step=index-1; next_step>=0; next_step--){
				if(available[next_step]){
					max_ = max(max_, stones[index].first - stones[next_step].first);
					index = next_step;
					break;
				}
			}
			
		}

		printf("Case %lld: %lld\n", cas++, max_);
		
	}



	return 0;
}




