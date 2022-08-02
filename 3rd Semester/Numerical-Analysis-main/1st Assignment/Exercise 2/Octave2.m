x = linspace(-1.4,1.2);
x2 = linspace(-2,2);
y1 =  54.*x.^6 .+ 45.*x.^5 .- 102.*x.^4 .-69.*x.^3 .+ 35.*x.^2 .+ 16.*x - 4;
y2 = x .- x;



plot(x, y1,'r',x,y2,'b');

xlabel("x")
# ylabel("f(x)= 14xe^x^-^2 - 12e^x^-^2 - 7x^3 + 20x^2 - 26x + 12")
set(gca,'FontSize',24)
title("y=0 and f(x)= 54x^6+45x^5-102x^4-69x^3+35x^2+16x-4")