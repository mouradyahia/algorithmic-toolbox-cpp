#include <iostream>
#include <algorithm>

using namespace std;

int comp(int a, int b){
	return (a < b);
}

int main(){
	int lcs[105][105][105]={{{0}}}, a[105], b[105], c[105], a_len, b_len, c_len;

	cin >> a_len;
	for(int i=1; i<=a_len; i++)
		cin >> a[i];
	
	cin >> b_len;
	for(int i=1; i<=b_len; i++)
		cin >> b[i];
	
	cin >> c_len;
	for(int i=1; i<=c_len; i++)
		cin >> c[i];

	for(int i=1 ; i<=a_len; i++)
		for(int j=1 ; j<=b_len; j++)
			for(int k=1; k<=c_len; k++){
				int max_val = max(max(lcs[i-1][j][k], 
									  lcs[i][j-1][k]), 
								  lcs[i][j][k-1]);
					
				if(a[i]==b[j] && b[j]==c[k]){
					lcs[i][j][k] = lcs[i-1][j-1][k-1] + 1;
				}else{	
					lcs[i][j][k] = max_val;
				}
			}
	
	cout << lcs[a_len][b_len][c_len];
	
	return 0;
}
