/*
... iss Crew
... Made by Mukho
... 2020-06-17 Wed
... Practice for C
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{

	return 0;
}

/* 배열
	printf("국영수 과목 총 점수 합계는 %d점이고, 평균 점수는 %f점입니다.\n", sum, (double)sum/3);
	grade = grade[0]
	배열의 길이 자동 설정 : Type arrayName[] = {...};
	ex) int arr[] = {1, 2, 3};
		- 배열의 길이를 선언할 때에는 반드시 상수를 사용해야 함
		- 배열 요소의 인덱스는 언제나 0부터 시작함
		- C 컴파일러는 배열의 길이를 전혀 신경 쓰지 않음
	배열이 차지하는 메모리의 크기 : 배열의 길이 * sizeof(Type) // 배열의 길이 = sizeof(배열이름) / sizeof(배열이름[0])
	다차원 배열에서 원하는 배열 요소만을 초기화할 수 있다. 이때 초기화하지 않은 배열 요소는 모두 0으로 자동초기화된다.
	다차원 배열에서 길이 자동 설정(행의 길이는 반드시 명시해야 한다.) : int arr[][n]
*/
/* 포인터
	데이터의 주소값 : 해당 데이터가 저장된 메모리의 시작 주소.
	포인터 : 메모리의 주소값을 저장하는 변수.
		int n = 100; // 변수의 선언
		int *ptr = &n; // 포인터의 선언
	&(주소연산자) : 해당 주소의 주소값을 반환
	*(참조연산자) : 포인터에 가리키는 주소에 저장된 값을 반환

	포인터의 선언과 초기화(동시)
		type* ptrName = &varName;
	포인터의 참조
		int x = 7; // 변수의 선언
		int *ptr = &x; // 포인터의 선언
		int *pptr = &ptr // 포인터의 참조

	포인터 연산 : 값을 증가시키거나 감소시키는 등의 제한된 연산만을 할 수 있음.
		- 포인터끼리의 덧셈, 곱셈, 나눗셈은 아무런 의미가 없다.
		- 포인터끼리의 뺄셈은 두 포인터 사이의 상대적 거리를 나타냄.
		- 포인터에 정수를 더하거나 뺄 수는 있지만, 실수와의 연산은 허용하지 않음.
		- 포인터끼리 대입하거나 비교할 수 있음.

		++ptr : 타입만큼의 byte 이동

	인수 전달 방법
		Call by Value : 인수로 전달되는 변수가 가지고 있는 값을 함수 내의 매개변수에 복사하는 방식. 함수 내에서의 매개변수 조작은 인수로 전달되는 변수에 아무런 영향을 미치지 않음.
		Call by Reference : 인수로 해당 변수의 주소값을 전달. ex) void local(int*) -> *num += 10;
	
	다양한 포인터
		이중 포인터 : **ptr
			int num = 10; // 변수 선언
			int *ptr_num = &num; // 포인터 선언
			int **pptr_num = &ptr_num; // 포인터의 포인터 선언
		void 포인터 : 대상이 되는 데이터의 타입을 명시하지 않은 포인터. 어떤 값이든 가리킬 수 있지만 포인터 연산이나 메모리 참조와 같은 작업은 할 수 없음.
					  주소값을 저장하는 기능만 있음. void 포인터를 사용할 때에는 반드시 먼저 사용하고자 하는 타입으로 명시적 타입 변환 작업을 거친 후에 사용해야 함.
		함수 포인터 : 함수의 시작 주소를 가리키는 포인터 상수
			함수 원형이 void func(int, int) 일 때, 함수 포인터 : void (*ptr_func)(int, int)
		Null 포인터 : 0이나 NULL을 대입하여 초기화한 포인터. 아무것도 가리키지 않는 포인터.

	포인터와 배열의 관계 : 배열의 이름은 그 값을 변경할 수 없는 상수라는 점을 제외하면 포인터와 같으므로, '배열의 이름' = 포인터 상수(Constant Pointer)
		int arr[3] = {...};
		int *ptr_arr - arr;
		-> ptr_arr = arr[0]
	배열의 포인터 연산
		arr[n] == *(arr + n)

	포인터 배열 : 배열 요소로 변수를 가지는 배열 // int *arr[3] = {&num1, &num2, &num3};
	배열 포인터 : 배열을 가리킬 수 있는 포인터(2차원 이상의 배열에서만 의미를 가짐) ex) arr[2][3] 에서 *arr[0] *arr[1]
	int (*pArr)[3] / int *pArr[3] (배열포인터 / 포인터배열)
*/

