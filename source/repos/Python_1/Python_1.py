# ... iss Crew
# ... Made by Mukho
# ... 2020-06-17 Wed
# ... Python Practice

"""
Python : Interpreter Language
           Interpreter : 소스 코드를 처음부터 한 라인 씩 차례대로 해석하며 실행하는 프로그램.
                          컴파일러 언어에 비해 느림.
           높은 생산성과 빠른 개발 속도 - 파이썬 프로그램을 C/C++에서, 또는 그 반대로 실행 가능. / 다양한 라이브러리 존재

print("파"+"이"+"썬") # 파이썬
print("파""이""썬") # 파이썬
print("파","이","썬") # 파 이 썬

연산자 : +, -, *, /, //(몫), %(나머지)
text sequence types : str " ", ' ', *""" """, *''' '''. * : 여러 문자열 표시
문자열 * 연산 : 같은 문자열 반복 출력
문자열 배열, 문자열 슬라이싱
문자열 .count('x') - x의 갯수 / .find('x') - 첫 x의 위치 / .index('x') - 첫 x의 위치
	.upper() .lower() / .replace("a", "b") - a문자를 b문자로 바꿈
	.split(' ') - ' '으로 문자열을 나누어 출력

if 조건식:
    응기잇
elif 조건식2:
    응기잇2
else:
    %71it
- pass : c의 continue같은 느낌

for 변수 in 문자열/튜플/리스트:
    반복할 친구
for i in range(1,10, 1):
    1 이상 10 미만의 숫자를 1씩 증가시키면서 출력
break - 반복문 탈출 / continue - 해당 조건만 탈출

list / tuple / set / dict
len() : 길이 / extend() : 연결 / 리스트 사칙연산 가능 / .append() 추가 .remove(삭제)
.insert(위치, 값) .pop(값) - 값 출력하고 리스트에서 뺌
.sort() .reverse() sorted(리스트)
리스트 : 간단히 순서대로 늘어선 박스. 다양한 데이터 타입을 다룰 수 있음. 값 변경 가능
리스트- =(대입연산자)로 복사하면 얕은 복사(원본 리스트의 메모리 주소만 넘겨줌)
	깊은 복사하려면 리스트 슬라이싱 사용

튜플 : 값을 변경할 수 없음. 리스트와 같은 데이터 타입에 비해 그 실행속도가 빠르다.
    튜플명 = (요소1, ..., 요소n)
    튜플명 = 요소1, ..., 요소n
    tuple1 = (1, 2, 3) # (1, 2, 3)
    tuple2 = 1, 2, 3 # (1, 2, 3
    tuple3 = (1,) # (1, )
    tuple4 = (1) # 1
    여러 타입의 데이터를 하나의 튜플이나 리스트로 묶어 선언하는 것을 패킹(packing)이라 하며, 하나의 튜플이나 리스트의 요소들을 여러 개의 변수에 나누어 대입하는 것을 언패킹(unpacking)이라 한다.
        # 패킹(packing)
        tuple1 = 10, "열", True 
        # 언패킹(unpacking)
        a, b, c = tuple1

    tuple1 = 10, "열", True  
    print(10 in tuple1) # True
    print("아홉" in tuple1) # False
    print("아홉" not in tuple1) # True

세트 : 집합. 순서를 매길 수 없으며, 중복된 값 또한 허용하지 않음.
    세트명 = {요소1, ..., 요소n}

    set1 = {1, 2, 3} #{1, 2, 3}
    set2 = set("Python") #{'P', 'y', 'h', 'n', 'o', 't'}
    set3 = set("Hello") #{'l', 'e', 'o', 'H'}
    빈 세트 : set()함수를 통해서만 선언할 수 있다.
    .add(값) : 요소 추가 / .remove(값) : 요소 제거 / .update(값1, ..., 값n) : 요소들 추가

    집합 연산 : |(합집합), &(교집합), -(차집합), ^(여집합)

딕셔너리 : '사전'과 같이 별도로 정해진 키를 통해 각 요소에 접근할 수 있도록 만들어진 데이터 타입
    dict1 = {'하나': 1, '둘': 'two', '파이': 3.14} #{'하나': 1, '둘': 'two', '파이': 3.14}
    dict2 = dict({'하나': 1, '둘': 'two', '파이': 3.14}) #{'하나': 1, '둘': 'two', '파이': 3.14}
    dict3 = dict([('하나', 1), ('둘', 'two'), ('파이', 3.14)]) #{'하나': 1, '둘': 'two', '파이': 3.14}
    dict4 = dict(하나=1, 둘='two', 파이=3.14) #{'하나': 1, '둘': 'two', '파이': 3.14}

    []를 사용해 키를 전달하거나 get()을 사용해 저장된 값을 얻을 수 있다.
        dict1 = dict({'자바': 80, 'PHP': 90, 'HTML': 70})  
        print(dict1['자바']) # 80
        print(dict1.get('자바')) # 80
    []안에 키를 넣고 =를 사용하여 값을 저장하면 추가할 수 있다. ex) dict1['파이썬'] = 100 -> {'파이썬' : 100}

    dict1 = dict({'자바': 80, 'PHP': 90, 'HTML': 70})  
    dict1['파이썬'] = 100 -> {'자바': 80, 'PHP': 90, 'HTML': 70, '파이썬': 100}
    del dict1['PHP'] -> {'자바': 80, 'HTML': 70, '파이썬': 100}
    dict1['자바'] = 100 -> {'자바': 100, 'HTML': 70, '파이썬': 100}
    dict1.clear() -> {}

    keys() 함수를 사용하면 딕셔너리에 저장된 모든 요소의 키(key)들을 한 번에 얻을 수 있음
    values() 함수를 사용하면 딕셔너리에 저장된 모든 요소들의 값(value)들을 따로 얻을 수 있음
    items() 함수는 딕셔너리에 저장된 모든 요소들을 각각 키와 값의 한 쌍으로 이루어진 튜플의 형태로 반환함
        dict1 = dict({'자바': 80, 'PHP': 90, 'HTML': 70})  
        print(dict1.keys()) -> dict_keys(['자바', 'PHP', 'HTML'])
        print(dict1.values()) -> dict_values([80, 90, 70])
        print(dict1.items()) -> dict_items([('자바', 80), ('PHP', 90), ('HTML', 70)])
        print('HTML' in dict1) -> True
        print('파이썬' in dict1) -> False

Function
    def 함수명(매개변수...):
        실행할 코드
    
    def sub(a, b):
        print(a - b)
    sub(1, 2) -> -1
    sub(a=1, b=2) -> -1
    sub(b=1, a=2) -> 1

    매개변수의 기본값 설정 _ 함수 호출 시 전달받지 못한 인수에 대해서는 설정해 놓은 기본값으로 자동 초기화할 수 있다. / 단, 매개변수의 기본값 설정은 매개변수의 목록에서 항상 오른쪽부터 차례대로 명시되어야만 한다.
        def total(a, b=2):
           print(a + b)
        total(1) -> 3
        total(1, 3) -> 4

    가변 매개변수 : 함수를 호출할 때 몇 개의 인수가 전달될지 미리 알 수 없다면, 사용자가 직접 매개변수의 개수를 정할 수 있도록 선언할 수 있음.
        def 함수명(*매개변수명):
            실행할 코드
        
        - 이렇게 선언된 가변 매개변수에는 함수가 호출될 때 전달된 모든 인수가 튜플의 형태로 저장됨.
        - 가변 매개변수로 딕셔너리를 사용하려면 **를 써서 선언하면 됨.
        def add(*paras):
            print(paras) # 매개변수들 출력
    
            total = 0 # 총합 변수
            for para in paras:
                total += para
            return total
        print(add(10)) # (10,) 10
        print(add(10, 100)) # (10, 100) 110
        print(add(10, 100, 1000)) # (10, 100, 1000) 1110
        def print_map(**dicts):
            for item in dicts.items():
                print(item)    
        print_map(one=1, two=2) # ('one', 1) ('two', 2)
람다(lambda) : 간단한 함수의 선언과 호출을 하나의 식으로 간략히 표현
    lambda 매개변수 1, 매개변수2, ... : 매개변수를 이용한 표현식

    def add(a, b):
        return a + b
    ==
    (lambda a, b : a+b)(1, 2)

    함수 내부에서 전역 변수를 사용하기 위해서는 global 키워드를 사용하여 해당 전역 변수를 재선언해야 한다.
    def func():
        global global_var
"""
'''
Class : 함수뿐만 아니라 관련된 변수까지도 한꺼번에 묶어서 관리하고 재사용할 수 있게 해주는 것.
Class : Object = 붕어빵 틀 : 붕어빵
속성(attribute) : 클래스에 포함되는 변수
메소드(method) : 클래스에 포함되는 함수

    class Dog: #클래스
        name = "아리" # 속성
        age = 2
        breed = "토이 푸들"

        def bark(self): # 메소드
            print(self.name + "는 멍멍")

    dog_1 = Dog() #인스턴스 생성
    print(dog_1.breed) # 인스턴스의 속성 접근
    dog_1.bark() # 인스턴스의 메소드 호출

초기화 메소드
    class Dog:
        def __init__(self, name):
            self.name = name

        def bark(self):
            print(self.name + "는 멍멍")

    dog_1 = Dog("아리")
    dog_1.bark()

상속
    class 자식클래스명(부모클래스명)
    class Bird:
        def __init__(self):
            self.flying = True 
        def birdsong(self):
            print("새소리")    
    class Sparrow(Bird):
        def birdsong(self):
            print("짹짹")    

    my_pet = Sparrow()  
    print(my_pet.flying)
    my_pet.birdsong()
    ->True 짹짹

메소드 오버라이딩 : 부모클래스에서 선언한 메소드와 같은 이름의 메소드를 자식클래스에서 재정의하는 것.
접근제어
    public : 선언된 클래스 멤버는 외부로 공개됨. 해당 객체를 사용하는 프로그램 어디서나 직접 접근 가능. // name
    private : 선언된 클래스 멤버는 외부에 공개되지 않음. 외부에서 직접 접근할 수 없음. // __name
    protected : 선언된 클래스 멤버는 부모클래스에 대해서는 public 멤버처럼, 외부에서는 private 멤버처럼 취급. // _name
'''

