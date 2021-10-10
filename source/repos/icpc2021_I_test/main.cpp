#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Person {
public:
	int number;
	int rank1;
	int rank2;
	int rank3;
	int mul;
	int sum;
	Person(int n, int r1, int r2, int r3) {
		number = n;
		rank1 = r1;
		rank2 = r2;
		rank3 = r3;
		mul = rank1 * rank2 * rank3;
		sum = rank1 + rank2 + rank3;
	}
	~Person() {}
};
bool cmp(Person a, Person b) {
	if (a.mul < b.mul)
		return true;
	else if (a.mul > b.mul)
		return false;
	else {
		if (a.sum < b.sum)
			return true;
		else if (a.sum > b.sum)
			return false;
		else {
			if (a.number < b.number)
				return true;
			else
				return false;
		}
	}
}

vector<Person> v;
int main() {
	int n, number, r1, r2, r3, i;
	cin >> n;
	for (i = 0; i < n; ++i) {
		cin >> number >> r1 >> r2 >> r3;
		Person input(number, r1, r2, r3);
		v.push_back(input);
	}
	sort(v.begin(), v.end(), cmp);
	cout << v[0].number << ' ' << v[1].number << ' ' << v[2].number << '\n';

	return 0;
}
