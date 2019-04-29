#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
	int n, seq_len=1, curr, next;
	
	cin >> n;

	vector<int>a(n), count(n);
	
	for(int i=0; i<n; i++){
		cin >> a[i];
		count[i]=0;
	}

	sort(a.begin(), a.end(), less<int>());
	
	curr = 0;
	next = 1;
	while(next < n){
		if((a[next] == a[curr]))
			seq_len = max(next-curr+1, seq_len);
		else
			curr = next;
		next++;
	}

	cout << (seq_len > (n/2));
	
	return 0;
}
