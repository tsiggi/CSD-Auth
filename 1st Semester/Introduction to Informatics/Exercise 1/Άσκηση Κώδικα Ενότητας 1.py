import math
a1 = int(input())
a2 = int(input())
b1 = int(input())
b2 = int(input())
costh=(a1*b1+a2*b2)/((math.sqrt(a1**2+a2**2))*(math.sqrt(b1**2+b2**2)))
goniath=math.degrees(math.acos(costh))
print(costh,str(int(goniath))+'°')
