function [z,m]=power_m(A,max_it,tol)
     [n,nn]=size(A); z=ones(n,1);
     it=0; error=100;
    
   while  it<max_it&error>tol
     w=A*z;ww=abs(w);
     [k,kk]=max(ww);%kk为ww最大元素的标号。
      m=w(kk);            %特征值的近似值。
     z=w/w(kk);          %特征向量的近似值。
    out=[it+1 m];disp(out)
    error=norm(A*z-m*z);
   it=it+1;
   end