"""
모듈 : 한번 정의했던 변수나 함수, 클래스 등을 다른 파이썬 프로그램에서도 불러와 사용할 수 있게 하나의 파일로 모아두는 것. (.py)
    import 모듈명 -> 전체를 불러옴 / 변수나 함수를 사용할 때 마다 매번 모듈명과 함께 .를 사용해야 함. math.pi()
    from 모듈명 import * -> 전체를 불러옴 / 변수명이나 함수명만으로 사용 가능. pi()
    from 모듈명 import 함수명 또는 클래스명 -> 해당 함수나 클래스만 불러옴.

파일 입출력 : 표준 입출력 함수인 input()과 print() 함수를 사용하여 입출력하는 것과 같이 프로그램과 파일 사이의 입출력을 하는 것.
    파일객체 = open(파일명, 파일모드문자열) // "r" 읽기 전용 모드(기본값), "w" 쓰기 전용 모드, "a" 파일의 마지막에 새로운 데이터를 추가하는 모드" // 생략 or "t" 텍스트 모드로 염, "b" 바이너리 파일로 염. // "x" 열고자 하는 파일이 이미 존재하면 파일 열기에 실패, "+" 파일을 읽을 수도 있고 쓸 수도 있도록 염.
    파일 내용 읽기 : read() - 해당 파일의 모든 내용을 읽어 들여 하나의 문자열로 반환
                    readline() - 해당 파일의 내용을 한 라인씩 읽어 들여 문자열로 반환, EOF에 도달하면 None을 반환
                    readlines() - 해당 파일의 모든 라인을 순서대로 읽어 들여 각각의 라인을 하나의 요소로 저장하는 하나의 리스트를 반환
        # read()
        fp = open('test.txt', 'r')  
        file_data = fp.read()
        print(file_data)  
        fp.close()
                1번째 라인입니다.
                2번째 라인입니다.
                3번째 라인입니다.
                마지막 라인입니다.
        
        # readline()
        fp = open('test.txt', 'r')  
        file_data = fp.readline()
        print(file_data)  
        fp.close()
            1번째 라인입니다.
        fp = open('test.txt', 'r')  
        while True:
            file_line = fp.readline()
            if not file_line:
                break
            print(file_line, end='')  
        fp.close()
                1번째 라인입니다.
                2번째 라인입니다.
                3번째 라인입니다.
                마지막 라인입니다.

        # readlines()
        fp = open('test.txt', 'r')     
        file_lines = fp.readlines()
        print(file_lines)  
        fp.close()
                ['1번째 라인입니다.\n', '2번째 라인입니다.\n', '3번째 라인입니다.\n', '마지막 라인입니다.']

        # 내용 추가
        fp = open('test.txt', 'a')  
        fp.write("\n추가된 라인입니다.")
        print(file_data)  
        fp.close()
                1번째 라인입니다.
                2번째 라인입니다.
                3번째 라인입니다.
                마지막 라인입니다.
                추가된 라인입니다.

    자동으로 파일 닫기 : with open(파일명, 파일모드문자열) as 파일객체:
                            명령문
        fp = open('test.txt', 'r')  
        file_data = fp.read()
        print(file_data)  
        fp.close()
        ->
        with open('test.txt', 'r') as fp:
            file_data = fp.read()
            print(file_data)

예외처리(Exception Handling) : 문법 오류(Syntax Errors), 예외(Exceptions)
try, except문
    try:
        예외가 발생할 가능성이 있는 코드
    except [ 처리할 예외 명 [ as 에러 메시지 변수 ]]:
        try절에서 발생한 예외를 처리할 코드
    (except [ 처리할 예외 명2 [ as 에러 메시지 변수 ]]:
        try절에서 발생한 예외를 처리할 코드2)
    (else: # 생략 가능
        try절에서 예외가 발생하지 않았을 경우에만 실행될 코드)
    (finally: # 생략 가능
        try절이 실행되고 나면 언제나 마지막에 실행될 코드)
    
    -> 예외가 발생 안했을 경우 : try [-> finally]

        try:
            3 / 0
        except IndexError as e:
            print("인덱스가 안맞아요!", e)
        except ZeroDivisionError as e:
            print("0으로 나누면 안돼요!", e) 
        print("프로그램이 정상적으로 종료됩니다!")
            -> 0으로 나누면 안돼요! division by zero
               프로그램이 정상적으로 종료됩니다!

    예외 발생시키기 : raise 키워드
"""