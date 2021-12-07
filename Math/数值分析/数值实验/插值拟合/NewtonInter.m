function  [DividedDiffTable,CoEff]=NewtonInter(Nodes,FValues)
%% 牛顿插值系数 f[x0,x1,...,xn] 求解程序. 
%% Nodes is the set of all nodes, It is a vector;
%% Copyright by ZZG, 2008.12.04
if nargin<2
        error('Must provide the sets of Nodes and Faction Values!');
end
 
[Rn,Cn]=size(Nodes);
if ( Rn > 1)
     Nodes=Nodes';
end
[Rnf,Cnf]=size(FValues);
if ( Rnf > 1)
     FValues=FValues';
end

[Rn,Cn]=size(Nodes);  [Rnf,Cnf]=size(FValues);
    
if (Rn > 1) | (Rnf >1)
       error('Nodes (and function values) must be input in 1xN Vector! Please enter the nodes and function values again!')    
end

if Cn~=Cnf
    error('The numbers of Nodes and Function Values  are not equal !')
end
 
DividedDiff=zeros(Cn,Cn);
DividedDiff(:,1)=FValues';

for cI=2:Cn
   for rI=cI:Cn
       xrI=Nodes(rI);  xrI_k=Nodes(rI-(cI-1));
       DDiff=( DividedDiff(rI,cI-1) -  DividedDiff(rI-1,cI-1) )/ ( xrI-xrI_k );
       DividedDiff(rI,cI)=DDiff;
   end
end
 DividedDiffTable=[Nodes',DividedDiff];
 CoEff=diag(DividedDiff);
