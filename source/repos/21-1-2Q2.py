class MyMatrix:
    saveFileCount = 0 # 클래스 변수, 여러 클래스를 선언하더라도 'MATRIX.TXT' 파일에 저장한 matrix의 갯수를 counting할 수 있음
    def __init__(self):
        self.lst = []

    def getNewMatrix(self, N):
        if type(N) != int or N <= 1 or N%2 == 0: # 실수, 0, 1, 짝수인 경우 -1
            return -1

        self.lst = [[0 for col in range(N)] for row in range(N)]
        cnt = 0

        while(cnt <= N-cnt):
            for i in range(cnt, N-cnt):
                self.lst[cnt][i] = pow(N, cnt+1)
                self.lst[N-cnt-1][i] = pow(N, cnt+1)
                self.lst[i][cnt] = pow(N, cnt+1)
                self.lst[i][N-cnt-1] = pow(N, cnt+1)
            cnt += 1
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
     
mm = MyMatrix()

lst = mm.getNewMatrix(3)
cnt = mm.saveFileMatrix(lst)
print(cnt)

lst = mm.getNewMatrix(5)
cnt = mm.saveFileMatrix(lst)
print(cnt)

lst = mm.getNewMatrix(3)
cnt = mm.saveFileMatrix(lst)
print(cnt)