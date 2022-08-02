input_message = ["10001101011000"]

count1 = 0;

for i = input_message
  if i == "1"
    count1 = count1 + 1;
  endif
endfor

if mod(count1,2)==1
  final_message = strcat(input_message,"1");
else
  final_message = strcat(input_message,"0");
endif

disp("")
disp("The output Message with Parity is : ")
disp(final_message)