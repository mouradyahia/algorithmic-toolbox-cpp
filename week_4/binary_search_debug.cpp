#include <iostream>

using namespace std;

int n, k, points[10005], searches[10005];

int binary_search(int start, int end, int search){
	
	int mid;
	mid = (start + end) / 2;

	if(start > end)
		return -1;
	
	if(search == points[mid])
		return mid;

	if(search > points[mid])
		return binary_search(mid+1, end, search);
	if(search < points[mid])
		return binary_search(start, mid-1, search);
}

int main(){

	cin >> n;

	for(int i=0; i<n; i++){
		cin >> points[i];
	}

	cin >> k;

	for(int j=0; j<k; j++){
		cin >> searches[j];
	}

	for(int i=0; i<k-1; i++){
		cout << binary_search(0, n-1, searches[i]) << " ";
	}
	cout << binary_search(0, n-1, searches[k-1]);

	return 0;
}
