def isLeap(n):
    if n % 4 == 0 :
        if n % 100 == 0 :
            if n % 400 == 0 :
                return True
            else: 
                return False
        else:
            return True
    else:
        return False  

if __name__ == '__main__':

    n = int(input())
    print(isLeap(n))