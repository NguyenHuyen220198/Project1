clear all
close all
x=[3:1:9];
y1=[119 123 103 109 149 261 513];
y2=[69 59 61 85 133 257 513];
plot(x,y1,'m*',x,y1,'b-');
hold on;
plot(x,y2,'co',x,y2,'g-');
title('analytical and simulation results of PQRT protocol');
ylabel('Expected number of polling rounds');
xlabel('Initial prefix length');