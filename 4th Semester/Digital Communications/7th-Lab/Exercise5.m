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
    disp(strcat(str," Message found with Error!"))
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
      disp(strcat(str," Message found with Error!"))
    else
      disp(strcat(str," Message found with No errors!"))
    endif
  endif
end

array_message_4_errors_1 = ["0100110100111001011100100101001101010101"]     # 1st example: Message with errors that are not recognizable (40 bits)
array_message_4_errors_2 = ["1100111110111011111101101101011101010101"]     # 2nd example: Message with errors that are not recognizable (40 bits)
disp("")
# FIRST EXAMBLE
# This message comes from "Askhsh3" with 4 errors at
# the positions [1,1] [1,7] [2,1] [2,7]

# SECOND EXAMBLE
# This message comes from "Askhsh3" with 4 errors at
# the positions [3,1] [3,6] [4,1] [4,6]


# These Messages have 4 errors each and are recognized like they do not have any
Check_Message(array_message_4_errors_1,"1st");

Check_Message(array_message_4_errors_2,"2nd")

