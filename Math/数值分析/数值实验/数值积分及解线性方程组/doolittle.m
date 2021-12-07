function [L,U]=doolittle(A)

[n,m]=size(A);

%U=zeros(n,n),
L=eye(n);

for k=1:n

U(1,k)=A(1,k);L(k,1)=A(k,1)/U(1,1);
end

for k=2:n

U(k,k)=A(k,k)-L(k,1:k-1)*U(1:k-1,k);

for j=k+1:n

U(k,j)=A(k,j)-L(k,1:k-1)*U(1:k-1,j);

L(j,k)=(A(j,k)-L(j,1:k-1)*U(1:k-1,k))/U(k,k);

end

end
