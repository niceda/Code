function I =trap(f,a,b,n)
        %  用复化梯形公式求f的积分。
         h=(b-a)/n;S=feval(f,a)
       
         for   i=1:n-1
         x(i)=a+h*i;
         S=S+2*feval(f,x(i));
         end
         S=S+feval(f,b);I=h*S/2;
