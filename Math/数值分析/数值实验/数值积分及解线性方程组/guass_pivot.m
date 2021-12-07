function x=guass_pivot(A,b)

%  ����ѡ��Ԫ��Gauss��ȥ���ⷽ����Ax=b��

%���룺A��һ��      n*n    ϵ������b��   n*1     ���Ҷ�������

[n,n1]= size(A);

for i=1:n-1

[pivot,k]=max(abs(A(i:n,i)));
if k>1

temp1=A(i,:); temp2=b(i,:);

A(i,:)=A(i+k-1,:); b(i,:)=b(i+k-1,:);

A(i+k-1,:)=temp1; b(i+k-1,:)=temp2;

end

for h=i+1:n

m=A(h,i)/A(i,i);

A(h,:)=A(h,:)-m*A(i,:);
b(h,:)=b(h,:)-m*b(i,:);

end

end

% �ش�����

x(n,:)=b(n,:)./A(n,n);

for i=n-1:-1:1

x(i,:)=(b(i,:)-A(i,i+1:n)*x(i+1:n,:))./A(i,i);

end
