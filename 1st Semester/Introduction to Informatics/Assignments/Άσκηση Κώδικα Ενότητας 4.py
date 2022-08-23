import statistics

def squares(*args):
    if len(args)==0:
        return
    m=statistics.mean(list(args))
    for i in args:
        s=(m-i)**2
        yield s
 
for i in squares(2,7,3,12):
    print(i,end=' ')

