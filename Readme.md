 **Digitally-Controlled Analog `EQ for Bus Processing in Dolby Atmos**

This was a project completed for my Final Year Project, which demonstrates a unique and natural way to integrate analog hardware into multi-channel workflows through the use of digital control. It also includes an algorithim for manipulating effects processing in the spatial domain with three potentiometers, simplifying the UI massively from other products on the market.

**System Overview**

Per-channel, the system comprises of an analog EQ, whose paramters are contolled from an array of digipots (digital potentiometers). The specific digipot chosen was the AD5290 as it allows for bi-polar signals to be passed through, and also has very low distortion (0.006% typical) which removes the need for any signal conditioning (biasing/gain-staging). These present a massive advantage over using either VCA/VCF chips or a transistor as a crude voltage controlled resistor, as they can be effectively dropped in as a replacement for a physical potentioemter, excluding the digital control circuitry. 

The microcontroller reads a set of physical potentiometers (low shelf gain, low shelf frequency etc..) and then proceses and passes these values to the digipots over an SPI bus, allowing the microcontroller to translate a single input, such as input gain to 12 channels simultaneously. The AD5290's are able to be configured in daisy chain mode, which means all of them can be controlled off of a single, three-wrie SPI bus (CS, SCK, MOSI). The only requirement here is that all digipots must be updated simultaneusly, which leads to a large amount of identical data to be passed thorugh every time a single parameter is changed. 

PCB layouts, Spice Sims, Code and a write-up for each section are availabe in their respective folders:
Digital Control 
EQ-Channel
Mounting Board
Panning Algorithm


**EQ Circuit**




