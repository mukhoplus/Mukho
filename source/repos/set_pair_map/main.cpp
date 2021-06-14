#include <iostream>
#include <set>
#include <map>
using namespace std;
int main() {
	pair<string, int> p;
	p = { "��¿�", 2016104101 };
	cout << p.first << ' ' << p.second << '\n'; // ��¿� 2016104101
	
	map<string, int> m; // ��� ����� ���� ���� Ʈ��, Key �ߺ� �Ұ���
	// multimap: Key �ߺ� ���
	m.insert(pair<string, int>("��ȣ", 560)); // 3
	m.insert({ "ITX û��", 2400 }); // 1
	m["Made By Google"] = 89; // 2

	map<string, int> ::iterator iter;
	iter = m.begin(); cout << (*iter).first << '\n';
	for (iter = m.begin(); iter != m.end(); iter++)
		cout << iter->first << ' ' << iter->second << '\n';
	
	set<int> s; // ��� ����� ���� ���� Ʈ��, Key �ߺ� �Ұ���
	// set<int> s;
	// multiset: Key �ߺ� ���
	// inorder traversal�� ������� ��� ����
	s.insert(21);
	s.insert(16);
	s.insert(19);
	set<int>::iterator iter_;
	for (iter_ = s.begin(); iter_ != s.end(); ++iter_)
		cout << *iter_ << '\n';
	return 0;
}