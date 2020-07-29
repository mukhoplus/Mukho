/*
... iss Crew
... Made By Mukho
... 2020-07-29 WED
... Get Process-Handler using PID
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <TlHelp32.h>
#include <wchar.h>
#include <vector>
using namespace std;

#define FIND_PROCESS_NAME L"Hwp.exe" // 찾을 프로세스 이름 지정

vector<DWORD> pidList; // 프로세스를 저장할 벡터
vector<HWND> hdrList; // 프로세스 핸들러를 저장할 벡터

void SetProcessList(); // 프로세스 목록을 벡터에 저장

ULONG ProcIDFromWnd(HWND hwnd) // 윈도우 핸들로 프로세스 아이디 얻기   
{
	ULONG idProc;
	GetWindowThreadProcessId(hwnd, &idProc);
	return idProc;
}

HWND GetWinHandle(ULONG pid) // 프로세스 아이디로 윈도우 핸들 얻기   
{
	HWND tempHwnd = FindWindow(NULL, NULL); // 최상위 윈도우 핸들 찾기   

	while (tempHwnd != NULL)
	{
		// 최상위 핸들인지 체크, 버튼 등도 핸들을 가질 수 있으므로 무시하기 위해
		if (GetParent(tempHwnd) == NULL)
			if (pid == ProcIDFromWnd(tempHwnd))
				return tempHwnd;
		tempHwnd = GetWindow(tempHwnd, GW_HWNDNEXT); // 다음 윈도우 핸들 찾기   
	}
	return NULL;
}

void SetProcessList()
{
	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0); // CreateToolhelp32Snapshot()으로 snapshot handle을 얻어옴(TH32CS_SNAPPROCESS = process list)

	if (hSnapshot) // snapshot handle이 null이 아니면
	{
		const WCHAR* findProcessName = FIND_PROCESS_NAME; // 비교 변수에 찾을 process name 저장

		PROCESSENTRY32 ProcessEntry32; // Snap all process
		ProcessEntry32.dwSize = sizeof(PROCESSENTRY32);
		BOOL bProcessFound;
		bProcessFound = Process32First(hSnapshot, &ProcessEntry32); // Get first process(True or False)

		while (bProcessFound) // 첫 process가 존재하면
		{
			if (!wcscmp(ProcessEntry32.szExeFile, findProcessName)) // 현재 process name이 찾을 process name과 같은가
			{
				pidList.push_back(ProcessEntry32.th32ProcessID); // 저장 (Process ID)
			}
			bProcessFound = Process32Next(hSnapshot, &ProcessEntry32); // Get next process
		}
		CloseHandle(hSnapshot); // Close snapshot handle
	}
}

int main()
{
	SetProcessList();

	// 프로세스 리스트, 핸들러 리스트 저장
	for (unsigned int i = 0; i < pidList.size(); i++)
	{
		hdrList.push_back(GetWinHandle(pidList[i]));
		cout << pidList[i] << " // " << hdrList[i] << endl; // 확인용 출력
	}

	return 0;
}