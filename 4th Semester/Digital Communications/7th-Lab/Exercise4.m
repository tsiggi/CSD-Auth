1;
# Function that checks if a message has an error
function Check_Message (message,str)
  flag = true;
  count = 0 ;
  j = 0 ;
  # Row parities Check 
  for i = message 
    if i == "1"
      count = count + 1 ;
    endif 
    j = j + 1;
    if j == 8 
      if mod(count,2) == 1
        flag = false;
        break
      endif
      count = 0;
      j = 0;
    endif
  endfor
  
  # if there is a problem print the message else check Column parities
  if flag==false
    disp(strcat(str," Message with ERROR!"))
  else 
      for i = 1:8                                 # 8 columns
        count = 0;
        for j = 1:5                               # 5 rows
   
          if message(j*8 - 8 + i) == "1"          # j*8 - 8 + 1 gives the first column  
            count = count + 1;                    # counts the bits that are 1 (turned on)
          endif
        endfor
        
        if mod(count,2) == 1                      # if count of 1 bits is not even then the messages transferred with error
          flag = false;
          break
        endif
      endfor
    if flag == false
      disp(strcat(str," Message with ERROR!"))
    else
      disp(strcat(str," Message with No error!"))
    endif
  endif
end

array_message_with_no_errors = ["1100111110111011011100100101001101010101"]  # 1st message with no errors (40 bits)
array_message_with_1_error   = ["1100111110011011011100100101001101010101"]  # 2nd message with 1 error (40 bits)
array_message_with_2_errors  = ["1100111110010011011100100101001101010101"]  # 3rd message with 2 errors (40 bits)


# Check if a 2d array message that cames out of "Askhsh3" has an error
# 1st message is the result of "Askhsh3"
# 2nd message is the 1st message with 1 bit change  in the 2nd row 3rd column
# 3rd message is the 1st message with 3 bit changed in [2,3] and [2,5]     [rows,columns]
disp("")
Check_Message(array_message_with_no_errors,"1st");       
Check_Message(array_message_with_1_error  ,"2nd");
Check_Message(array_message_with_2_errors ,"3rd");

