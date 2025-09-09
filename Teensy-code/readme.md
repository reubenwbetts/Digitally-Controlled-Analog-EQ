**Example code for a single channel of EQ using four digipot boards (12 digipots) with a Teensy 4.1**

In this example, the Teensy reads in a set of 8 inputs, and distributes them to 12 digipots (to form a single channel of EQ).

- Input 1 (High Shelf Gain) - Digipot 12 
- Input 2 (High Shelf Frequency) - Digipot 11 + 10
- Input 3 (High Mid Bell Gain) - Digipot 9 
- Input 4 (High Mid Bell Frequency) - Digipot 8 + 7
- Input 5 (Low Mid Bell Gain) - Digipot 6 
- Input 6 (Low Mid Bell Frequency) - Digipot 5 + 4
- Input 7 (Low Shelf Gain) - Digipot 3 
- Input 8 (Low Shelf Frequency) - Digipot 2 + 1

As the digipots are configured in daisy chain mode, the data on the SPI bus is pushed through the system. If N = TXBuffer's length in bytes (12 in this case), and the digipots are numbered based on their position on the physical bus (digipot 1 is the closest to the MCU/first in the chain) then by the time the transfer has finished, the first byte sent will end up in digipot N, the second byte N-1, then N-2 etc...

The code is structured as so:

- Read in pots to an Array
- Filter out any noise with a pair of IIR's (exponential moving averages)
- Distribute the filtered signal to the SPI TXBuffer.
- Compare this TXBuffer to the previous buffer created and if difffernt, update the digipots.

**THIS CODE IS SLOW, ANALOGREAD AND GENERAL ARDUINO LIBRARIES ADD A MASSIVE OVERHEAD, BUT IT WORKS AS A PROOF-OF-CONCEPT**


        
