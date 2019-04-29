#include <iostream>
#include <utility>
#include <algorithm>
#include <climits>
#include <stack>

using namespace std;

int steps[1000005], preceds[1000005], values[1000005], n;

int get_preced_pair(int a){

	vector<pair <int, int>> vec; // idx, steps
	int idx=-1, value=10000009;

	if(a % 3 == 0)
		vec.push_back(make_pair(a/3, steps[a/3]));
	if(a % 2 == 0)
		vec.push_back(make_pair(a/2, steps[a/2]));
	
	vec.push_back(make_pair(a-1, steps[a-1]));
	
	for(int i=0; i<vec.size(); i++){
		if(vec[i].second < value){
			value = vec[i].second;
			idx = vec[i].first;
		}
	}
	return idx;
	
}

int main(){
	int idx, product;
	stack<int> s;
	cin >> n;
	steps[1] = 0;
	steps[2] = 1;
	steps[3] = 1;

	preceds[1] = -1;
	preceds[2] = 1;
	preceds[3] = 1;
	
	for(int i=4; i<=n; i++){
		
		idx = get_preced_pair(i);

		if(idx == i/3)
			preceds[i] = i/3;
		if(idx == i/2)
			preceds[i] = i/2;
		if(idx ==  i-1)
			preceds[i] = i-1;

		steps[i] = steps[preceds[i]] + 1;

	}

	cout << steps[n] << "\n";

	while(n != -1){
		s.push(n);
		n = preceds[n];
	}

	while(! s.empty()){
		cout << s.top()<< " ";
		s.pop();
	}
	return 0;
}
