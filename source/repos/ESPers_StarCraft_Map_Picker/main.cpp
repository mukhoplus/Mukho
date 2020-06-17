/*
... iss Crew
... Made by Mukho
... 2020-06-17 Wed
... ESPers_StarCraft_Map_Picker
*/
// 맵 고정이니까 대충 만듬.
#pragma warning(disable : 6385) // 오니..?
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

int main()
{
	string map[7] = {"Destination(2)", "Match Point(2)", "Neo Sylphid(3)", "Tau Cross(3)", "Fighting Spirit(4)", "Cirucit Breaker(4)", "Escalade(4)"}; // 맵 목록
	string picked_map[5]; // 골라진 맵을 저장할 배열
	int order[5]; // 맵 순서를 저장할 배열

	int ban_Player1, ban_Player2; // 밴할 맵의 번호가 저장될 변수

	// 맵 목록 출력
	cout << "★맵 목록" << endl;
	for (int i = 0; i < 7; i++)
		cout << i + 1 << " : " << map[i] << endl;
	cout << endl;

	// 첫번째 플레이어의 맵 밴
	while (1)
	{
		cout << "첫번째로 밴할 맵의 번호를 입력해주세요 : ";
		cin >> ban_Player1;
		if (ban_Player1 < 1 or ban_Player1 > 7) // 잘못된 숫자 입력
			cout << "!잘못된 번호입니다." << endl;
		else
			break;
	}

	// 두번째 플레이어의 맵 밴
	while (1)
	{
		cout << "두번째로 밴할 맵의 번호를 입력해주세요 : ";
		cin >> ban_Player2;
		if (ban_Player2 < 1 or ban_Player2 > 7) // 잘못된 숫자 입력
			cout << "!잘못된 번호입니다." << endl;
		else
			if (ban_Player1 == ban_Player2) // 맵 중복 밴
				cout << "!똑같은 맵을 밴했습니다." << endl;
			else
				break;
	}
	// map 배열에서 제거할 용도로 숫자 변환
	ban_Player1--;
	ban_Player2--;

	int temp = 0; // 저장용 변수
	for (int i = 0; i < 7; i++)
	{
		if (i == ban_Player1 or i == ban_Player2)
			continue; // 밴된 맵은 Pass
		picked_map[temp++] = map[i]; // 맵 저장
	}

	// 맵 순서 정하기
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 5; i++)
	{
		int number = rand()%5; // 랜덤 변수
		order[i] = number;
		for (int j = 0; j < i; j++)
			if (order[i] == order[j]) // 중복일 경우 숫자 다시 설정
			{
				i--;
				break;
			}
	}
	
	// 맵 순서 출력
	cout << endl << "★맵 순서" << endl;
	for (int i = 0; i < 5; i++)
		cout << "  " << i + 1 << "Set : " << picked_map[order[i]] << endl;
	cout << endl;

	system("pause");
	return 0;
}