/* 메모리의 구조
low memory
	1 - Code 영역 : 실행할 프로그램의 코드 // cpu는 코드 영역에 저장된 명령어를 하나씩 가져가서 처리함.
	2 - Data 영역 : 전역 변수, 정적 변수 // 프로그램의 시작과 함께 할당, 종료와 함께 소멸한다.
	4 - Heap 영역 : 사용자의 동적 할당(런 타임에 크기가 결정됨) : 사용자가 직접 관리하는 공간. 메모리의 낮은 주소에서 높은 주소의 방향으로 할당.
	3 - Stack 영역 : 지역 변수, 매개 변수(컴파일 타임에 크기가 결정됨) : 함수의 호출과 함께 할당, 완료와 함께 소멸.
					 스택 프레임(스택 영역에 저장되는 함수의 호출 정보) : 함수의 호출이 모두 끝난 뒤에 해당 함수가 호출되기 이전 상태로 되돌아갈 수 있다.
					 Push 동작으로 데이터를 저장하고, Pop 동작으로 데이터를 인출한다(LIFO). 높은 주소에서 낮은 주소의 방향으로 할당.
high memory
	Stack Overflow : 재귀 호출이 무한이 반복되는 등 스택의 모든 공간을 사용하는데 또 다시 스택 프레임을 저장하게 되면 발생. -> 오동작 또는 보안상의 크나큰 취약점을 유발
	Dynamic Allocation
		- 데이터 영역과 스택 영역에 할당되는 메모리의 크기는 Compile time에 미리 결정된다.
		- 하지만 힙 영역의 크기는 프로그램이 실행되는 도중인 Run time에 사용자가 직접 결정하게 된다. -> 동적 할당
		malloc() : void *malloc(size_t size); 인수로 할당받고자 하는 메모리의 크기를 바이트 단위로 전달받아 할당되지 않은 적당한 블록을 찾아 첫 번째 바이트를 가리키는 주소값을 반환한다. 적당한 블록이 없으면 Null pointer를 반환하며, 힙 영역에 할당된 메모리 공간으로 접근하려면 포인터를 사용해야 한다.
		free() : void free(void *ptr); 힙 영역에 할당받은 메모리 공간을 다시 os으로 반환해주는 함수. Memory Leak(메모리 누수) 현상을 방지한다.
		calloc() : void *calloc(size_t nmemb, size_t size); 메모리의 크기를 두 개의 인수로 나누어 전달받아 동적 할당하는 함수.
		realloc() : void *realloc(void *ptr, size_t size); 이미 할당된 메모리의 크기를 바꾸어 재할당할 때 사용하는 함수.
					(크기를 바꾸고자 하는 메모리 공간을 가리키는 포인터, 재할당할 크기)
*/

