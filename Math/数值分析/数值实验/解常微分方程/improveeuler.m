function [x,y]=improveeuler(f,tspan,y0,n)
%  解初值问题：     y'=f(x,y),y(a)=y0。
%步长 h=(b-a)/n。
a=tspan(1);b=tspan(2);h=(b-a)/n;
x=(a+h:h:b);
yp=y0+h*feval(f,a,y0);
yc=y0+h*feval(f,a+h,yp);
y(1)=(1/2)*(yp+yc);
for  i=1:n-1
    yp=y(i)+h*feval(f,x(i),y(i));
    yc=y(i)+h*feval(f,x(i+1),yp);
    y(i+1)=(1/2)*(yp+yc);
end
x=[a x];
y=[y0 y];
