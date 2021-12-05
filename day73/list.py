
def execute():
    inputLst = []
    n = int(input("Enter size of list : "))
    # print(n)
    for i in range(0, n):
        x = int(input())
        inputLst.append(x)
    print("List Elements : ",inputLst)
    print("Input the limits : ")
    left = int(input())
    right = int(input())

    print("The elements in the range are : ")
    for i in range(0, n):
        if inputLst[i] >= left and inputLst[i] <=right:
            print(inputLst[i])


if __name__ == "__main__":
    execute()