clear;
f=@(x,y)(x^2+100*y^2);
tspan=[0,0.3];
[x,y]=euler(f,tspan,0,3)
