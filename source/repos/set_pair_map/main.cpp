#include <iostream>
#include <set>
#include <map>
using namespace std;
int main() {
	pair<string, int> p;
	p = { "고승완", 2016104101 };
	cout << p.first << ' ' << p.second << '\n'; // 고승완 2016104101
	
	map<string, int> m; // 노드 기반의 균형 이진 트리, Key 중복 불가능
	// multimap: Key 중복 허용
	m.insert(pair<string, int>("묵호", 560)); // 3
	m.insert({ "ITX 청춘", 2400 }); // 1
	m["Made By Google"] = 89; // 2

	map<string, int> ::iterator iter;
	iter = m.begin(); cout << (*iter).first << '\n';
	for (iter = m.begin(); iter != m.end(); iter++)
		cout << iter->first << ' ' << iter->second << '\n';
	
	set<int> s; // 노드 기반의 균형 이진 트리, Key 중복 불가능
	// set<int> s;
	// multiset: Key 중복 허용
	// inorder traversal로 순서대로 출력 가능
	s.insert(21);
	s.insert(16);
	s.insert(19);
	set<int>::iterator iter_;
	for (iter_ = s.begin(); iter_ != s.end(); ++iter_)
		cout << *iter_ << '\n';
	return 0;
}