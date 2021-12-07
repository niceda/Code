function [x,y]=bisect(fun,a,b,tol,max)
a(1)=a; b(1)=b;
ya(1)=feval(fun,a(1));
yb(1)=feval(fun,b(1));
if ya(1)*yb(1)>0
    disp('区间端点函数同号');
    return;
end
for i=1:max
    x(i)=(a(i)+b(i))/2;
    y(i)=feval(fun,x(i));
    if abs(x(i)-a(i))<tol
        disp('二分法已收敛');
        break;
    end
    if y(i)==0
        disp('准确解');
        break;
    elseif y(i)*ya(i)<0
        a(i+1)=a(i);
        ya(i+1)=ya(i);
        b(i+1)=x(i);
        yb(i+1)=y(i);
    else a(i+1)=x(i);
        ya(i+1)=y(i);
        b(i+1)=b(i);
       yb(i+1)=yb(i);
    end
    iter=i;
end
if iter>=max
    disp('没有得到满足精度的解');
end
%n=length(x);
%k=1:n;
%out[k' a(1:n)' b(1:n)' x' y'];
%disp('step a b x' y'') 
   

 
    