class MyMatrix:
    saveFileCount = 0 # 클래스 변수, 여러 클래스를 선언하더라도 'MATRIX.TXT' 파일에 저장한 matrix의 갯수를 counting할 수 있음
    def __init__(self, N=None):
        if N:
            if type(N) != int or N <= 1 or N%2 == 0: # 실수, 0, 1, 짝수인 경우 -1
                self.lst = []
            else:
                self.lst = [[0 for col in range(N)] for row in range(N)] # list 초기화

                # Algorithm
                cnt = 0
                while(cnt <= N-cnt):
                    for i in range(cnt, N-cnt):
                        self.lst[cnt][i] = pow(N, cnt+1)
                        self.lst[N-cnt-1][i] = pow(N, cnt+1)
                        self.lst[i][cnt] = pow(N, cnt+1)
                        self.lst[i][N-cnt-1] = pow(N, cnt+1)
                    cnt += 1
        else:
            self.lst = []

    def __eq__(self, other):
        isEqual = True
        if len(self.lst) == len(self.lst):
            for i in range(len(self.lst)):
                for j in range(len(self.lst)):
                    if self.lst[i][j] != other.lst[i][j]:
                        isEqual = False
                        break
                if(isEqual == False):
                    break
        else:
            isEqual = False
        return isEqual

    def getNewMatrix(self, N):
        if type(N) != int or N <= 1 or N%2 == 0: # 실수, 0, 1, 짝수인 경우 -1
            return -1

        self.lst = [[0 for col in range(N)] for row in range(N)] # list 초기화

        # Algorithm
        cnt = 0
        while(cnt <= N-cnt):
            for i in range(cnt, N-cnt):
                self.lst[cnt][i] = pow(N, cnt+1)
                self.lst[N-cnt-1][i] = pow(N, cnt+1)
                self.lst[i][cnt] = pow(N, cnt+1)
                self.lst[i][N-cnt-1] = pow(N, cnt+1)
            cnt += 1

        # list return
        return self.lst

    def saveFileMatrix(self, M):
        f = open('MATRIX.TXT', 'a')
        if self.saveFileCount > 0: # 이어쓰는 경우 줄 바꾸기 실행
            f.write('\n')

        f.write("#LENGTH:"+str(M[0][0])+"#\n")
        
        # list to str
        text = "["
        for i in range(len(M)):
            text += "["
            for j in range(len(M)):
                text += str(M[i][j])
                if(j != len(M)-1):
                    text += ","
            text += "]"
            if(i != len(M)-1):
                    text += ","
        text += "]"
        f.write(text)

        # counting save number
        self.saveFileCount += 1
        f.close()

        # return value
        return self.saveFileCount

    def readFileMatrix(self, N):
        try:
            with open('MATRIX.TXT', "r") as f:
                findN = False
                for item in f: # line을 받아옴
                    if(item[0] == '#'): # 해당 열에 length가 적혀있는가?
                        temp = str(N) # 해당 열에서 N 찾기위한 임시 변수
                        if(item.find(temp) != -1): # 해당 열에 N이 있는가?
                            findN = True
                    else: # Matrix가 있는 line
                        if(not findN): # 이 Matrix는 N x N Matrix가 아닙니다.
                            continue
                        else: # 이 Matrix는 N x N Matrix입니다.
                            returnList = [[0 for col in range(N)] for row in range(N)] # 반환용 list 초기화
                            temp = item.replace('[', '') # 해당 열을 임시 변수에 저장 후, [를 없앰
                            temp = temp.replace(']', '') # 그 임시 변수에서 ]를 없앰 -> ex) 3,3,3,3,9,3,3,3,3 형태의 str type 변수가 됨.
                            tempList = temp.split(',') # tempList를 만들어줌(일차원리스트) -> ex) [3,3,3,3,9,3,3,3,3]
                            cnt = 0 # tempList 접근용 index 변수
                            for i in range(N):
                                for j in range(N):
                                    returnList[i][j] = int(tempList[cnt]) # returnList(다차원)에 tempList(일차원)값 저장
                                    cnt += 1
                            return returnList # 리스트 변환
                return -1 # 파일에 없으면 int형 -1 반환
        except:
            print("Cannot load file.")

    def readFileMaxValue(self):
        try:
            with open('MATRIX.TXT', "r") as f:
                returnTuple = () # return할 tuple 선언
                tempN = 0
                tempV = 0
                maxN = 0
                maxV = 0
                for item in f: # line을 받아옴
                    if(item[0] == '#'): # 해당 열에 length가 적혀있는가?
                        temp = item[8:] # int형을 가져오기 위한 임시변수
                        temp = temp.replace('#','')
                        tempN = int(temp)
                    else: # tempN가 있는 source 추출
                        temp = item.replace('[', '') # 해당 열을 임시 변수에 저장 후, [를 없앰
                        temp = temp.replace(']', '') # 그 임시 변수에서 ]를 없앰 -> ex) 3,3,3,3,9,3,3,3,3 형태의 str type 변수가 됨.
                        tempList = list(map(int, temp.split(','))) # tempList를 만들어줌(일차원리스트) -> ex) [3,3,3,3,9,3,3,3,3]
                        tempV = max(tempList)
                        if tempV > maxV:
                            maxN = tempN
                            maxV = tempV
                            
                returnTuple = (maxN, maxV)
                return returnTuple # 튜플 변환
        except:
            print("Cannot load file.")

    def applyGivenFunction(self, fn):
        for i in range(fn):
            for j in range(fn):
                self.lst[i][j] = 1
        return self.lst
    def fn(self, n):
        return n

    def __add__(self, other):
        if len(self.lst) != len(other.lst): # N1 != N2
            return -1
        else:
            returnList = [[0 for col in range(len(self.lst))] for row in range(len(self.lst))] # 반환용 list 초기화
            for i in range(len(self.lst)):
                for j in range(len(self.lst)):
                    returnList[i][j] = self.lst[i][j] + self.lst[i][j]
            return returnList

class MyDerivedMatrix(MyMatrix):
    def getMemberMatrix(self):
        return self.lst

m1 = MyDerivedMatrix(3)
m2 = MyDerivedMatrix(5)
m3 = MyDerivedMatrix(7)

print(m1.getMemberMatrix())
print(m2.getMemberMatrix())
print(m3.getMemberMatrix())