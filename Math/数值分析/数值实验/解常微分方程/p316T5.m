clear;
f=@(x,y) (x+y);
tspan=[0,1];
% [x,y]=rk4(f,tspan,1,5)
[x,y]=improveeuler(f,tspan,1,5)