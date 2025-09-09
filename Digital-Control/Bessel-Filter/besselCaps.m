function [c1,c2] = besselCaps (sigma, omega)

c1 = 1/sigma;

c2 = sigma/((sigma^2) + omega^2);

end