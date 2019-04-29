#include <iostream>

using namespace std;

int main(){
	int n, nums[1000], count, k;
	
	cin >> n;
	while(n > 0){
		// printf("n == %d", n);
		count = 0;

		for(int i=0; i<n ; i++){
			cin >> nums[i];
			if(nums[i]){
				count++;
			}
		}
		if(count ==0){
			cout << "0\n";
			cin >> n;
			continue;
		}
		k=0;

		for(int i=0; i<n; i++){
			if(nums[i]){
				if(k < count-1){
					cout << nums[i] << " ";
					k++;
				}else{
					cout << nums[i] << "\n";
					break;
				}

			}
		}

		cin >> n;
	}
	return 0;
}
