function x=lu_solve(L,U,b)

%  �ⷽ����LUx=b.

[n,m]=size(L); z=zeros(n,1); x=zeros(n,1);

% ��Lz=b.

z(1)=b(1);

for i=2:n

z(i)=b(i)-L(i,1:i-1)*z(1:i-1);

end
% ��Ux=z.

x(n)=z(n)/U(n,n);

for i=n-1:-1:1

x(i)=(z(i)-U(i,i+1:n)*x(i+1:n))/U(i,i);

end
