#include <iostream>
#include<vector>

using namespace std;

int main() {
	int n=0;
	int cnt = 1;
	cout << "N*N 마방진의 N 값을 입력해주세요(N은 홀수 입니다) : ";
	cin >> n;
	int idx_y = n - 1;
	int idx_x = n / 2 ;
	
	vector < vector <int> > mabang;		
	mabang.assign(n, std::vector<int>(n, 0));	
	mabang.at(idx_y).at(idx_x) = 1;

	while (cnt<n*n) {
		idx_y += 1;
		idx_x += 1;
		if (idx_y >= n && idx_x >= n) {
			idx_x -= 1;
			idx_y -= 2;
		}
		else if (idx_y >= n) {
			idx_y -= n;
		}
		else if (idx_x >= n) {
			idx_x -= n;
		}

		if (mabang.at(idx_y).at(idx_x) != 0) {
			idx_x -= 1;
			idx_y -= 2;
		}
		cnt++;
		mabang.at(idx_y).at(idx_x) = cnt;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << mabang.at(i).at(j) << " ";
		}
		cout << "\n";
	}	
}