/* 입출력
	stdin : 입력, stdout : 출력
	Stream : 운영체제에 의해 생성되는 가상의 연결 고리
	EOF(End Of File) : 파일의 끝. -1
		in Windows : Ctrl+Z -> Enter // in Unix : 라인의 시작 위치에서 Ctrl+D

	단일 문자 입력 함수
		- getchar() : int getchar(void); 키보드로부터 하나의 문자를 입력받는 함수
		- fgetc() : int fgetc(FILE *stream); 문자를 입력받을 스트림을 인수로 전달하여 직접 지정할 수 있는, 하나의 문자를 입력받는 함수
	단일 문자 출력 함수
		- putchar() : int putchar(int c); 모니터에 하나의 문자를 출력하는 함수
		- fputc() : int fputc(int c, FILE *stream); 문자를 출력할 스트림을 인수로 전달하여 직접 지정할 수 있는, 하나의 문자를 출력하는 함수

	문자열(String) : 큰따옴표("")를 사용해 표현되는 문자열 상수.(이름을 가지고 있지 않으며, 변경할 수 없음) 메모리에 저장된 일련의 연속된 문자들의 집합. 문자열 변수 == 문자열 배열
	Null 문자 : 문자열의 끝을 의미하는 문자(\0, 아스키코드값 0)

	문자열 입력 함수
		- fgets() : char *fgets(char * restrict s, int n, FILE * restrict stream); 키보드, 파일 등에서 문자열을 입력받을 수 있는 함수
					fgets() 함수의 첫 번째 인수는 입력받는 문자열을 저장하기 위해 선언한 배열의 시작 주소를 전달하고, 두 번째 인수로는 입력받을 수 있는 문자열의 최대 길이를 전달하고, 마지막 인수로는 문자열을 입력받을 스트림을 전달한다.
	문자열 출력 함수
		- puts() : int puts(const char *s); 모니터에 하나의 문자열을 출력하고 자동으로 줄을 바꿔주는 함수. 인수로 출력할 문자열을 가리키는 포인터를 전달함.
		- fputs() : int fputs(const char * restrict s, FILE * restrict stream); 모니터 뿐만 아니라 파일을 통해서도 문자를 출력할 수 있는 함수. 자동으로 줄을 바꿔주지 않음. fputs() 함수의 첫 번째 인수는 출력할 문자열을 가리키는 포인터를 전달하고, 두 번째 인수로는 문자열을 출력할 스트림을 전달함.
	
	문자열 처리 함수
		- strlen() : size_t strlen(const char *s); 인수로 저장된 문자열의 길이를 반환하는 함수. Null 문자는 길이에서 제외.
		- strcat() / strncat() : 하나의 문자열에 다른 문자열을 연결해주는 함수. char *strcat(char * restrict s1, const char * restrict s2); / char *strncat(char * restrict s1, const char * restrict s2, size_t n);
								 (기존 문자열, 추가할 문자열, 인수로 추가할 최대 길이(strncat). strcat은 오버플로우가 발생할 수 있음. strncat을 사용해 최대 허용치를 설정하면 오버플로우에서 안전해짐.
		- strcpy() / strncpy() : 문자열을 복사하는 함수. char *strcpy(char * restrict s1, const char * restrict s2); / char *strncpy(char * restrict s1, const char * restrict s2, size_t n);
								strncpy(str02, str01, sizeof(str02)-1); // str02 배열의 크기만큼만 복사를 진행
								str02[sizeof(str02)-1] = '\0'; // 맨 마지막에 Null 문자를 삽입
								strncpy(str+5, "ang", 4) -> 일부분 변경. 배열 이름을 이용한 포인터 연산으로 수정할 부분의 시작 부분을 지정
		- strcmp() / strncmp() : 문자열의 내용을 비교하는 함수. int strcmp(const char *s1, const char *s2); / int strncmp(const char *s1, const char *s2, size_t n);
								 양수 : 첫 번째 인수로 전달된 문자열이 더 큰 경우, 0 : 두 문자열의 내용이 완전히 같은 경우 / 음수 : 두 번째 인수로 전달된 문자열이 더 큰 경우
		- atoi() / atol(), atoll(), atof() : 문자열을 'int형 정수로 / long형 정수로 / long long형 정수로 / double형 실수'로 변환
		- toupper() / tolower() : 영문자를 각각 모두 대문자/소문자로 변환시켜주는 함수
*/