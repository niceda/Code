       function [x,y]=euler(f,tspan,y0,n)
       %  ���ֵ���⣺     y'=f(x,y),y(a)=y0��
       %  ʹ�� n ���� Euler �������� h=(b-a)/h��
       a=tspan(1);b=tspan(2);h=(b-a)/n;
       x=(a+h:h:b);
       y(1)=y0+h*feval(f,a,y0);
       for  i=2:n
            y(i)=y(i-1)+h*feval(f,x(i-1),y(i-1));
       end
       x=[a x];
       y=[y0 y];
