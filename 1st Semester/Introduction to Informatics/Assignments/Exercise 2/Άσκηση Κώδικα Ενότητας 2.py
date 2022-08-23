year=int(input('give a year: '))
disekto=False
if(year%4==0):
  if(year%100==0):
    if(year%400==0):
      disekto=True
  else:
    disekto=True
print(disekto)
