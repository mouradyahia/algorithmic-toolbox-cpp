#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int a[105], b[105], lcs[105][105], a_len, b_len;

	cin >> a_len;
	for(int i=1; i<=a_len; i++)
		cin >> a[i];
	
	cin >> b_len;
	for(int i=1; i<=b_len; i++)
		cin >> b[i];
	
	
	for(int i=0; i<=a_len; i++)
		lcs[i][0] = 0;
	for(int i=0; i<=b_len; i++)
		lcs[0][i] = 0;
	

	for(int i=1; i<=a_len; i++){
		for(int j=1; j<=b_len; j++){
			if(a[i] == b[j])
				lcs[i][j] = lcs[i-1][j-1] + 1;
			else
				lcs[i][j] = max(max(lcs[i-1][j-1], lcs[i-1][j]), lcs[i][j-1]);
		}
	}

	cout << lcs[a_len][b_len];

	return 0;
}
