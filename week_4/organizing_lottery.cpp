#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

int bigger(pair<int,int> a, pair<int, int> b){
	return a.first < b.first;
}

int comp(int a, int b){
	return a < b;
}
int main(){
	int s, p, points[50004], aux_1, aux_2, scores[50004] = {0};
	
	vector<pair<int, int>> vec;
	cin >> s >> p;
	vec.reserve(s);

	for(int i=0; i<s; i++){
		cin >> aux_1 >> aux_2;
		vec.push_back(make_pair(aux_1, aux_2));
	}

	for(int i=0; i<p; i++){
		cin >> points[i];
	}
	
	sort(vec.begin(), vec.end(), bigger);
	sort(points, points+p, comp);
	
	int start=0;

	for(int i=0; i<p; i++){
		for(int j=start; j<s; j++){
			if(vec[j].first <= points[i] && vec[j].second >= points[i]){
				scores[i]++;
			}
			if(vec[j].first > points[i]){
				start = j+1;
			}
		}
	}

	for(int i=0; i<p; i++){
		cout << scores[i] << " ";
	}

	// Now search for the last segment that contains the point

	// Now retract until you find segment that ends before point
	// while counting the number of segments that contains the point

	
	return 0;
}
