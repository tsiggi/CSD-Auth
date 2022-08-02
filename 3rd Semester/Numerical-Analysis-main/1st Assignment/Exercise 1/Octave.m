x = linspace(0.5,2.5);
x2 = linspace(0.5,2.5);
y1 =  14.*x.*e.^(x.-2) - 12.*e.^(x-2) - 7.*x.^3 .+ 20.*x.^2 .- 26.*x .+ 12;
y2 = x .- x;



plot(x, y1,'r',x,y2,'b');

xlabel("x")
# ylabel("f(x)= 14xe^x^-^2 - 12e^x^-^2 - 7x^3 + 20x^2 - 26x + 12")
set(gca,'FontSize',24)
title("y=0 and f(x)= 14xe^x^-^2 - 12e^x^-^2 - 7x^3 + 20x^2 - 26x + 12")