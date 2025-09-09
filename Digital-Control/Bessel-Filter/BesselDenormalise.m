function [capout] = BesselDenormalise(fc,r, capin)

capout = capin/(2*pi*fc*r);

end

