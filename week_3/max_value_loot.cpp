#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct sort_pred {
	bool operator()(pair<pair<int,int>, double> &left,  pair<pair<int, int>, double> &right){
		return left.second > right.second;
	}
};

bool comparator(pair<pair<int,int>, double> left, pair<pair<int, int>, double> right){return left.second > right.second; }


int main(){
	int n, W;
	double a, b, c, value_sum=0;
	vector<pair<pair<int,int>, double>> vec;
	
	cin >> n >> W;
	
	for(int i=0; i<n; i++){
		cin >> a >> b;
		c = (a / 1.0) / (b / 1.0);
		vec.push_back(make_pair(make_pair(a,b),c));
	}
	

	std::sort(vec.begin(), vec.end(), comparator);

	for(int i=0; i<n; i++){
		if(W > 0){
			if(W >= vec[i].first.second){
				W -= vec[i].first.second;
				value_sum += vec[i].first.second * vec[i].second;
			}else{
				value_sum += W * vec[i].second;
				W = 0;
			}
		}else{
		break;
		}
	}

	//cout << setprecision(10) << value_sum;
	printf("%.4f", value_sum);
	return 0;
}
