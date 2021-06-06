class MyMatrix:
    def getNewMatrix(self, N):
        if type(N) != int or N <= 1 or N%2 == 0:
            return -1
        lst = [[0 for col in range(N)] for row in range(N)]
        
        cnt = 0
        while(cnt <= N-cnt):
            for i in range(cnt, N-cnt):
                lst[cnt][i] = pow(N, cnt+1)
                lst[N-cnt-1][i] = pow(N, cnt+1)
                lst[i][cnt] = pow(N, cnt+1)
                lst[i][N-cnt-1] = pow(N, cnt+1)
            cnt += 1
        return lst
     
mm = MyMatrix()

lst = mm.getNewMatrix(3)
print(lst)
lst = mm.getNewMatrix(5)
print(lst)
lst = mm.getNewMatrix(7)
print(lst)