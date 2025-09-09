#include <SPI.h>
#include "one_pole_iir.h"
#define CS_PIN 10

uint8_t input_pot_values_past[8] = {   };
uint8_t input_pot_values[8] = {   };
uint8_t digipot_values_past[12] = {   };
uint8_t digipot_values[12] = {   };
uint8_t spi_rx_buf[12] = {};
uint8_t input_pots[8] = {16,17,18,19,20,21,22,23};

one_pole_iir potfilter[16];
uint8_t filter_input;
float input_pot_damp_val = 0.5; // massively overdamped, but good for visualising on plotter

EventResponder spiDone;
volatile bool spiBusy = false;

void spiFinished(EventResponderRef event) {
  spiBusy = false;  
  digitalWrite(CS_PIN, HIGH); // mark DMA transfer as complete
}



void setup() {

  // set the slaveSelectPin as an output:
  Serial.begin(9600);
  pinMode(CS_PIN, OUTPUT);
  digitalWrite(CS_PIN, HIGH);

  // initialize SPI:
  SPI.begin();
  SPI.beginTransaction(SPISettings(50000, MSBFIRST, SPI_MODE0));
 
  spiDone.attachImmediate(spiFinished);
  
  // assign all pot pins as inputs
  for (int i = 0; i < 8; i++){
    pinMode(input_pots[i], INPUT);
  }

}

void loop() {

  uint8_t counter = 0;
  bool pot_changed = 0;

  for (int i = 0; i < 8; i++){

    input_pot_values[i] = analogRead(input_pots[i]) >> 2;
    
    // grabbing pin 23 for plotting pre-filter
    if (i == 7)
    {filter_input = input_pot_values[i];}
    
    // filter input pots with two single pole IIR's, should do a second order but didn't have time.
    input_pot_values[i] = potfilter[i].filter_method(input_pot_values[i],input_pot_damp_val);  
    input_pot_values[i] = potfilter[i+8].filter_method(input_pot_values[i],input_pot_damp_val);
    
    /* distribute inputs to the correct positons 
      in digipot array (1,2,2,3,4,4 etc..)   */
    digipot_values[counter] = input_pot_values[i];
    counter++;
    if (i % 2 != 0){
      digipot_values[counter] = digipot_values[counter-1];
      counter++;
    } 

  }
  for (int i = 0; i<12; i++){
    if (digipot_values_past[i] != digipot_values[i])
    pot_changed = 1;
  }

  if (!spiBusy && pot_changed == 1){
    digitalWrite(CS_PIN, LOW);
    spiBusy = true;
    SPI.transfer(digipot_values, 0, 12, spiDone);
  }

  for (int i = 0; i <12; i++){
    digipot_values_past[i] = digipot_values[i];
  }

}


