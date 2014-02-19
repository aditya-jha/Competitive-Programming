
sub = []
k= 0

def check(a,b,length):
    mis = 0
    #print a[0]
    #print b[0]
    for p in range(length):
        if a[p] != b[p]:
            mis = mis+1
    if mis <= k:
        return 1
    else:
        return 0

def mismatch():
    length = len(sub)
    count = 0
    i=0
    while i<length-1:
        j=i+1
        while j<length:
            if(len(sub[i]) == len(sub[j])):
                if check(sub[i],sub[j],len(sub[i])):
                    count = count+1
            j = j+1
        i = i+1
    return count


def main():
    k = int(raw_input())
    s = raw_input()
    #print s
    length = len(s)
    #print length
    
    i=0
    
    while i<length:
        j = length-1
        while j>-1:
            temp = s[i:j+1]
            if temp != '':
                sub.append(temp)
            j = j-1
        i = i+1
    #print sub
    print mismatch()
    
main()

