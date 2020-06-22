/*
... iss Crew
... Made By Mukgo
... 2020-06-22 MON
... Container Practice(vecter, list)
*/
#include <iostream>
#include <vector> // vector : 랜덤 접근에 유리함
#include <list> // list : doubly linked list와 구조가 같음. 중간 값들의 삽입 삭제에 유리
using namespace std;


bool P(int n)
{
	return (n <= 4);
}

int main()
{
	vector<int> vList; // 비어있는 vector vList를 생성
	// vector<int> vList(5); : 기본값(0)으로 초기화 된 5개의 원소를 가지는 vector vList를 생성
	// vector<int> vList(5, 2); : 2로 초기화 된 5개의 원소를 가지는 vector vList를 생성
	// vector<int> v2(v1); : v2는 v1을 복사해서 생성
	/*
	vList.assign(5, 0); // 0의 값으로 5개의 원소 할당
	vList.at(index); : index번째 원소를 참조. 범위를 점검해 안전
	vList[index]; : index번째 원소를 참조. 빠름
	vList.front(); : 맨 앞 데이터 참조
	vList.back(); : 맨 뒤 데이터 참조
	vList.push_back(22); : 맨 뒤에 22 삽입
	vList.push_pop(); : 맨 뒤 데이터 삭제
	vList.clear(); : 모든 원소를 제거. 단, 메모리는 남아있다.
	vList.begin(); == vList.rend(); : 첫번째 데이터를 가리킴
	vList.end(); == vList.rbegin(); : 마지막 데이터의 다음을 가리킴

	vList.reserve(n); : n개의 데이터를 저장할 위치를 미리 동적할당 함
	vList.resize(n); : 크기를 n으로 변경, 더 커졌을 경우 0으로 초기화
	vList.resize(n, 3); 크기를 n으로 변경, 더 커졌을 경우 3으로 초기화
	vList.size(); : 데이터의 갯수를 리턴
	vList.capacity(); : 할당된 공간의 크기를 리턴
	v2.swap(v1); : 데이터를 서로 바꿈

	vList.insert(2,3,4); : 2번째 위치에 4를 3개 삽입
	vList.insert(2,3); : 2번째 위치에 3을 삽입
	vList.erase(index); : index번째의 데이터를 제거
	vList.empty(); vector가 비었으면 true
	*/
	
	cout << "★VECTOR" << endl << endl;
	cout << "1 3 2 100 22 삽입 후 맨 마지막 데이터 삭제" << endl;
	vList.push_back(1);
	vList.push_back(3);
	vList.push_back(2);
	vList.push_back(100);
	vList.push_back(22);
	vList.pop_back();

	// 일단 출력
	cout << "vList[i]꼴과 vList.at(i) 꼴로 각각 출력" << endl;
	for (int i = 0; i < vList.size(); i++)
		cout << vList[i] << " ";
	cout << endl;
	for (int i = 0; i < vList.size(); i++)
		cout << vList.at(i) << " ";
	cout << endl << endl;

	cout << "크기 : " << vList.size() << endl;
	cout << "첫번째 : " << vList.front() << endl;
	cout << "마지막 : " << vList.back() << endl;
	cout << endl << endl;

	cout << "3번째 위치에 5 삽입 후 첫번째 위치의 데이터 삭제" << endl;
	vList.insert(vList.begin() + 3, 5);
	vList.erase(vList.begin() + 0);
	cout << "크기 : " << vList.size() << endl;
	for (int i = 0; i < vList.size(); i++)
		cout << vList.at(i) << " ";
	cout << endl << endl;

	cout << "벡터 리스트 초기화" << endl;
	vList.clear();
	cout << "크기 : " << vList.size() << endl;
	for (int i = 0; i < vList.size(); i++)
		cout << vList.at(i) << " ";
	cout << endl << endl << endl << "------------------------------------------------------" << endl;

	cout << "★LIST" << endl << endl;
	list<int> lList; // 비어있는 list 생성
	// list<int> lList(10); : 0으로 초기화된 값 10개를 가진 list 생성
	// list<int> lList(3, 2); : 2로 초기화 된 값 3개를 가진 list 생성
	// list<int> l2(l1); : l2에 l1을 복사해서 생성

	/*
	lList.assign(3, 4); : 4로 초기화 된 3개의 데이터를 할당
	lList.front(); : 맨 앞의 데이터 참조
	lList.back(); : 맨 뒤의 데이터 참조
	lList.begin(); == lList.rend(); : 맨 앞의 원소를 가리킴
	lList.end(); == lList.rbegin() : 맨 뒤 원소 다음을 가리킴

	lList.push_front(5); : 맨 앞에 5를 삽입
	lList.push_back(5); : 맨 뒤에 5를 삽입
	lList.pop_front(); : 맨 앞 데이터 제거
	lList.pop_back(); : 맨 뒤 데이터 제거
	lList.insert(iter, 2); : iter 위치에 2 삽입
	lList.erase(iter); : iter 위치에 있는 데이터 삭제
	lList.clear(); : 전체 삭제

	lList.size(); : 데이터 갯수 반환
	lList.remove(2); : 2인 데이터 모두 삭제
	lList.remove_if(Predicate); : 단항 조건자 Predicate에 해당하는 데이터 모두 삭제
	lList.reverse(); : 뒤집음
	lList.sort(); : 정렬
	l2.swap(l1); : l2와 l1을 바꿈
	l2.splice(iter2, l1); : l2에서 iter2가 가리키는 곳에 lt의 모든 데이터를 삽입함
	l2.splice(iter2, l1, iter1); : l2에서 iter2가 가리키는 곳에 l1의 iter1이 가리키는 데이터를 삽입
	l2.splice(iter2, l1, iter1_1, iter1_2); : l2에서 iter2가 가리키는 곳에 l1의 iter1_1 이상 iter1_2 미만 까지의 데이터를 삽입함
	lList.unique(); : 인접한 곳의 데이터가 같으면 하나로 합침
	l2.merge(l1) : l1을 l2로 합병 정렬함
	*/

	list<int>::iterator iter; // 반복자.
	iter = lList.begin();

	cout << "앞에 1, 앞에 0, 뒤에 2, 뒤에 3, 뒤에 55를 삽입(0 1 2 3 55)" << endl;
	lList.push_front(1);
	lList.push_front(0);
	lList.push_back(2);
	lList.push_back(3);
	lList.push_back(55);
	for (iter = lList.begin(); iter != lList.end(); iter++)
		cout << *iter << ' ';
	cout << endl;
	
	cout << "그 후에 2번째 위치의 데이터와 맨 앞, 맨 뒤를 삭제함(2 3)" << endl;
	iter = lList.begin();
	lList.begin()++;
	lList.begin()++;
	lList.erase(iter);
	lList.pop_front();
	lList.pop_back();

	for (iter = lList.begin(); iter != lList.end(); iter++)
		cout << *iter << ' ';
	cout << endl << endl;

	cout << "리스트 초기화 후 리스트에 1부터 20까지, 7 3개 삽입" << endl;
	lList.clear();
	for (int i = 1; i < 20; i++)
		lList.push_back(i);
	for (int i = 0; i < 3; i++)
		lList.push_back(7);
	for (iter = lList.begin(); iter != lList.end(); iter++)
		cout << *iter << ' ';
	cout << endl;

	cout << "7 전체 삭제 및 4 이하 삭제, 5번째 데이터 삭제(10) 후 5번째에 69 삽입" << endl;
	lList.remove(7);
	lList.remove_if(P);

	iter = lList.begin();
	for (int i=0; i < 4; i++)
		iter++;
	lList.erase(iter);

	iter = lList.begin();
	for (int i = 0; i < 4; i++)
		iter++;
	lList.insert(iter, 69);

	for (iter = lList.begin(); iter != lList.end(); iter++)
		cout << *iter << ' ';
	cout << endl;

	return 0;
}