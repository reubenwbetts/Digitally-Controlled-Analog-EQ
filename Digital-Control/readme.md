**Digital Control**

Whilst the overall system is relatively simple, the digital control circuitry can become quite complex due to possible zipper nosie from performing discrete parameter changes. As the digipots are 8-bit, even small parameter changes can lead to sharp edges on the audio signal, which if large enough, could create audible clicking sounds to be mixed into the audio signal. To avoid this, a zero-cross detection ciruit was created to ensure parameter changes only take place when the signal passing through a digipot is at a zero-crossing.

This was done through a pair of comparators, which would change to a high state when the signal was in the range of +/-50Mv, and their outputs were ANDed to create a pulse at the singals zero-crossing. This was then ANDed with the CS line, which meant only when CS was high, and a zero crossing had occured, that the AD5290's CS input would become high. 

The AD5290's required a low CS input to be written to their input buffer, and a high state to move the wiper position to the position stored in the buffer. This meant that the microcontroller could set the CS line to low whilst each digipot was written to, and once the data was transferred, a zero-crossing pulse at each digipots input would update them all indepently of the MCU, exactly when a zero-crossing took place.

A final consideration was that due to propogation delay from the ZCD circuit and the two logic gates (around 70ns), the CS update may end up taking place outside of the zero-crossing. To fix this, a bessel filter was also implemented to delay the audio signal (a matlab script was created to calculate the values), re-syncing the two waveforms. However, in practise the propogation delay was insignificant enough to warrant using it.

<p align=center> <img width="507" height="648" alt="image" src="https://github.com/user-attachments/assets/6cb2f503-6b6f-4595-93fd-a5c0ba5b7cd5" />

<p align=center> Assembled digipot board, with 4 digipots + ZCD circuits.

<p align=center> <img width="292" height="388" alt="image" src="https://github.com/user-attachments/assets/a804206d-5166-410f-8459-61464e5f0e2d" />

<p align=center> ZCD circuit being fed a 20kHz sine wave (output was inverted due to not having the correct logic gates on hand) 

<p align=center> <img width="818" height="305" alt="image" src="https://github.com/user-attachments/assets/1d5cb571-03b9-4733-be0b-ec90b0cdb929" />


<p align=center> Signal flow diagram of the ZCD system
