clear all 

% sallen-key bessel filter capacitor values calaculator
% 
% set delay to value needed and run. 
%
% cap'n'denormal = capacitor value in nF.
%
% script created based on formulas in 'Analog and Digital Filter Design Second Edition' by Steve Winder. 
% 
% scaling values taken from CRBonds paper on Bessel Filter design 'http://www.crbond.com/papers/bsf2.pdf'
%
% sigma and omega values take from Analog Devices 'MT204 Bessel Design Tables'
% 'https://www.analog.com/media/en/training-seminars/tutorials/MT-204.pdf'

delay = 0.000005; %input in secs              
r = 100;                   
order = 2;

if (order == 2)
    fc = 1.36165412871613/(2*pi*delay);
    sigma1 = 1.1050;
    omega1 = 0.6368;

    [cap1normal,cap2normal] = besselCaps (sigma1,omega1);

    [cap1denormal] = BesselDenormalise (fc, r, cap1normal) * 1000000000;
    [cap2denormal] = BesselDenormalise (fc, r, cap2normal) * 1000000000; 
end

if (order == 4)
    fc = 2.11391767490422/(2*pi*delay);
    sigma1 = 1.3596;
    sigma2 = 0.9877;
    omega1 = 0.4071;
    omega2 = 1.2476;

    [s1cap1normal,s1cap2normal] = besselCaps(sigma1,omega1);
    [s2cap1normal,s2cap2normal] = besselCaps(sigma2,omega2);

    cap1denormal = BesselDenormalise(fc,r,s1cap1normal) * 1000000000;
    cap2denormal = BesselDenormalise(fc,r,s1cap2normal) * 1000000000;
    cap3denormal = BesselDenormalise(fc,r,s2cap1normal) * 1000000000;
    cap4denormal = BesselDenormalise(fc,r,s2cap2normal) * 1000000000;
end

if (order == 6)
    fc = 2.70339506120292/(2*pi*delay);
    sigma1 = 1.5735;
    sigma2 = 1.3836;
    sigma3 = 0.9318;
    omega1 = 0.3213;
    omega2 = 0.9727;
    omega3 = 1.6640;

    [s1cap1normal,s1cap2normal] = besselCaps(sigma1,omega1);
    [s2cap1normal,s2cap2normal] = besselCaps(sigma2,omega2);
    [s3cap1normal,s3cap2normal] = besselCaps(sigma3,omega3);

    cap1denormal = BesselDenormalise(fc,r,s1cap1normal) * 1000000000;
    cap2denormal = BesselDenormalise(fc,r,s1cap2normal) * 1000000000;
    cap3denormal = BesselDenormalise(fc,r,s2cap1normal) * 1000000000;
    cap4denormal = BesselDenormalise(fc,r,s2cap2normal) * 1000000000;
    cap5denormal = BesselDenormalise(fc,r,s3cap1normal) * 1000000000;
    cap6denormal = BesselDenormalise(fc,r,s3cap2normal) * 1000000000;
end
 
 

