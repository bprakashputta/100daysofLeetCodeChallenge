def execute():
    inputstring = input()
    ch = inputstring[0]
    count = 0
    for i in range(2, len(inputstring)):
        if inputstring[i] == ch:
            count = count + 1

    print(count)

if __name__=="__main__":
    execute()