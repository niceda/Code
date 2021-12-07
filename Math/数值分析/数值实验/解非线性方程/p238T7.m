clear;
f=@(x) (x^3-3*x-1);
df=@(x) (3*x^2-3);
% newton(f,df,2,0.0005,5)
secant(f,1.9,2,0.0005,5)

s
