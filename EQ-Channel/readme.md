**EQ Channel PCB**

A set of schematics, SPICE sims and PCBs for an individual EQ Channel

Each channel consists of:
- De-balancing input
- Gain Stage
- Passive RC HPF
- 4 EQ bands, a low-shelf, two mid-bells and a high-shelf
- Balanced output

Each stage starts with a buffered output, which is passed to the ZCD/Digipot board for generating the CS pulse for the assosciated digipots. Then, the signal is (supposed to be) passed to a bessel filter before being processed to further synchronise the audio signal with the ZCD circuitry, although this is not actually necessary. 

The EQ stages are based on the wein-bridge topology which function as so:
- The signals phase is inverted, then inverted again.
- A wein-bridge network (effectively an RC bandpass) is fed either the in-phase version of the signal, or the inverted version, with the amount determined by the 'gain' potentiometer.
- The output of the wein-bridge is summed with the input signal, creating either a boost or a cut, depending on the positon of the gain-potentiometer.

This is the exact method for the bell stages, however the shelves are created by omitting one half of the wein-bridge (resulting in either an LPF or a HPF). 

