# [START]
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
        if len(self.lst) == len(other.lst):
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
        text += "]\n"
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
        for i in range(len(self.lst)):
            for j in range(len(self.lst)):
                self.lst[i][j] = fn(self.lst[i][j])
        return self.lst

    def __add__(self, other):
        if len(self.lst) != len(other.lst): # N1 != N2
            return -1
        else:
            returnList = [[0 for col in range(len(self.lst))] for row in range(len(self.lst))] # 반환용 list 초기화
            for i in range(len(self.lst)):
                for j in range(len(self.lst)):
                    returnList[i][j] = self.lst[i][j] + other.lst[i][j]
            return returnList

class MyDerivedMatrix(MyMatrix):
    def getMemberMatrix(self):
        return self.lst
# [END]

print("\n\n\n\n\n:--------->> SCORING STARTS   <<---------:")

# SCORE VARIABLES
SCORE_TOTAL = 0
SCORE_STATUS = []

import os
import shutil

# PROBLEM #1
try:
    FLAG = True
    myMaxtrixObj = MyMatrix()

    if myMaxtrixObj.getNewMatrix(0) != -1:
        FLAG = False
    if myMaxtrixObj.getNewMatrix(-1) != -1:
        FLAG = False
    if myMaxtrixObj.getNewMatrix(4) != -1:
        FLAG = False
    ANSWER_3 = [[3, 3, 3], [3, 9, 3], [3, 3, 3]]
    if myMaxtrixObj.getNewMatrix(3) != ANSWER_3:
        FLAG = False
    ANSWER_5 = [[5, 5, 5, 5, 5], [5, 25, 25, 25, 5], [5, 25, 125, 25, 5], [5, 25, 25, 25, 5], [5, 5, 5, 5, 5]]
    if myMaxtrixObj.getNewMatrix(5) != ANSWER_5:
        FLAG = False
    ANSWER_7 = [[7, 7, 7, 7, 7, 7, 7], [7, 49, 49, 49, 49, 49, 7], [7, 49, 343, 343, 343, 49, 7], [7, 49, 343, 2401, 343, 49, 7], [7, 49, 343, 343, 343, 49, 7], [7, 49, 49, 49, 49, 49, 7], [7, 7, 7, 7, 7, 7, 7]]
    if myMaxtrixObj.getNewMatrix(7) != ANSWER_7:
        FLAG = False

    if FLAG == True:
        SCORE_TOTAL += 5
        SCORE_STATUS.append(5)
        print("[PROBLEM-01] CORRECT (+5)")
    else:
        SCORE_STATUS.append(0)
        print("[PROBLEM-01] IN-CORRECT")
except:
    SCORE_STATUS.append(0)
    print("[PROBLEM-01] FAILED")

# PROBLEM #2
try:
    FLAG = True
    myMaxtrixObj = MyMatrix()

    file = './MATRIX.TXT'
    if os.path.isfile(file):
        os.remove(file)

    ANSWER_3 = [[3, 3, 3], [3, 9, 3], [3, 3, 3]]
    if myMaxtrixObj.saveFileMatrix(ANSWER_3) != 1:
        FLAG = False

    ANSWER_5 = [[5, 5, 5, 5, 5], [5, 25, 25, 25, 5], [5, 25, 125, 25, 5], [5, 25, 25, 25, 5], [5, 5, 5, 5, 5]]
    if myMaxtrixObj.saveFileMatrix(ANSWER_5) != 2:
        FLAG = False

    ANSWER_7 = [[7, 7, 7, 7, 7, 7, 7], [7, 49, 49, 49, 49, 49, 7], [7, 49, 343, 343, 343, 49, 7], [7, 49, 343, 2401, 343, 49, 7], [7, 49, 343, 343, 343, 49, 7], [7, 49, 49, 49, 49, 49, 7], [7, 7, 7, 7, 7, 7, 7]]
    if myMaxtrixObj.saveFileMatrix(ANSWER_7) != 3:
        FLAG = False

    myFile = open('MATRIX.TXT', 'r')
    contents_student = myFile.read()
    myFile.close()

    myFile = open('MATRIX_ANSWER.TXT', 'r')
    contents_answer = myFile.read()
    myFile.close()

    if contents_student != contents_answer :
        FLAG = False

    if FLAG == True:
        SCORE_TOTAL += 5
        SCORE_STATUS.append(5)
        print("[PROBLEM-02] CORRECT (+5)")
    else:
        SCORE_STATUS.append(0)
        print("[PROBLEM-02] IN-CORRECT")
