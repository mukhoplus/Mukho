/*
... iss Crew
... Made By Mukho
... 2020-07-29 WED
... Get Process Name I Want
*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <TlHelp32.h>
#include <wchar.h>
using namespace std;

#define FIND_PROCESS_NAME L"chrome.exe" // 찾을 프로세스 이름 지정

void PrintProcessList();

int main()
{
	PrintProcessList();
	return 0;
}

void PrintProcessList()
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
			if (!wcscmp(ProcessEntry32.szExeFile, findProcessName) && IsWindowVisible) // 현재 process name이 찾을 process name과 같은가
			{
				printf("%ls [%d]\n", ProcessEntry32.szExeFile, ProcessEntry32.th32ProcessID); // 출력 ( Process PID )
			}
			bProcessFound = Process32Next(hSnapshot, &ProcessEntry32); // Get next process
		}
		CloseHandle(hSnapshot); // Close snapshot handle
	}
}