function [z,m]=power_m(A,max_it,tol)
     [n,nn]=size(A); z=ones(n,1);
     it=0; error=100;
    
   while  it<max_it&error>tol
     w=A*z;ww=abs(w);
     [k,kk]=max(ww);%kkΪww���Ԫ�صı�š�
      m=w(kk);            %����ֵ�Ľ���ֵ��
     z=w/w(kk);          %���������Ľ���ֵ��
    out=[it+1 m];disp(out)
    error=norm(A*z-m*z);
   it=it+1;
   end
