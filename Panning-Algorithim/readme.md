This requires the RNBO extension for maxMSP. It is configured to be 7.1.4 currently, so has 12 channels in, 12 out. In the bottom right of the RNBO patch, the GUI can be found: 

<img width="627" height="239" alt="image" src="https://github.com/user-attachments/assets/e2ec232b-6db2-4b42-b29a-cb846d248f60" />

**Algorithim Explanation**

This algorithim allows for a set of input parameters (EQ in this case) to be distributed across 12 channels, and 'spataily-weight' them based on three extra parameters:

- latitude
- longitude
- spatial-q

The EQ parameters will be reffered to as 'processor parameters', and the spatial controls 'spatial parameters'.

It works as so:

- Each channel is positioned on a sphere and assigned a set of co-ordinates, latitude and longitude. These follow the offical Dolby Atmos specification, but could be re-arranged however the user sees fit. Extra channels can also be added/removed, allowing it to be configured as a 9.1.6, 5.1.2 system etc. 

- The user inputs a set of processor parameters, and a set of spatial parameters. 

- The processor parameters are stored, and based on the spatial parameters a scaling value is created for each channel, which is determined by the channel's distance to the latitude and longitude values (user position), and then scaled by the spatial-q value. 

- The processor parameters are then scaled per-channel by the scaling values generated earlier, meaning the closer to the user postion each channel is, the more pronounce the EQ curve becomes, and as you move away from the user positon, the EQ curve becomes flat. 

- Spatial-Q simply changes the distance at which the EQ curve becomes flat, allowing for the EQ curve to become more/less focused at the area around the user position.

This allows the user to perform spatial-tone shaping, by altering the frequnecy repsonse of certain areas in the mix, without having to tweak values per-channel. Whilst not tehcnically an object-audio based sytem, it allows the EQ curve to be used like an object, and be postioned (which to me, is a much much more natural way of handling FX processing in Atmos).
