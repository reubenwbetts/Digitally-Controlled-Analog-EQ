**Digitally-Controlled Analog `EQ for Bus Processing in Dolby Atmos**

This was a project completed for my Final Year Project, which demonstrates a unique and natural way to integrate analog hardware into multi-channel workflows through the use of digital control. It also includes an algorithim for manipulating effects processing in the spatial domain with three potentiometers, simplifying the UI massively from other products on the market.

**System Overview**

Per-channel, the system comprises of an analog EQ, whose paramters are contolled from an array of digipots (digital potentiometers). The specific digipot chosen was the AD5290 as it allows for bi-polar signals to be passed through, and also has very low distortion (0.006% typical) which removes the need for any signal conditioning (biasing/gain-staging). These present a massive advantage over using either VCA/VCF chips or a transistor as a crude voltage controlled resistor, as they can be effectively dropped in as a replacement for a physical potentioemter, excluding the digital control circuitry. 

The microcontroller reads a set of physical potentiometers (low shelf gain, low shelf frequency etc..) and then proceses and passes these values to the digipots over an SPI bus, allowing the microcontroller to translate a single input, such as input gain to 12 channels simultaneously. The AD5290's are able to be configured in daisy chain mode, which means all of them can be controlled off of a single, three-wrie SPI bus (CS, SCK, MOSI). The only requirement here is that all digipots must be updated simultaneusly, which leads to a large amount of identical data to be passed thorugh every time a single parameter is changed. 

**Digital Control**

Whilst the system is relatively simple, the digital control circuitry can become quite complex due to possible zipper nosie from performing discrete parameter changes. As the digipots are 8-bit, even small parameter changes can lead to sharp edges on the audio signal, which if large enough, could create audible clicking sounds to be mixed into the audio signal. To avoid this, a zero-cross detection ciruit was created to ensure parameter changes only take place when the signal passing through a digipot is at a zero-crossing.

This was done through a pair of comparators, which would change to a high state when the signal was in the range of +/-50Mv, and their outputs were ANDed to create a pulse at the singals zero-crossing. This was then ANDed with the CS line, which meant only when CS was high, and a zero crossing had occured, that the AD5290's CS input would become high. 

The AD5290's required a low CS input to be written to their input buffer, and a high state to move the wiper position to the position stored in the buffer. This meant that the microcontroller could set the CS line to low whilst each digipot was written to, and once the data was transferred, a zero-crossing pulse at each digipots input would update them all indepently of the MCU, exactly when a zero-crossing took place.

A final consideration was that due to propogation delay from the ZCD circuit and the two logic gates (around 70ns), the CS update may end up taking place outside of the zero-crossing. To fix this, a bessel filter was also implemented to delay the audio signal (a matlab script was created to calculate the values), re-syncing the two waveforms. However, in practise the propogation delay was insignificant enough to warrant using it.

<img width="642" height="380" alt="image" src="https://github.com/user-attachments/assets/5fef43b5-8d66-4d56-acda-c0c5558d90e0" />
