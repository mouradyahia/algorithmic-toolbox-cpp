#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Segment {
	int x, y;
};

bool OrderX(Segment i, Segment j){return (i.x < j.x);}
bool OrderY(Segment i, Segment j){return (i.y < j.y);}

int SearchByX(vector<Segment> segments, int left, int right, int point){
	int pos = -1;

	while(left <= right){
		
		if(left == right) {
			Segment p = segments[left];
			if (p.x <= point)
				pos = left;
			break;
		}

		int mid = (left + right) / 2;

		Segment p = segments[mid];
		if(p.x <= point){
			pos = mid;
			left = mid +1;
		}else 
			if(p.x > point)
				right = mid;
	}
	return pos;
}

int SearchByY(vector<Segment> segments, int left, int right, int point){
	if(segments.empty()) return -1;

	if(left == right){
		return segments[left].y >= point ? left: -1;
	}

	int mid = (left + right) / 2;

	Segment p = segments[mid];

	if(p.y >= point){
		return SearchByY(segments, left, mid, point);
	}
	else
		return SearchByY(segments, left, mid+1, point);
}

vector<int> fast_count_segments(vector<int> starts, vector<int> ends, vector<int> points){
	vector<int> cnt(points.size());
	vector<Segment> segments(starts.size());

	for(size_t i=0; i<segments.size(); ++i){
		segments[i].x = starts[i];
		segments[i].y = ends[i];
	}

	sort(segments.begin(), segments.end(),  OrderX);

	for(int i=0; i<points.size(); i++){
		int pos = SearchByX(segments, 0, segments.size()-1, points[i]);
		if (pos != -1){
			vector<Segment> head(pos+1);
			for(size_t j=0; j<pos+1; j++){
				head[j].x = segments[j].x;
				head[j].y = segments[j].y;
			}

			sort(segments.begin(), segments.end(), OrderY);
			pos = SearchByY(head, 0, head.size()-1, points[i]);
			int c = (pos != -1)? head.size()-pos:0;
			cnt[i] = c;
		}
		else cnt[i] = 0;
	}
	return cnt;
}

int main(){
	int n, m;

	cin >> n >> m;

	vector<int> starts(n), ends(n);
	
	for(size_t i=0; i<n; i++){
		cin >> starts[i] >> ends[i];
	}
	
	vector<int> points(m);

	for(size_t i=0; i<m ;i++){
		cin >> points[i];
	}
	
	vector<int> cnt = fast_count_segments(starts, ends, points);

	for(size_t i=0; i<cnt.size(); i++){
		cout << cnt[i] << " ";
	}

}