except:
    SCORE_STATUS.append(0)
    print("[PROBLEM-02] FAILED")

# PROBLEM #3
try:
    FLAG = True
    myMaxtrixObj = MyMatrix()

    file = './MATRIX.TXT'
    if os.path.isfile(file):
        os.remove(file)

    shutil.copy('MATRIX_ANSWER.TXT', 'MATRIX.TXT')

    ANSWER_3 = [[3, 3, 3], [3, 9, 3], [3, 3, 3]]
    if myMaxtrixObj.readFileMatrix(3) != ANSWER_3:
        FLAG = False

    ANSWER_5 = [[5, 5, 5, 5, 5], [5, 25, 25, 25, 5], [5, 25, 125, 25, 5], [5, 25, 25, 25, 5], [5, 5, 5, 5, 5]]
    if myMaxtrixObj.readFileMatrix(5) != ANSWER_5:
        FLAG = False

    ANSWER_7 = [[7, 7, 7, 7, 7, 7, 7], [7, 49, 49, 49, 49, 49, 7], [7, 49, 343, 343, 343, 49, 7], [7, 49, 343, 2401, 343, 49, 7], [7, 49, 343, 343, 343, 49, 7], [7, 49, 49, 49, 49, 49, 7], [7, 7, 7, 7, 7, 7, 7]]
    if myMaxtrixObj.readFileMatrix(7) != ANSWER_7:
        FLAG = False

    if myMaxtrixObj.readFileMatrix(9) != -1:
        FLAG = False

    if FLAG == True:
        SCORE_TOTAL += 5
        SCORE_STATUS.append(5)
        print("[PROBLEM-03] CORRECT (+5)")
    else:
        SCORE_STATUS.append(0)
        print("[PROBLEM-03] IN-CORRECT")
except:
    SCORE_STATUS.append(0)
    print("[PROBLEM-03] FAILED")

# PROBLEM #4
try:
    FLAG = True
    myMaxtrixObj = MyMatrix()

    file = './MATRIX.TXT'
    if os.path.isfile(file):
        os.remove(file)

    shutil.copy('MATRIX_ANSWER.TXT', 'MATRIX.TXT')

    if myMaxtrixObj.readFileMaxValue() != (7, 2401):
        FLAG = False

    if FLAG == True:
        SCORE_TOTAL += 5
        SCORE_STATUS.append(5)
        print("[PROBLEM-04] CORRECT (+5)")
    else:
        SCORE_STATUS.append(0)
        print("[PROBLEM-04] IN-CORRECT")
except:
    SCORE_STATUS.append(0)
    print("[PROBLEM-04] FAILED")

# PROBLEM #5
try:
    FLAG = True
    myMaxtrixObj1 = MyMatrix(3)
    myMaxtrixObj2 = MyMatrix(3)
    myMaxtrixObj3 = MyMatrix(5)

    if (myMaxtrixObj1 == myMaxtrixObj2) != True:
        FLAG = False

    if (myMaxtrixObj1 != myMaxtrixObj2) != False:
        FLAG = False

    if (myMaxtrixObj1 == myMaxtrixObj3) != False:
        FLAG = False

    if (myMaxtrixObj1 != myMaxtrixObj3) != True:
        FLAG = False

    if FLAG == True:
        SCORE_TOTAL += 5
        SCORE_STATUS.append(5)
        print("[PROBLEM-05] CORRECT (+5)")
    else:
        SCORE_STATUS.append(0)
        print("[PROBLEM-05] IN-CORRECT")
except:
    SCORE_STATUS.append(0)
    print("[PROBLEM-05] FAILED")

# PROBLEM #6
try:
    FLAG = True
    myMaxtrixObj = MyMatrix(3)

    def myFn(num):
        return num * -10

    myMaxtrixObjResult = myMaxtrixObj.applyGivenFunction(myFn)

    ANSWER_FN = [[-30, -30, -30], [-30, -90, -30], [-30, -30, -30]]

    if (myMaxtrixObjResult == ANSWER_FN) != True:
        FLAG = False

    if FLAG == True:
        SCORE_TOTAL += 5
        SCORE_STATUS.append(5)
        print("[PROBLEM-06] CORRECT (+5)")
    else:
        SCORE_STATUS.append(0)
        print("[PROBLEM-06] IN-CORRECT")
