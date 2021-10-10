#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<int> selectedStudent; // 각 날짜의 Best Student 저장
map <int, int> student; // Best Student만 저장되어 있는 Map

// Map 비교용 정렬
bool cmp(const pair<int, int>& a, const pair<int, int>& b);
int main() {
	// Get Mukho Style
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// 변수 선언
	int n, q, input, s, e, i, j;
	cin >> n >> q; // N, Q 입력

	// N일간 1위 학생 StuID 기록 및 데이터 처리용 Map에 저장
	for (i = 0; i < n; ++i) {
		cin >> input;
		selectedStudent.push_back(input);

		if (student.empty() == 1 or student.find(input) == student.end())
			student.insert(pair<int, int>(input, 0));
	}

	// S, E를 입력받아 해당 기간동안의 빈도수 측정
	for (i = 0; i < q; ++i) {
		map <int, int> temp = student; // 계산용 Map
		cin >> s >> e; // S, E 입력

		// 빈도수 측정
		for (j = s - 1; j < e; ++j)
			temp[selectedStudent[j]]++;

		// Map을 Vector로 이동 -> vector를 정렬
		vector<pair<int, int>> v(temp.begin(), temp.end());
		sort(v.begin(), v.end(), cmp); // 정렬 함수로 정렬
		cout << v.begin()->first << '\n'; // 출력
	}

	return 0;
}

// 값의 빈도수(.second)가 높을수록, 키의 숫자(.first)가 클수록 우선순위
bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.second > b.second)
		return true;
	else if (a.second == b.second) {
		if (a.first > b.first)
			return true;
		else
			return false;
	}
	else
		return false;
}