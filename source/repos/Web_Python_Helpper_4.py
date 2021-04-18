def getResult(status):
    if '_' in status:
        return "You lose"
    else:
        return "You win"
def updateStatus(word, x, status):
    new_status = ''
    for i in range(len(word)):
        if word[i] == x:
            new_status += x
        else:
            new_status += status[i]
    return new_status
def startGame(word):
    b = ''
    count = len(word)
    status = '_' * count
    print(status)
    for i in range(count, 0, -1):
        print(i, end='')
        temp = input(" chances. Enter a letter : ")
        status = updateStatus(word, temp, status)
        print(status)
        b = getResult(status)
        if b == "You win":
            break
    print(b)
w = input()
startGame(w)