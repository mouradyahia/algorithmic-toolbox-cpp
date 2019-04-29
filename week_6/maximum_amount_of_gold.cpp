#include <iostream>

using namespace std;

int main(){
	
	int dp[10001][2]={{0}}, gold[305], W, n, val;
	
	
	cin >> W >> n;

	for(int i=1; i<=n;i++)
		cin >> gold[i];
	
	for(int i=1; i<=n; i++){
		for(int w=1; w<=W; w++){
		
			dp[w][1] = dp[w][0];
			
			if(gold[i] <= w){
				val = dp[w-gold[i]][0] + gold[i];
				if(dp[w][1] < val){
					dp[w][1] = val;
				}
			}	
		}
		
		for(int k=0; k<=W; k++){
			dp[k][0] = dp[k][1];
			dp[k][1] = 0;
		}
	}
	
	cout << dp[W][0];
	
	return 0;
}
