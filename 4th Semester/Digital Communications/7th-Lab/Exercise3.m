message = ["1100111101110101110010101001"]; # original message with 28 bits


temp1 = ""   ;                              # stores the 1st column                                
count_row_1 = 0 ;                           # counts the "1" bits in 1st row

temp2 = ""   ;                              # stores the 2nd column
count_row_2 = 0;                            # counts the "1" bits in 2nd row

temp3 = "" ;                                # stores the 3rd column
count_row_3 = 0;                            # ...

temp4 = "" ;                                # stores the 4th column
count_row_4 = 0;                            # ...

temp5 = "";                                 # stores the 5th column
count_row_5 = 0;                            # ... 

c = length(message);                        # message length 


# Divide the message and stores the data to 4 variables (4 rows)

for i = 1:c                                 # loops through the message
  if i <= 7 
    temp1 = strcat(temp1,message(i));       # adds the bit to the 1st row 
  else
    if i <= 14
      temp2 = strcat(temp2,message(i));     # adds the bit to the 2nd row
    else 
      if i <= 21 
        temp3 = strcat(temp3,message(i));   # adds the bit to the 3rd row
      else
        temp4 = strcat(temp4,message(i));   # adds the bit to the 4th row
      endif
    endif
  endif
endfor




# Calculate the count of 1 bits for every row 
for i = 1:7
  if temp1(i) == "1"                        # checks if the bit is 1  (1st row)
    count_row_1 = count_row_1 + 1;          # adds 1 in the counter 
  endif
  if temp2(i) == "1"                        # checks if the bit is 1  (2nd row)
    count_row_2 = count_row_2 + 1;          # adds 1 in the counter2
  endif
  if temp3(i) == "1"                        # same ...
    count_row_3 = count_row_3 + 1;
  endif
  if temp4(i) == "1"                        # same ...
    count_row_4 = count_row_4 + 1;
  endif
endfor


# Row parities 

# We add the Row Parity bits 
if mod(count_row_1,2)==1
  temp1 = strcat(temp1,"1");
else
  temp1 = strcat(temp1,"0");
endif

if mod(count_row_2,2)==1
  temp2 = strcat(temp2,"1");
else
  temp2 = strcat(temp2,"0");
endif

if mod(count_row_3,2)==1
  temp3 = strcat(temp3,"1");
else
  temp3 = strcat(temp3,"0");
endif

if mod(count_row_4,2)==1
  temp4 = strcat(temp4,"1");
else
  temp4 = strcat(temp4,"0");
endif



# Calculating Column parities (5th Column)
for i = 1:8                   
  count_temp = 0 ;
  if temp1(i) == "1"
    count_temp = count_temp + 1;
  endif
  if temp2(i) == "1"
    count_temp = count_temp + 1;
   endif
  if temp3(i) == "1"
    count_temp = count_temp + 1;
   endif
  if temp4(i) == "1"
    count_temp = count_temp + 1;
   endif
  
  if mod(count_temp,2) == 1
    temp5 = strcat(temp5,"1");
  else
    temp5 = strcat(temp5,"0");
  endif
  
  
endfor




# Create a 2d final message 
output_message_2d_array = [temp1;temp2;temp3;temp4;temp5]

# Creates the final message that is transmitted 
output_message = strcat(temp1,temp2,temp3,temp4,temp5)



