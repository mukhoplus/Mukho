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

/* C��� ��Ÿ���� ���ڿ�
	C++ cin : �̸��� ���Ⱑ ���� ���ø��� �Է��� �� ���� ex) cin >> "������ ���ؽ�" -> ������ / ���ؽ�
			: ������ SIZE �̻��� �̸��̳� ���ø��� �Է��ϸ� ���α׷��� ���� ����ȴ�
			: ���⸦ ������ �� ����, ĳ���� ���� ���� ���� ��� ���ڿ��� ������ �ν���.

				const int SIZE = 20;
				char name[SIZE];
				char address[SIZE];

				cout << "�̸� : ";
				cin.get(name, SIZE).get(); -> ���⸦ ������ ���ڿ��� ��Ȯ�� �Է¹��� �� ������, 20����Ʈ �̻��� �̸��� �Է��ϸ� ���ø��� �Է��� �� ����.
				cin.get(assress, SIZE).ignore(SIZE, '\n'); -> 20����Ʈ �̻��� ���ڿ��� �Է¹޾Ƶ� 20����Ʈ������ �Է¹���.
				-> ���ŷ���? string ����.

				string name, address;
				getline(cin, name);
				getline(cin, address);
				-> ���ڿ��� ���� ������ ���ڿ��� ���̿� ������� ��� ���ڿ��� ��Ȯ�� �Է¹��� �� ����.

	C��� ���ڿ� ó�� �Լ� : cstring.h
			
	string Ŭ���� : string.h
					string ��ü �Է¹ޱ� : getline(cin, name);

					string ��ü�� ���ڿ��� �ܼ��� ������ ������. -> ����ڰ� ���̸� �������� �ʾƵ� �Ǹ�, ������ C++ Program�� �ڵ����� ó���� �ش�.
					string name = "chaewon";
					cout << name.length() << endl; // 7
					cout << name[0] << endl; // c

					���� : string name = "chaewon";
						   string temp;
						   temp = name; // temp -> chaewon

					�߰�, ���� : += or append()
	string �޼ҵ�
					length(), size() : ���ڿ��� ���� ��ȯ. length�� ���ڿ��� ����, size�� string ��ü�� �޸𸮿��� ���� ����ϰ� �ִ� ũ��
					append() : �ϳ��� ���ڿ��� ���� �ٸ� ���ڿ��� �߰��ϴ� �޼ҵ�
								���ڿ�.append(�߰��ҹ��ڿ�);
								���ڿ�.append(�߰��ҹ��ڿ�, ������ġ, ��������ġ); // �߰��� ���ڿ��� ������ġ~��������ġ������ �߰���.
								���ڿ�.append(����, �߰��ҹ���);
					find() : Ư�� ���ڿ��� ã��, �� ���� ��ġ�� ��ȯ�ϴ� �޼ҵ�
								���ڿ�.find(ã�����ڿ�);
								���ڿ�.find(ã������);
								���ڿ�.find(ã�����ڿ�, ������ġ);
							 ���� �ش� ���ڿ����� ã�� ���ڿ��� ã�� ���ϸ�, string::size_type�� string::npos��� ����� ��ȯ�Ѵ�.(-1)
					compare() : �� ���ڿ����� ���� ��
									str1.compare(str2) == 0 // str1�� str2�� ����
													   < 0 // str1�� str2���� ���� ���������� �տ� ����
													   > 0 // str1�� str2���� ���� ���������� �ڿ� ����
					replace() : Ư�� ���ڿ��� ã��, �� ���ڿ��� �ٸ� ���ڿ��� ��ü�ϴ� �޼ҵ�
									���ڿ�.replace(��ü�ҹ��ڿ��ǽ�����ġ, ��ü�ҹ��ڿ��Ǳ���, ���ο�ڿ�);
									// ���޵� ���� ��ġ���� ���ڿ��� ���̸�ŭ ������ ��, ���ο� ���ڿ��� ������.
										string str1 = "C++ is very nice!";
										string str2 = "nice";
										string str3 = "awesome";
										
										string::size_type index = str1.find(str2); // str1���� str2�� ã��, �� ������ġ�� ����
										if (index != string::npos) // ã������
											str1.replace(index, str2.length(), str3); // str1���� ������ġ���� str2 ���̸�ŭ ���ְ� str3�� �߰���.
										cout << str1; // "C++ is very awesome!"
					capacity(), max_size() : capacity�� �ش� ���ڿ��� �����(reallocation)���� �ʰ� ������ �� �ִ� �ִ� ���ڿ��� ���̸� ��ȯ
											 max_size�� �ش� ���ڿ��� �ִ��� ���Թ����� ���� �� �ִ� �ִ� ���ڿ��� ���̸� ��ȯ
*/
/* ����ü
	C++������ ����ü�� ������ �� ��� ������ �� �ٸ� ����ü�� ������ �� �ִ�.
*/
/* Function Pointer
	�Լ��� ���� �ּҸ� ����Ű�� ������ ���
	������ Ÿ���� �Լ��� ��ȯ���� �Ű������� ���� ������
		�Լ� ���� : void Func(int, int);
		�Լ� ������ : void (*ptr_func)(int, int);

			#include <iostream>
			using namespace std;

			double Add(double, double);
			double Sub(double, double);
			double Mul(double, double);
			double Div(double, double);
			double Calculator(double, double, double (*func)(double, double));

			int main(void)
			{
				double (*calc)(double, double) = NULL; // �Լ� ������ ����
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
					cout << "��Ģ����(+, -, *, /)���� �����մϴ�.";
					break;
				}
				result = Calculator(num1, num2, calc);
				cout << "��Ģ ������ ����� " << result << "�Դϴ�.";
	
				return 0;
			}

			double Add(double num1, double num2) { return num1 + num2; }
			double Sub(double num1, double num2) { return num1 - num2; }
			double Mul(double num1, double num2) { return num1 * num2; }
			double Div(double num1, double num2) { return num1 / num2; }
			double Calculator(double num1, double num2, double (*func)(double, double)) { return func(num1, num2); }

		�Լ� �������� ǥ��� : double (*calc)(double, double) = NULL; // ������

							   typedef double (*calcFunc)(double, double) // �Լ� �����Ϳ� calcFunc�̶�� ���ο� �̸��� ����
							   calcFunc ptr_func = calc;

							   auto ptr_func = calc;
*/
/* ������(reference)
	Ư�� ������ ���� �̸� ��� ����� �� ����
		int �����̸�; // ������ ����
		int& �������̸� = �����̸�; // ������ ����. int& = int���� ���� ����. ��� ������ ���� �޸� ��ġ�� �����ϰ� ��
	�����ڴ� �ַ� �Լ��� �μ��μ� ������ �� ����.
		- �Լ��� �����ڸ� �μ��� ���޹�����, �����ڰ� �����ϰ� �ִ� ���� ������ ���� �Լ� ������ ������ �� ����.

		void Swap(int& x, int& y){ ... } -> Call by Reference
			- call by pointer�� ��� ����� ����� ����.
			- �Լ� ������ ���� ������ (*)�� ������� �ʾ� �Լ� ������ �ڵ尡 ����ϰ� ��������.
			- �ٸ�, �Լ��� ȣ���� call by value�� ���� ���¶� �ڵ� �бⰡ ���� ����.
			- ���� ������ �Լ������� call by value��, ���� ȣ���� �� �ʿ��� ���� call by pointer�� ����.
			- C++���� �����ڴ� ũ�Ⱑ ū ����ü�� Ŭ������ �ٷ� ������ ����ϴ� ���� ����.

			struct Book
			{
				string title;
				string author;
				int price;
			};
			void Display(const Book&);
			int main(void)
			{
				Book web_book = {"HTML�� CSS", "ȫ�浿", 28000};
				Display(web_book);
				return 0;
			}
			void Display(const Book& bk)
			{
				cout << "å�� ������ " << bk.title << "�̰�, ";
				cout << "���ڴ� " << bk.author << "�̸�, ";
				cout << "������ " << bk.price << "���Դϴ�.";
			}
*/
/* ����Ʈ �μ�(default argument)
	�⺻���� �̸� ���ǵǾ� �ִ� �μ�
		- �Լ��� �������� ������ �� �ִ�.
		- ���� �����ʿ����� �����Ͽ� ������θ� ������ �� �ִ�.
		- ��� �μ��鸸 ������ ����Ʈ �μ��� ������ ���� ����.
		void Display(int x, int y, char ch, int z = 4);
	�Լ��� ���޵� �μ��� ���ʺ��� ������� �Ű����� ��Ͽ� ���Ե�. �μ� ������ �ǳʶ� �� ����.
*/
/* �Լ� �����ε�(function overloading)
	���� �̸��� �Լ��� �ߺ��Ͽ� �����ϴ� ��
	���� �Լ��� �ϳ��� �̸����� ������ ��. ���� ���� �ϴ� �Լ��� �Ű������� ������ ���ݾ� �޸��Ͽ�, �ϳ��� �̸����� �ۼ��� �� �ְ� ���ִ� ��.
	-> ��ü ���� ���α׷����� Ư¡ �� ������(polymorphism)�� ����

	�Լ� �ñ״�ó - �Լ��� ������ ���õǴ� �Ű����� ����Ʈ
	�Լ��� �����ε� : ���� �ٸ� �ñ״�ó�� ���� ���� �Լ��� ���� �̸����� �����ϴ� ��
		void add(int, int);
		void add(int, double);
		void add(double, int);
		void add(double, double);
		-> ����ڰ� add() �Լ��� ȣ���ϸ�,C++ �����Ϸ��� �ڵ����� ���� �ñ״�ó�� ������ �Լ��� ������ ã�� ȣ����.
*/
/* �ζ��� �Լ�
	...�Լ��� ȣ��Ǹ� �켱 ���ÿ� �Լ��� ������ �Ű������� �Բ� ȣ���� ���� �� ���ư� ��ȯ �ּҰ��� �����ϰ� �˴ϴ�.
	�׸����� ���α׷��� ��� �Լ��� ��ġ�� �Ѿ�� �Լ� ���� ����� ���� ������ ���ÿ� �����մϴ�.
	�׶����� �Լ��� ��� �ڵ带 �����ϰ� �ǰ�, ������ ���� ������ ��ȯ���� �Ѱ� �ݴϴ�.
	�� �� ���α׷��� ����� ���ÿ� ����� ���ư� ��ȯ �ּҰ����� �̵��Ͽ�, ���ÿ� ����� �Լ� ȣ�� ������ �����մϴ�.
	�̿� ���� �Ϸ��� �Լ� ȣ�� ������ �Լ����� �Ͼ�� �˴ϴ�....
	-> C++���� �Լ��� ȣ���� �� ������ ������ ��ġ�� ������ �ణ�� �ð��� �ɸ��� ��
	   �Լ��� �����ϴ� �ð��� ���� �ɸ��ٸ�, �Լ��� ȣ���ϴµ� �ɸ��� �ð��� ���� ������ ���� ������
	   �Լ��� ���� �ð��� �ſ� ª�ٸ�, �Լ� ȣ�⿡ �ɸ��� �ð��� �δ��� �� �� ����.
	�ζ��� �Լ��� ȣ��� �� �Ϲ����� �Լ��� ȣ�� ������ ��ġ�� �ʰ�, �Լ��� ��� �ڵ带 ȣ��� �ڸ��� �ٷ� �����ϴ� ����� �Լ�.
	-> �Լ��� ȣ���ϴ� �� �ɸ��� �ð��� ����ǳ�, �Լ� ȣ�� �������� ����� ���� ������ �����ϰ� ��.
	   ���� �ڵ尡 �ſ� ���� �Լ����� �ζ��� �Լ��� �����ϴ� ���� ����.

	inline �Լ��� ���� / inline �Լ������� : �� �� �ϳ���, �� �� ǥ���ص� �������.
	������ �ζ��� �Լ��� ũ�Ⱑ �۾� �Լ��� ������ ������ �ڸ��� �Լ��� ��ü���� �Բ� �����ϴ� ��찡 ����. // �ζ��� �Լ������� ��� ȣ���� ������ ����.
*/
/* ��ȿ ������ ����
	��ȿ ����(scope) : �ϳ��� ��ȯ ���� ������ �ش� ������ ���� �� �ִ� ����
	����(linkage) : �ش� ������ ����� �� �ִ� ������ ���� ���� ����
		- �ܺ� ����(external linkage) : ���� ���Ͽ��� ��� ����
		- ���� ����(internal linkage) : �ϳ��� ���Ͽ����� ��� ����

	�ڵ� ����(automatic variable) : ���� ������ ����� ����(�Լ��� �Ű������� ����)
									����� ���� �������� ��ȿ. ������ ����Ǹ� �޸𸮿��� �����
									�޸𸮻��� ���� ������ �����, �ʱ�ȭ ���ϸ� �����갪���� �ʱ�ȭ��
									C����� ���� ������ ���� �ǹ�
	������ ������ �ʴ� ���� ���� : ���� ���ο��� static Ű���带 ����Ͽ� ���ǵ�.
								   ���� ������ ���� ������ Ư¡�� ��� ������ �� - ���� ����ó�� �� �ѹ��� �ʱ�ȭ�Ǹ�, ���α׷��� ����Ǿ�� �޸𸮻󿡼� �����. ���� ����ó�� �ش� ���� �������� ������ �� ����.
	���� ������ ������ ���� ���� : ��ȿ ������ ��ȯ ������ ������ ������ static Ű���带 ����Ͽ� ������.
								   ���� ���Ͽ����� ��� ����. �ϳ��� ���� ���� ��� ���Ͽ��� ������ �� �ְ�, ���� ����� �� ����.
	�ܺ� ������ ������ ���� ���� : ��ȿ ������ ��ȯ ������ ������ ����. ���� ���� or �ܺ� ������� ��.
								   �ܺ� ���Ͽ����� ��� ����. �ش� ������ ����ϴ� ��� ���Ͽ��� ���� extern Ű���带 ����Ͽ� �缱��Ǿ�� ��� ������.
*/
/* Ŭ����
	����ü�� ���� ȣȯ.
	��ü ���� ���α׷����� Ư¡ �� �ϳ��� �߻�ȭ(abstraction)�� ����� ���� Ÿ������ ������ ��
	��ü ���� ���α׷��� : ��ü�� ���¿� �ൿ�� ��üȭ�ϴ� ������ ���α׷���
		- �߻�ȭ(abstraction)
		- ĸ��ȭ(encapsulation)
		- ���� ����(data hiding)
		- ��Ӽ�(inheritance)
		- ������(polymorphism)
	Ŭ���� : �̿� ���� ��ü�� ����� ���� ���� Ʋ�� ���� ����
	�ν��Ͻ�(instance) : ����� �ش� Ŭ���� Ÿ���� ��ü. �޸𸮿� ���Ե� ��ü
		- �ϳ��� Ŭ�������� ���� ���� �ν��Ͻ��� ������ �� ����.
		- ������ �޸� ������ ����� �ڽŸ��� ��� ������ ��������, ��� �Լ��� ��� �ν��Ͻ��� ������.
	
	Ŭ���� ����
		class Ŭ�����̸�{
			��������������1:
				�������1��Ÿ�� �������1���̸�;
				�������2��Ÿ�� �������2���̸�;
				...
				����Լ�1�� ����
				����Լ�2�� ����
				...
		};

	��� �Լ��� ����
		��ȯŸ�� Ŭ�����̸�::����Լ��̸�(�Ű��������) { �Լ��� ��ü; }
	- ��� �Լ��� Ŭ������ ���� �ȿ��� ���ǵǸ�, �� �Լ��� �ζ��� �Լ��� ó���Ǿ� ���� ���� ���� ���� �����ڸ� ����Ͽ� �Ҽ� Ŭ������ ������ �ʿ䰡 ���� ��
	- Ŭ���� ���� �ۿ��� ���ǵ� ��� �Լ��� inline Ű���带 ����Ͽ� �ζ��� �Լ��� ó���� �� ����

	��� �Լ��� ȣ��
		��ü�̸�.����Լ��̸�();
		��ü�̸�.����Լ��̸�(�������μ����);

	���� ����(data hidding) : ����ü�� ��� ����� �ܺο��� ������ ������ �� ������, Ŭ���������� ��ü ���� ���α׷����� ��Ģ �� ���� ������ ���� '����ڰ� ���� �� �ʿ䰡 ���� ������ ����ڷκ��� ���ܾ� �Ѵ�.'
	���� ����(access control) : ���� ���� �����ڸ� ����� Ŭ���� �ܺο����� �������� ������ ������� ���� ����� ������ �� �ֵ��� �Ͽ�, ���� ������ ��üȭ�ϴ� ��
		- public : Ŭ���� ����� �ܺη� ����. �ش� ��ü�� ����ϴ� ���α׷� ��𿡼��� ���� ���� ����.
				   public ��� �Լ��� �ش� ��ü�� private ����� ���α׷� ������ �������̽� ������ �ϰ� ��.(public ��� �Լ��� ���� �ش� ��ü�� private ����� ���� ����)
		- private : Ŭ���� ����� �ܺο� �������� ������, �ܺο��� ���� ������ ���� ����. Ŭ������ �⺻ ���� ���� ������ private�̹Ƿ�, Ŭ���� ���� �� private ���� ���� �����ڴ� ������ �� �ִ�.
					private ����� public �������̽��� ���� �������� �ʴ� Ŭ������ �������� ������ �����ϴ� �� ����
		- protected : �Ļ� Ŭ������ ���ؼ��� public ���ó�� ��޵ǰ�, �ܺο����� private ���ó�� ��޵�.

	this ������
		��� �Լ��� ���� ������ C++������ ��� ��� �Լ��� �ڽŸ���; this �����͸� ������ �ִ�.
		�ش� ��� �Լ��� ȣ���� ��ü�� ����Ű�� �Ǹ�, ȣ��� ��� �Լ��� ���� �μ��� ���޵� -> ȣ��� ��� �Լ��� �ڽ��� ȣ���� ��ü�� �������� ��Ȯ�� �ľ��� �� �ִ�.(return *this;)
		- Ŭ����, ����ü �Ǵ� ����ü Ÿ���� ������ ��� �Լ������� ����� �� �ִ�
		- Static ��� �Լ��� this �����͸� ������ �ʴ´�
		- ������ ������ ����̸�, ���� ���� ���Ҵ��� �� ����
*/
/* ������(Constructor)
	��� ������ �ʱ�ȭ : Ŭ������ ������ ��ü�� �����ϸ� �ش� ��ü�� �޸𸮿� ��� �����ǳ�, ��� ��� ������ �ʱ�ȭ�ϱ� ������ ����� �� ����.
						 private ����� ������ �� �ִ� �ʱ�ȭ���� ���� public �Լ��� �ʿ� -> �ʱ�ȭ �Լ��� ��ü�� ������ �ĺ��� ���Ǳ� ������ �ݵ�� ����� �ʱ�ȭ�� ���� ȣ��Ǿ�� ��.

	Constructor : ��ü�� ������ ���ÿ� ��� ������ �ʱ�ȭ���ִ� ��� �Լ�. Ŭ���� �������� �̸� == �ش� Ŭ������ �̸�
				  - �����ڴ� �ʱ�ȭ�� ���� �����͸� �μ��� ���޹��� �� ����
				  - �����ڴ� ��ȯ���� ������, void������ �������� ����
				  - ��ü�� �ʱ�ȭ�ϴ� ����� ���� �� ������ ��쿡�� �����ε� ��Ģ�� ���� ���� ���� �����ڸ� ���� �� ����
				  - Ŭ���� �������� ������ Ŭ���� ������ public ������ ���ԵǾ�� ��.
				  - Ŭ�������� ��ü�� ������ ������ �ش� Ŭ������ �����ڴ� �����Ϸ��� ���� �ڵ����� ȣ���.(����ڰ� ���� ���������� ȣ���� ���� ����)
	Default Constructor : ��ü�� ������ �� ����ڰ� �ʱ갪�� �������� ������, �����Ϸ��� �ڵ����� �����ϴ� ������.
						  - ����ڷκ��� �μ��� ���޹��� �����Ƿ� �Ű������� ������ ����
						  - �Ű������� ������ �����Ƿ� ��κ��� ����Ʈ �����ڰ� 0�̳� NULL, �� ���ڿ� ������ �ʱ�ȭ�� ������.
						  - �Լ� �����ε� �Ǵ� ����Ʈ �μ��� �̿��� ������ -> Ŭ������ �� �ϳ��� ����Ʈ �����ڸ��� ���� �� �����Ƿ�, �� �� �� ���� ������θ� ����Ʈ �����ڸ� �����ؾ� ��.

						  ����Ʈ �����ڸ� ������ ��ü�� ����
							- Book web_book; // ����Ʈ �������� �Ͻ��� ȣ��
							- Book web_book = Book(); // ����Ʈ �������� ������ ȣ��
							- Book *ptr_book = new Book(); // ����Ʈ �������� �Ͻ��� ȣ��

	���� ������
		- ���� ����(Shallow Copy) : ���� ������(=)�� ���.
										int x = 10; int y = x;
										Book bookA("OhMyGirl");
										Book bookB = bookA;
									���� ����� ���� �����ϴ� ���� �ƴ϶�, ���� ����Ű�� �����͸� �����ϴ� ��.
									������ �������� ���� �����ڸ� �̿��� ���� ����� ������ ���� ������, ��ü������ ������ �߻��� ���� ����.(��ü�� ����� heap ������ ������ ��� ������ �߻�)
		- ���� ����(Deep Copy) : ���� ����.
								 ���� ������(Copy Constructor) - �ڽŰ� ���� Ŭ���� Ÿ���� �ٸ� ��ü�� ���� ����(reference)�� �μ��� ���޹޾�, �� ������ ������ �ڽ��� �ʱ�ȭ�ϴ� ���
								 ���Ӱ� �����Ǵ� ��ü�� ���� ��ü�� �����鼭�� ������ �������� ������ ����.
								 ���� �����ڴ� ������ ���� ��Ȳ���� �ַ� ����
									 - ��ü�� �Լ��� �μ��� ���޵� ��
									 - �Լ��� ��ü�� ��ȯ������ ��ȯ�� ��
									 - ���ο� ��ü�� ���� Ŭ���� Ÿ���� ���� ��ü�� �Ȱ��� �ʱ�ȭ�� ��
									Book(const Book&); // ���� �������� ����

									Book::Book(const Book& origin) // ���� �������� ����
									{
										title_ = origin.title_;
										total_page_ = origin.total_page_;
										current_page_ = origin.current_page_;
										percent_ = origin.percent_;
									}
									int main(void)
									{
										Book web_book("HTML�� CSS", 350);
										Book html_book(web_book);
										...
									}
									-> Book html_book = Book(web_book); // Book html_book(web_book); ������ �����Ϸ��� ���� ������ ���� ���� �����ڸ� ����� ������ �ؼ���.
							 
	�Ҹ���(Destructor) : ��ü�� ������ ������ �����Ϸ��� ���� �ڵ����� ȣ��Ǿ� ����� ���� ��ü�� ������.
						 ~Book() // �Ҹ��� ����. Ŭ���� ������ public ������ ���ԵǾ�� ��.
						 - �μ��� ������ ����
						 - ��ȯ���� ������ void������ �������� ����
*/