N = int(input())
M = int(input())
data = input()

fidx = data.find("I"),
count = 0
result = 0
if fidx == -1:
    print(-1)
else : 
    i = fidx
    while fidx != -1 :
        if i+1 >=M or i+2 >=M : 
            if count >= N:
                result += count - N + 1
            break
        if data[i+1] == 'O' and data[i+2] == 'I' : 
            #print("IOI",i,count)
            count+=1
            i+=2
        else :
            #print("else",i,fidx,count,result)
            if count >= N : 
                result += count - N + 1
            count =0
            fidx= data.find("I",i+1)
            if fidx ==-1 :
                break
            i = fidx
            #print("result : ",result)
print(result)