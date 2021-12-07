%       用复化Simpson积分公式求f的积分。
%       n必须是偶数
clear;
f=@(x) (sin(x)./x);
a=0;
b=1;
n=8;
h=(b-a)/n;
S=1;
for     i=1:2:n-1
         x(i)=a+h*i;
         S=S+4*feval(f,x(i));
end
for      i=2:2:n-2 
    x(i)=a+h*i;
           S=S+2*feval(f,x(i));
end
S=S+feval(f,b);
I=h*S/3
R=(-(b-a)/180)*h^4*(1/5)

