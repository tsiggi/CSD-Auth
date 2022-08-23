#while True:
s=input()
if(len(s)==1):
    print('Μήκος = 1')
else :
    flag=True
    for i in range(len(s)//2):
        if(s[i]!=s[len(s)-1-i]):
            flag=False
            break
    if(flag):
        #print('YES!!!!!')
        adict={s:len(s)}
        alist=[s[i] for i in range(len(s))]
        print(adict)
        print(alist)
    else:
        print('Δεν είναι παλίνδρομο')
