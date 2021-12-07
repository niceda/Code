function [x,y]=secant(fun,a,b,tol,max)
x(1)=a;x(2)=b;
y(1)=feval(fun,x(1));
y(2)=feval(fun,x(2));
for i=2:max
    x(i+1)=x(i)-y(i)*(x(i)-x(i-1))/(y(i)-y(i-1));
    y(i+1)=feval(fun,x(i+1));
    if abs(x(i+1)-x(i))<tol
        disp('���߷�������');
        break;
    end
     if y(i)==0
        disp('׼ȷ��');
        break;
     end
    iter=i;
end
if iter>=max
    disp('û�еõ����㾫�ȵĽ�')
end