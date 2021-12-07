function x=thomas(a,d,b,r)

%  解Ax=r,A是一个三对角矩阵
%   输入：
%           a是A的上对角线元素，a（n）=0。
%           d是A的对角线元素。
%           b是A的下对角线元素，b（1）=0。
%           r是方程组的右端向量。
n=length(d);a(1)=a(1)/d(1);r(1)=r(1)/d(1);

for i=2:n-1

denom=d(i)-b(i)*a(i-1);

if denom==0
    disp('error 分母为零');
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
