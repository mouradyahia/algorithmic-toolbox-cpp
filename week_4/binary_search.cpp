#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

int n, k, points[10005], searches[10005];

int binary_search(int start, int end, int search){
	
	int mid;
	mid = (start + end) / 2;

	if(start > end || search > points[end] || search < points[start])
		return -1;
	
	if(search == points[mid])
		return mid;

	if(search > points[mid])
		return binary_search(mid+1, end, search);
	if(search < points[mid])
		return binary_search(start, mid-1, search);
}

int binary_search_iterative(int size, int x) {
  int left = 0, right = size - 1;
  int mid;
  
  while(left <= right){
    mid = left + (right - left)/2;

    if(points[mid] == x){
      return mid;
    }
    else if(points[mid] < x){
      left = mid + 1;
    }
    else{
      right = mid - 1;
    }
  }
  return -1;
}

int main(){
	srand((unsigned)time(0));
	int aux = 0, res_1, res_2;
	long long int trials=0;
	while(true){
		n = rand() % 100;
		vector<int> a(n);
	
		aux = 0;

		for(int i=0; i<n; i++){
			aux += rand() % 10 + 1;
			points[i] = aux;
			a[i] = aux;
		}

		k = rand() % 15;
		aux = 0;

		for(int j=0; j<k; j++){
			aux += rand() % 10;
			searches[j] = aux;
		}
	
		cout << "trials " << ++ trials << "\n";
		for(int i=0; i<k; i++){
			
			res_1 = binary_search_iterative(n, searches[i]);
			res_2 = binary_search(0, n-1, searches[i]);
			
			if(res_1 != res_2){
				// write down the case
				for(int j=0; j<n; j++)
					cout << points[j] << " ";
				cout << "\n";
				cout << "n = " << n <<"\n";
				cout << "search = " << searches[i] << "\n";
				cout << "iterative = " << res_1 << "\n";
				cout << "my search = " << res_2 << "\n";
				return 0;
			}
		}
	}
	return 0;
}




