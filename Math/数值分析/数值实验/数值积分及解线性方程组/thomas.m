function x=thomas(a,d,b,r)

%  ��Ax=r,A��һ�����ԽǾ���
%   ���룺
%           a��A���϶Խ���Ԫ�أ�a��n��=0��
%           d��A�ĶԽ���Ԫ�ء�
%           b��A���¶Խ���Ԫ�أ�b��1��=0��
%           r�Ƿ�������Ҷ�������
n=length(d);a(1)=a(1)/d(1);r(1)=r(1)/d(1);

for i=2:n-1

denom=d(i)-b(i)*a(i-1);

if denom==0
    disp('error ��ĸΪ��');
end 

a(i)=a(i)/denom;
end
for i=2:n
r(i)=(r(i)-b(i)*r(i-1))/(d(i)-b(i)*a(i-1));
end
x(n)=r(n);

for i=n-1:-1:1

x(i)=r(i)-a(i)*x(i+1);

end
