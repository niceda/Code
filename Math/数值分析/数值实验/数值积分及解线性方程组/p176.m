clear;
A=[12 -3 3;-18 3 -1;1 1 1];
b=[15; -15; 6];
% guass_pivot(A,b)
[L,U] = doolittle(A);
lu_solve(L,U,b)