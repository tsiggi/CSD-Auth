mes_without =   ["100011010110000"]     # 1st message 
mes_with_1_er = ["100010010110000"]     # 2nd message 1 error  (6th bit)
mes_with_2_er = ["100010010111000"]     # 3rd message 2 errors (6th & 12th bit)

c = length(mes_without);                # message length 
count1 = 0 ;                            # counts the "1" bits in 1st message
count2 = 0 ;                            # counts the "1" bits in 2nd message
count3 = 0 ;                            # counts the "1" bits in 3rd message

for i = 1:c                             # loops through the message
  
  if mes_without(i) == "1"              # checks if the bit is "1"
    count1 = count1 + 1;                # adds 1 in the counter 
  endif
  if mes_with_1_er(i) == "1"             # same 
    count2 = count2 + 1;
  endif
  if mes_with_2_er(i) == "1"             # ...
    count3 = count3 + 1;
  endif
endfor

disp("")

#  for the first message with no changed bits 
if mod(count1,2) == 0
  disp("1st Message found with No errors!")
else
  disp("1st Message found with ERROR!")
endif

#  for the second message with 1 changed bit 
if mod(count2,2) == 0
  disp("2nd Message found with No errors!")
else
  disp("2nd Message found with ERROR!")
endif

#  for the third message with 2 changed bit 
if mod(count3,2) == 0
  disp("3rd Message found with No errors!")
else
  disp("3rd Message found with ERROR!")
endif