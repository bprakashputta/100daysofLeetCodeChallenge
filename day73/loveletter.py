def leftrotate(word, k):
    # print(word[k:]+"hi")
    # print(word[0:k]+"helo")
    tmp = word[k : ] + word[0 : k]
    return tmp
   
# In-place rotates word
# towards right by k
def rightrotate(word, k):
   
   return leftrotate(word, len(word) - k)

def rotatedWords(input1, input2):
    # Read only region end
    # Write code here

    # input1 is string of words
    # input2 is k value
    letter = input1
    k = int(input2)
    word = ""
    count = 0
    for i in range(0, len(letter)):
        # print("Hi")
        if letter[i] == ' ':
            print(len(word))
            wordlength = len(word)
            word = rightrotate(word,k)
            if wordlength == k:
                count = count+1
            word = ""
        elif i==len(letter)-1:
            word += letter[i]
            print(len(word))
            wordlength = len(word)
            word = rightrotate(word,k)
            if wordlength == k:
                count = count+1
            word = ""
        else:
            word += letter[i]
    return count


if __name__=="__main__":
    letter = input()
    k = int(input())
    # print("Count : ",rotatedWords(letter, k))
    word1 = rightrotate(letter, k)
    print("old : ", letter)
    print("new : ", word1)