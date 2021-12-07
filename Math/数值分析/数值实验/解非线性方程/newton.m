function [x,y]=newton(fun,dfun,x1,tol,max)
x(1)=x1;y(1)=feval(fun,x(1));
dy(1)=feval(dfun,x(1));
for i=2:max
    x(i)=x(i-1)-y(i-1)/dy(i-1);
    y(i)=feval(fun,x(i));
    if abs(x(i)-x(i-1))<tol
        disp('newton迭代已收敛');
        break;
    end
    dy(i)=feval(dfun,x(i));
    iter=i;
end
if iter>=max
    disp('没有得到满足精度的解')
end