#include <iostream>
#include <vector>

using namespace std;

int main(){
	long n, prize=1;
	vector<long> prizes;

	cin >> n;
	
	while(n>2*prize){
		n -= prize;
		prizes.push_back(prize);
		prize++;
	}
	// prize += n;
	prizes.push_back(n);
	
	cout << prizes.size() << "\n";
	
	for(int i=0; i<prizes.size(); i++){
		cout << prizes[i] << " ";
	}

	return 0;
}
