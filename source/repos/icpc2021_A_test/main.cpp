#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<int> selectedStudent; // �� ��¥�� Best Student ����
map <int, int> student; // Best Student�� ����Ǿ� �ִ� Map

// Map �񱳿� ����
bool cmp(const pair<int, int>& a, const pair<int, int>& b);
int main() {
	// Get Mukho Style
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// ���� ����
	int n, q, input, s, e, i, j;
	cin >> n >> q; // N, Q �Է�

	// N�ϰ� 1�� �л� StuID ��� �� ������ ó���� Map�� ����
	for (i = 0; i < n; ++i) {
		cin >> input;
		selectedStudent.push_back(input);

		if (student.empty() == 1 or student.find(input) == student.end())
			student.insert(pair<int, int>(input, 0));
	}

	// S, E�� �Է¹޾� �ش� �Ⱓ������ �󵵼� ����
	for (i = 0; i < q; ++i) {
		map <int, int> temp = student; // ���� Map
		cin >> s >> e; // S, E �Է�

		// �󵵼� ����
		for (j = s - 1; j < e; ++j)
			temp[selectedStudent[j]]++;

		// Map�� Vector�� �̵� -> vector�� ����
		vector<pair<int, int>> v(temp.begin(), temp.end());
		sort(v.begin(), v.end(), cmp); // ���� �Լ��� ����
		cout << v.begin()->first << '\n'; // ���
	}

	return 0;
}

// ���� �󵵼�(.second)�� ��������, Ű�� ����(.first)�� Ŭ���� �켱����
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