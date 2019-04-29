#include <iostream>
#include <algorithm>

using namespace std;

bool later(pair<long, long> left,  pair<long, long> right){ return left.second < right.second; }

int main(){
	vector<pair<long,long>> vec;
	vector<long> points;
	long start, end, n, number=0, last_end=0;
	
	cin >> n;
	
	for(int i=0; i<n; i++){
		cin >> start >> end;
		vec.push_back(make_pair(start, end));
	}

	sort(vec.begin(), vec.end(), later);
	
	last_end = vec[0].second;
	number = 1;
	points.push_back(last_end);

	for(int i=1; i<n; i++){
		if(vec[i].first > last_end){
			number++;
			last_end = vec[i].second;
			points.push_back(last_end);
		}		
	}
		
	cout << number<<"\n";
	for(int i=0; i<points.size(); i++){
		cout << points[i] << " ";
	}
	
	return 0;
}