except:
    SCORE_STATUS.append(0)
    print("[PROBLEM-06] FAILED")

# PROBLEM #7
try:
    FLAG = True
    myMaxtrixObjX = MyMatrix(3)
    myMaxtrixObjY = MyMatrix(3)
    myMaxtrixObjZ = MyMatrix(5)

    def myFn(num):
        return num * -10

    myMaxtrixObjY.applyGivenFunction(myFn)

    myNewMaxrix = myMaxtrixObjX + myMaxtrixObjY
    ANSWER_NEW = [[-27, -27, -27], [-27, -81, -27], [-27, -27, -27]]

    if myNewMaxrix != ANSWER_NEW:
        FLAG = False

    myNewMaxrix = myMaxtrixObjX + myMaxtrixObjZ
    
    if myNewMaxrix != -1:
        FLAG = False

    if FLAG == True:
        SCORE_TOTAL += 5
        SCORE_STATUS.append(5)
        print("[PROBLEM-07] CORRECT (+5)")
    else:
        SCORE_STATUS.append(0)
        print("[PROBLEM-07] IN-CORRECT")
except:
    SCORE_STATUS.append(0)
    print("[PROBLEM-07] FAILED")

# PROBLEM #8
try:
    FLAG = True

    myMaxtrixObjX = MyDerivedMatrix(3)
    myMaxtrixObjY = MyDerivedMatrix(3)
    myMaxtrixObjZ = MyDerivedMatrix(5)

    def myFn(num):
        return num * -10

    myMaxtrixObjY.applyGivenFunction(myFn)

    myNewMaxrix = myMaxtrixObjX + myMaxtrixObjY
    ANSWER_NEW = [[-27, -27, -27], [-27, -81, -27], [-27, -27, -27]]

    if myNewMaxrix != ANSWER_NEW:
        FLAG = False

    myNewMaxrix = myMaxtrixObjX + myMaxtrixObjZ
    
    if myNewMaxrix != -1:
        FLAG = False

    myDerivedMaxtrixObj = MyDerivedMatrix(7)

    if myDerivedMaxtrixObj.getNewMatrix(0) != -1:
        FLAG = False
    if myDerivedMaxtrixObj.getNewMatrix(-1) != -1:
        FLAG = False
    if myDerivedMaxtrixObj.getNewMatrix(4) != -1:
        FLAG = False
    ANSWER_3 = [[3, 3, 3], [3, 9, 3], [3, 3, 3]]
    if myDerivedMaxtrixObj.getNewMatrix(3) != ANSWER_3:
        FLAG = False
    ANSWER_5 = [[5, 5, 5, 5, 5], [5, 25, 25, 25, 5], [5, 25, 125, 25, 5], [5, 25, 25, 25, 5], [5, 5, 5, 5, 5]]
    if myDerivedMaxtrixObj.getNewMatrix(5) != ANSWER_5:
        FLAG = False
    ANSWER_7 = [[7, 7, 7, 7, 7, 7, 7], [7, 49, 49, 49, 49, 49, 7], [7, 49, 343, 343, 343, 49, 7], [7, 49, 343, 2401, 343, 49, 7], [7, 49, 343, 343, 343, 49, 7], [7, 49, 49, 49, 49, 49, 7], [7, 7, 7, 7, 7, 7, 7]]
    if myDerivedMaxtrixObj.getNewMatrix(7) != ANSWER_7:
        FLAG = False

    if myDerivedMaxtrixObj.getMemberMatrix() != ANSWER_7:
        FLAG = False

    if FLAG == True:
        SCORE_TOTAL += 5
        SCORE_STATUS.append(5)
        print("[PROBLEM-08] CORRECT (+5)")
    else:
        SCORE_STATUS.append(0)
        print("[PROBLEM-08] IN-CORRECT")
except:
    SCORE_STATUS.append(0)
    print("[PROBLEM-08] FAILED")

print(":--------->> SCORING COMPLETE <<---------:\n")

print(":=========>> TOTAL SCORE:", SCORE_TOTAL, "{FYI: PERFECT SCORE is 40}")
print(":=========>> SCORE FOR PROBLEMS:", SCORE_STATUS, '\n')

# DON"T REMOVE BELOW CODE
print("==> CLEAR!")
