#include <iostream>
#include <vector>

using namespace std;

void merge(int *a, int l, int m, int r, int &n_invert){
	int i=l, j=m+1;
	
	vector<int> d;
	
	while(i <= m || j <= r){
		
		if(i > m){
			d.push_back(a[j]);
			j++;
			continue;
		}
		
		if(i <= m && j > r){
			d.push_back(a[i]);
			i++;
			continue;
		}
		
		if(a[i] < a[j]){
			d.push_back(a[i]);
			i++;
		}else{
			d.push_back(a[j]);
			j++;
		}
	}
	
	for(int i=l; i<=m; i++){
		for(int j=m+1; j<=r; j++){
			if(a[i] > a[j]){
				n_invert++;
			}
		}
	}
	for(int k=0; k<d.size(); k++){
		 a[k+l] = d[k];
	}

}

void merge_sort(int *a, int l, int r, int &n_invert){
	
	int m;

	if(r == l)
		return;
	
	m = (r + l) / 2;

	merge_sort(a, l, m, n_invert);
	merge_sort(a, m+1, r, n_invert);
	merge(a, l, m, r, n_invert);
}

int main(){
	
	int a[100002], n, n_invert=0;
	
	cin >> n;

	for(int i=1; i<=n; i++)
		cin >> a[i];

 	merge_sort(a, 1, n, n_invert);

//	for(int i=1; i<=n; i++)
//		cout << a[i] << " ";

//	cout << "number of inversion: " << n_invert << "\n";
	cout << n_invert;
	return 0;
}
