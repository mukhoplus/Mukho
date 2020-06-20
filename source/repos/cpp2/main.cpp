/*
... iss Crew
... Made by Mukho
... 2020-06-20 SAT
... Practice for C++
*/
#include <iostream>
using namespace std;

int main()
{

	return 0;
}

/* C언어 스타일의 문자열
	C++ cin : 이름에 띄어쓰기가 들어가면 도시명을 입력할 수 없다 ex) cin >> "강원도 동해시" -> 강원도 / 동해시
			: 지정된 SIZE 이상의 이름이나 도시명을 입력하면 프로그램이 강제 종료된다
			: 띄어쓰기를 포함한 탭 문자, 캐리지 리턴 문자 등을 모두 문자열의 끝으로 인식함.

				const int SIZE = 20;
				char name[SIZE];
				char address[SIZE];

				cout << "이름 : ";
				cin.get(name, SIZE).get(); -> 띄어쓰기를 포함한 문자열을 정확히 입력받을 수 있으나, 20바이트 이상의 이름을 입력하면 도시명을 입력할 수 없다.
				cin.get(assress, SIZE).ignore(SIZE, '\n'); -> 20바이트 이상의 문자열을 입력받아도 20바이트까지만 입력받음.
				-> 번거롭지? string 쓰자.

				string name, address;
				getline(cin, name);
				getline(cin, address);
				-> 문자열의 띄어쓰기 문제나 문자열의 길이와 상관없이 모든 문자열을 정확히 입력받을 수 있음.

	C언어 문자열 처리 함수 : cstring.h
			
	string 클래스 : string.h
					string 객체 입력받기 : getline(cin, name);

					string 객체는 문자열을 단순한 변수로 선언함. -> 사용자가 길이를 명시하지 않아도 되며, 문제는 C++ Program이 자동으로 처리해 준다.
					string name = "chaewon";
					cout << name.length() << endl; // 7
					cout << name[0] << endl; // c

					대입 : string name = "chaewon";
						   string temp;
						   temp = name; // temp -> chaewon

					추가, 결합 : += or append()
	string 메소드
					length(), size() : 문자열의 길이 반환. length는 문자열의 길이, size는 string 객체가 메모리에서 실제 사용하고 있는 크기
					append() : 하나의 문자열의 끝에 다른 문자열을 추가하는 메소드
								문자열.append(추가할문자열);
								문자열.append(추가할문자열, 시작위치, 마지막위치); // 추가할 문자열의 시작위치~마지막위치까지만 추가함.
								문자열.append(개수, 추가할문자);
					find() : 특정 문자열을 찾아, 그 시작 위치를 반환하는 메소드
								문자열.find(찾을문자열);
								문자열.find(찾을문자);
								문자열.find(찾을문자열, 시작위치);
							 만약 해당 문자열에서 찾을 문자열을 찾지 못하면, string::size_type의 string::npos라는 상수를 반환한다.(-1)
					compare() : 두 문자열간의 내용 비교
									str1.compare(str2) == 0 // str1과 str2가 같음
													   < 0 // str1이 str2보다 사전 편차순으로 앞에 있음
													   > 0 // str1이 str2보다 사전 편차순으로 뒤에 있음
					replace() : 특정 문자열을 찾아, 그 문자열을 다른 문자열로 대체하는 메소드
									문자열.replace(대체할문자열의시작위치, 대체할문자열의길이, 새로운문자열);
									// 전달된 시작 위치부터 문자열의 길이만큼 제거한 후, 새로운 문자열을 삽입함.
										string str1 = "C++ is very nice!";
										string str2 = "nice";
										string str3 = "awesome";
										
										string::size_type index = str1.find(str2); // str1에서 str2를 찾아, 그 시작위치를 저장
										if (index != string::npos) // 찾았으면
											str1.replace(index, str2.length(), str3); // str1에서 시작위치부터 str2 길이만큼 없애고 str3을 추가함.
										cout << str1; // "C++ is very awesome!"
					capacity(), max_size() : capacity는 해당 문자열이 재대입(reallocation)받지 않고 저장할 수 있는 최대 문자열의 길이를 반환
											 max_size는 해당 문자열이 최대한 대입받으면 가질 수 있는 최대 문자열의 길이를 반환
*/
/* 구조체
	C++에서는 구조체를 정의할 때 멤버 변수로 또 다른 구조체를 포함할 수 있다.
*/
/* Function Pointer
	함수의 시작 주소를 가리키는 포인터 상수
	포인터 타입은 함수의 반환값과 매개변수에 의해 결정됨
		함수 원형 : void Func(int, int);
		함수 포인터 : void (*ptr_func)(int, int);

			#include <iostream>
			using namespace std;

			double Add(double, double);
			double Sub(double, double);
			double Mul(double, double);
			double Div(double, double);
			double Calculator(double, double, double (*func)(double, double));

			int main(void)
			{
				double (*calc)(double, double) = NULL; // 함수 포인터 선언
				double num1 = 3, num2 = 4, result = 0;
				char oper = '*';

				switch (oper)
				{
				case '+':
					calc = Add;
					break;
				case '-':
					calc = Sub;
					break;
				case '*':
					calc = Mul;
					break;
				case '/':
					calc = Div;
					break;
				default:
					cout << "사칙연산(+, -, *, /)만을 지원합니다.";
					break;
				}
				result = Calculator(num1, num2, calc);
				cout << "사칙 연산의 결과는 " << result << "입니다.";
	
				return 0;
			}

			double Add(double num1, double num2) { return num1 + num2; }
			double Sub(double num1, double num2) { return num1 - num2; }
			double Mul(double num1, double num2) { return num1 * num2; }
			double Div(double num1, double num2) { return num1 / num2; }
			double Calculator(double num1, double num2, double (*func)(double, double)) { return func(num1, num2); }

		함수 포인터의 표기법 : double (*calc)(double, double) = NULL; // 복잡함

							   typedef double (*calcFunc)(double, double) // 함수 포인터에 calcFunc이라는 새로운 이름을 붙임
							   calcFunc ptr_func = calc;

							   auto ptr_func = calc;
*/
/* 참조자(reference)
	특정 변수의 실제 이름 대신 사용할 수 있음
		int 변수이름; // 변수의 선언
		int& 참조자이름 = 변수이름; // 참조자 선언. int& = int형에 대한 참조. 대상 변수와 같은 메모리 위치를 참조하게 됨
	참조자는 주로 함수의 인수로서 전달할 때 사용됨.
		- 함수가 참조자를 인수로 전달받으면, 참조자가 참조하고 있는 실제 변수의 값을 함수 내에서 조작할 수 있음.

		void Swap(int& x, int& y){ ... } -> Call by Reference
			- call by pointer와 사용 방법과 결과는 같음.
			- 함수 내에서 참조 연산자 (*)를 사용하지 않아 함수 내부의 코드가 깔끔하고 직관적임.
			- 다만, 함수의 호출이 call by value와 같은 형태라 코드 읽기가 쉽지 않음.
			- 고로 간단한 함수에서는 call by value를, 참조 호출이 꼭 필요할 때는 call by pointer를 쓰자.
			- C++에서 참조자는 크기가 큰 구조체나 클래스를 다룰 때에만 사용하는 것이 좋다.

			struct Book
			{
				string title;
				string author;
				int price;
			};
			void Display(const Book&);
			int main(void)
			{
				Book web_book = {"HTML과 CSS", "홍길동", 28000};
				Display(web_book);
				return 0;
			}
			void Display(const Book& bk)
			{
				cout << "책의 제목은 " << bk.title << "이고, ";
				cout << "저자는 " << bk.author << "이며, ";
				cout << "가격은 " << bk.price << "원입니다.";
			}
*/
/* 디폴트 인수(default argument)
	기본값이 미리 정의되어 있는 인수
		- 함수의 원형에만 지정할 수 있다.
		- 가장 오른쪽에부터 시작하여 순서대로만 지정할 수 있다.
		- 가운데 인수들만 별도로 디폴트 인수를 지정할 수는 없다.
		void Display(int x, int y, char ch, int z = 4);
	함수로 전달된 인수는 왼쪽부터 순서대로 매개변수 목록에 대입됨. 인수 전달은 건너뛸 수 없다.
*/
/* 함수 오버로딩(function overloading)
	같은 이름의 함수를 중복하여 정의하는 것
	여러 함수를 하나의 이름으로 연결해 줌. 같은 일을 하는 함수를 매개변수의 형식을 조금씩 달리하여, 하나의 이름으로 작성할 수 있게 해주는 것.
	-> 객체 지향 프로그래밍의 특징 중 다형성(polymorphism)의 구현

	함수 시그니처 - 함수의 원형에 명시되는 매개변수 리스트
	함수의 오버로딩 : 서로 다른 시그니처를 갖는 여러 함수를 같은 이름으로 정의하는 것
		void add(int, int);
		void add(int, double);
		void add(double, int);
		void add(double, double);
		-> 사용자가 add() 함수를 호출하면,C++ 컴파일러는 자동으로 같은 시그니처를 가지는 함수의 원형을 찾아 호출함.
*/
/* 인라인 함수
	...함수가 호출되면 우선 스택에 함수로 전달할 매개변수와 함께 호출이 끝난 뒤 돌아갈 반환 주소값을 저장하게 됩니다.
	그리고서 프로그램의 제어가 함수의 위치로 넘어와 함수 내에 선언된 지역 변수도 스택에 저장합니다.
	그때부터 함수의 모든 코드를 실행하게 되고, 실행이 전부 끝나면 반환값을 넘겨 줍니다.
	그 후 프로그램의 제어는 스택에 저장된 돌아갈 반환 주소값으로 이동하여, 스택에 저장된 함수 호출 정보를 제거합니다.
	이와 같은 일련의 함수 호출 과정이 함수마다 일어나게 됩니다....
	-> C++에서 함수의 호출은 꽤 복잡한 과정을 거치기 때문에 약간의 시간이 걸리게 됨
	   함수를 실행하는 시간이 오래 걸린다면, 함수를 호출하는데 걸리는 시간은 전혀 문제가 되지 않으나
	   함수의 실행 시간이 매우 짧다면, 함수 호출에 걸리는 시간도 부담이 될 수 있음.
	인라인 함수는 호출될 때 일반적인 함수의 호출 과정을 거치지 않고, 함수의 모든 코드를 호출된 자리에 바로 삽입하는 방식의 함수.
	-> 함수를 호출하는 데 걸리는 시간은 절약되나, 함수 호출 과정으로 생기는 여러 이점을 포기하게 됨.
	   따라서 코드가 매우 적은 함수만을 인라인 함수로 선언하는 것이 좋다.

	inline 함수의 원형 / inline 함수의정의 : 둘 중 하나만, 둘 다 표기해도 상관없다.
	보통의 인라인 함수는 크기가 작아 함수의 원형이 나오는 자리에 함수의 본체까지 함께 정의하는 경우가 많음. // 인라인 함수에서는 재귀 호출이 허용되지 않음.
*/
/* 유효 범위와 연결
	유효 범위(scope) : 하나의 변환 단위 내에서 해당 변수가 사용될 수 있는 범위
	연결(linkage) : 해당 변수를 사용할 수 있는 파일의 접근 가능 여부
		- 외부 연결(external linkage) : 여러 파일에서 사용 가능
		- 내부 연결(internal linkage) : 하나의 파일에서만 사용 가능

	자동 변수(automatic variable) : 블록 내에서 선언된 변수(함수의 매개변수도 포함)
									선언된 블록 내에서만 유효. 블록이 종료되면 메모리에서 사라짐
									메모리상의 스택 영역에 저장됨, 초기화 안하면 쓰레깃값으로 초기화됨
									C언어의 지역 변수와 같은 의미
	연결을 가지지 않는 정적 변수 : 블록 내부에서 static 키워드를 사용하여 정의됨.
								   지역 변수와 전역 변수의 특징을 모두 가지게 됨 - 전역 변수처럼 단 한번만 초기화되며, 프로그램이 종료되어야 메모리상에서 사라짐. 지역 변수처럼 해당 블록 내에서만 접근할 수 있음.
	내부 연결을 가지는 정적 변수 : 유효 범위를 변환 단위로 가지는 변수에 static 키워드를 사용하여 정의함.
								   현재 파일에서만 사용 가능. 하나의 파일 내의 모든 블록에서 접근할 수 있고, 또한 사용할 수 있음.
	외부 연결을 가지는 정적 변수 : 유효 범위를 변환 단위로 가지는 변수. 전역 변수 or 외부 변수라고 함.
								   외부 파일에서도 사용 가능. 해당 변수를 사용하는 모든 파일에서 각각 extern 키워드를 사용하여 재선언되어야 사용 가능함.
*/
/* 클래스
	구조체의 상위 호환.
	객체 지향 프로그래밍의 특징 중 하나인 추상화(abstraction)를 사용자 정의 타입으로 구현한 것
	객체 지향 프로그래밍 : 객체의 상태와 행동을 구체화하는 형태의 프로그래밍
		- 추상화(abstraction)
		- 캡슐화(encapsulation)
		- 정보 은닉(data hiding)
		- 상속성(inheritance)
		- 다형성(polymorphism)
	클래스 : 이와 같은 객체를 만들어 내기 위한 틀과 같은 개념
	인스턴스(instance) : 선언된 해당 클래스 타입의 객체. 메모리에 대입된 객체
		- 하나의 클래스에서 여러 개의 인스턴스를 생성할 수 있음.
		- 독립된 메모리 공간에 저장된 자신만의 멤버 변수를 가지지만, 멤버 함수는 모든 인스턴스가 공유함.
	
	클래스 선언
		class 클래스이름{
			접근제어지시자1:
				멤버변수1의타입 멤버변수1의이름;
				멤버변수2의타입 멤버변수2의이름;
				...
				멤버함수1의 원형
				멤버함수2의 원형
				...
		};

	멤버 함수의 정의
		반환타입 클래스이름::멤버함수이름(매개변수목록) { 함수의 몸체; }
	- 멤버 함수가 클래스의 선언 안에서 정의되면, 이 함수는 인라인 함수로 처리되어 위와 같이 범위 지정 연산자를 사용하여 소속 클래스를 명시할 필요가 없게 됨
	- 클래스 선언 밖에서 정의된 멤버 함수도 inline 키워드를 사용하여 인라인 함수로 처리할 수 있음

	멤버 함수의 호출
		객체이름.멤버함수이름();
		객체이름.멤버함수이름(전달할인수목록);

	정보 은닉(data hidding) : 구조체의 모든 멤버는 외부에서 언제나 접근할 수 있으나, 클래스에서는 객체 지향 프로그래밍의 규칙 중 정보 은닉을 위해 '사용자가 굳이 알 필요가 없는 정보는 사용자로부터 숨겨야 한다.'
	접근 제어(access control) : 접근 제어 지시자를 사용해 클래스 외부에서의 직접적인 접근을 허용하지 않은 멤버를 설정할 수 있도록 하여, 정보 은닉을 구체화하는 것
		- public : 클래스 멤버는 외부로 공개. 해당 객체를 사용하는 프로그램 어디에서나 직접 접근 가능.
				   public 멤버 함수는 해당 객체의 private 멤버와 프로그램 사이의 인터페이스 역할을 하게 됨.(public 멤버 함수를 통해 해당 객체의 private 멤버에 접근 가능)
		- private : 클래스 멤버는 외부에 공개되지 않으며, 외부에서 직접 접근할 수도 없음. 클래스의 기본 접근 제어 권한이 private이므로, 클래스 선언 시 private 접근 제어 지시자는 생략할 수 있다.
					private 멤버는 public 인터페이스를 직접 구성하지 않는 클래스의 세부적인 도작을 구현하는 데 사용됨
		- protected : 파생 클래스에 대해서는 public 멤버처럼 취급되고, 외부에서는 private 멤버처럼 취급됨.

	this 포인터
		멤버 함수의 공유 때문에 C++에서는 모든 멤버 함수가 자신만의; this 포인터를 가지고 있다.
		해당 멤버 함수를 호출한 객체를 가리키게 되며, 호출된 멤버 함수의 숨은 인수로 전달됨 -> 호출된 멤버 함수는 자신을 호출한 객체가 무엇인지 정확히 파악할 수 있다.(return *this;)
		- 클래스, 구조체 또는 열거체 타입의 비정적 멤버 함수에서만 사용할 수 있다
		- Static 멤버 함수는 this 포인터를 가지지 않는다
		- 언제나 포인터 상수이며, 따라서 값을 재할당할 수 없다
*/
/* 생성자(Constructor)
	멤버 변수의 초기화 : 클래스를 가지고 객체를 생성하면 해당 객체는 메모리에 즉시 생성되나, 모든 멤버 변수를 초기화하기 전에는 사용할 수 없다.
						 private 멤버에 접근할 수 있는 초기화만을 위한 public 함수가 필요 -> 초기화 함수는 객체가 생성된 후부터 사용되기 전까지 반드시 멤버의 초기화를 위해 호출되어야 함.

	Constructor : 객체의 생성과 동시에 멤버 변수를 초기화해주는 멤버 함수. 클래스 생성자의 이름 == 해당 클래스의 이름
				  - 생성자는 초기화를 위한 데이터를 인수로 전달받을 수 있음
				  - 생성자는 반환값이 없지만, void형으로 선언하지 않음
				  - 객체를 초기화하는 방법이 여러 개 존재할 경우에는 오버로딩 규칙에 따라 여러 개의 생성자를 가질 수 있음
				  - 클래스 생성자의 원형은 클래스 선언의 public 영역에 포함되어야 함.
				  - 클래스에서 객체를 생성할 때마다 해당 클래스의 생성자는 컴파일러에 의해 자동으로 호출됨.(사용자가 직접 명시적으로 호출할 수도 있음)
	Default Constructor : 객체가 생성될 때 사용자가 초깃값을 명시하지 않으면, 컴파일러가 자동으로 제공하는 생성자.
						  - 사용자로부터 인수를 전달받지 않으므로 매개변수를 가지지 않음
						  - 매개변수를 가지지 않으므로 대부분의 디폴트 생성자가 0이나 NULL, 빈 문자열 등으로 초기화를 진행함.
						  - 함수 오버로딩 또는 디폴트 인수를 이용해 정의함 -> 클래스는 단 하나의 디폴트 생성자만을 가질 수 있으므로, 둘 중 한 가지 방법으로만 디폴트 생성자를 정의해야 함.

						  디폴트 생성자를 가지는 객체의 선언
							- Book web_book; // 디폴트 생성자의 암시적 호출
							- Book web_book = Book(); // 디폴트 생성자의 명시적 호출
							- Book *ptr_book = new Book(); // 디폴트 생성자의 암시적 호출

	복사 생성자
		- 얕은 복사(Shallow Copy) : 대입 연산자(=)를 사용.
										int x = 10; int y = x;
										Book bookA("OhMyGirl");
										Book bookB = bookA;
									얕은 복사는 값을 복사하는 것이 아니라, 값을 가리키는 포인터를 복사하는 것.
									변수의 생성에서 대입 연산자를 이용한 값의 복사는 문제가 되지 않지만, 객체에서는 문제가 발생할 수도 있음.(객체의 멤버가 heap 영역을 참조할 경우 문제가 발생)
		- 깊은 복사(Deep Copy) : 값을 복사.
								 복사 생성자(Copy Constructor) - 자신과 같은 클래스 타입의 다른 객체에 대한 참조(reference)를 인수로 전달받아, 그 참조를 가지고 자신을 초기화하는 방법
								 새롭게 생성되는 객체가 원본 객체와 같으면서도 완전한 독립성을 가지게 해줌.
								 복사 생성자는 다음과 같은 상황에서 주로 사용됨
									 - 객체가 함수에 인수로 전달될 때
									 - 함수가 객체를 반환값으로 반환할 때
									 - 새로운 객체를 같은 클래스 타입의 기존 객체와 똑같이 초기화할 때
									Book(const Book&); // 복사 생성자의 원형

									Book::Book(const Book& origin) // 복사 생성자의 선언
									{
										title_ = origin.title_;
										total_page_ = origin.total_page_;
										current_page_ = origin.current_page_;
										percent_ = origin.percent_;
									}
									int main(void)
									{
										Book web_book("HTML과 CSS", 350);
										Book html_book(web_book);
										...
									}
									-> Book html_book = Book(web_book); // Book html_book(web_book); 구문은 컴파일러에 의해 다음과 같이 복사 생성자를 사용한 것으로 해석됨.
							 
	소멸자(Destructor) : 객체의 수명이 끝나면 컴파일러에 의해 자동으로 호출되어 사용이 끝난 객체를 정리함.
						 ~Book() // 소멸자 원형. 클래스 선언의 public 영역에 포함되어야 함.
						 - 인수를 가지지 않음
						 - 반환값이 없지만 void형으로 선언하지 않음
*/