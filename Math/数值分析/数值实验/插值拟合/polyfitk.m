function  [P,sigma]=polyfitk(X,Y,k)
%% ����ʽ���������. 
%% 1. ����С�������k�ζ���ʽϵ�� ;
%% 2. �����sigma.
%% 3. �󷨷��̵�ϵ����ATA
%% 4. ���� X--���ݵ��x���꼯��,Y--���ݵ��y���꼯��. k--��϶���ʽ����.
%% 5. ��� P=a(n)*x^n+a(n-1)*x^(n-1)+...+a1*x+a0;  sigma--���ƽ����
%% Copyright  By ZZG  2008.12.04

if nargin<2
   error('Must provide the X and Y respectively!');
end
if nargin<3
    k=3;
end

[Rn,Cn]=size(X);  if ( Cn > 1),    X=X';end

[RnY,CnY]=size(Y); if ( CnY > 1),  Y=Y'; end

[Rn,Cn]=size(X);  [RnY,CnY]=size(Y);
    
if (Cn > 1) | (CnY >1)
   error('X (and function values) must be inputed in Nx1 Vector! Please enter the X and function values again!')    
end

if Rn~=RnY
    error('The numbers of X and Function Values  are not equal !')
end

if (max(X)~=X(Rn) ) | (min(X)~=X(1))
   error('The data in X must be sorted from little to great!  X(i) and Y(i) must be in corresponding!')    
end

%%%%%%%%%%%%%%%%%%%%%%
 A=zeros(Rn,k+1);
   A(:,1)=ones(size(X));
 for i=2:(k+1)
     A(:,i)=X.^(i-1);
 end
     ATA=A'*A
     ATY=A'*Y
     P=ATA\ATY;
 Ystar=P(1)*ones(size(X));
 for i=2:(k+1)
     Ystar=Ystar+P(i).*(X.^(i-1));
 end
     sigma=sum((Ystar-Y).^2);
     
     XX=X(1):0.05:X(Rn); 
     YY=P(1)*ones(size(XX));
     for i=2:(k+1)
         YY=YY+P(i).*(XX.^(i-1));
     end
     
     plot(X,Y,'*',XX,YY,'-')
     