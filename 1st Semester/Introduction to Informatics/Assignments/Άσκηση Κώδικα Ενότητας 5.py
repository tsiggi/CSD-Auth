import statistics

content=[]
try:
    with open('inputdata.txt','r') as f:
        for inline in f:
            content.append(float(inline))

except FileNotFoundError:
    print("Υπάρχει προβλημα εντομισμού του αρχείου με ονομα :'inputdata.txt'")

except Exception as error:
    print('Προβλημα:')
    print(error)


with open('outputdata.txt','w') as f:
    mo=format(statistics.mean(content),'.3f')
    ta=format(statistics.stdev(content),'.3f')
    astr='Μέσος όρος = '+str(mo)+'\n'+'Τυπική απόκλιση = '+str(ta)+'\n'
    f.write(astr)



