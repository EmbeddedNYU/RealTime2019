

int buf[7] = {255,238,191,127,64,17,0}; //This is for sine wave duty cycle values for the demo
int del = 100; //just a variable for delay arg in loop

void setup() {
Serial1.begin(38400);
delay(1000);

PORTD_PCR4 |= (1U << 10); //MUX

////////////////////////////////////////////////////////////  PWM Section ////////////////////////////////////////////////////////////////////

//PWM duty cycle(0 to 255) = 255 * (voltage/(3.3))  , thus 1.6V should give us 50% duty cycle.  USING 8 BIT RESOLUTION
//PTD4, chip 61, board 6 PWM  ...............FTM0 channel 4
//bit 3 and bit 4 of status control , This selects system clock

FTM0_SC |= _BV(3); //Status control register
FTM0_SC &= ~(_BV(4));

//DISABLE WRITE PROTECTION
FTM0_MODE |= (1U << 2); //Mode register

FTM0_MODE |= _BV(1); // Enables FTM, this must come after the line above since this bit is write protected.

FTM0_SC |= 0x3; //set bit 0 1, 

//Set MSB and ELSB, bit 5 and bit 3. This sets edge aligned PWM mode
FTM0_C4SC |= (1U << 3) | (1U << 5);

//Requirements for edge aligned up counter pwm is done, MSnB 1 (Channel mode select B) ,QUADEN 0 (Quadrature Decoder), DECAPEN 0 (Dual edge capture) , COMBINE 0 (Pair dual channel)
//CPWMS 0 (center aligned disabled and set as upcounting mode)

FTM0_CNTIN = 0; //Initial value is 0 for PWM counter, also edge align mode MUST use CNTIN by design
FTM0_C4V = 128; // count up to C4V and clear output, C4V/MOD duty cycle %
FTM0_MOD = 255;//counts up to MOD then counts back up from 0, this is the period of cycle

}

void loop() {


//This is for making a sine wave, hook up to oscilloscope to see it or just delete this part of the code to test what you want. 
for(int i = 0; i <= 6; i++ ){
  FTM0_C4V = buf[i];
  delay(del);
  }

for(int j = 5; j >= 0; j-- ){
  FTM0_C4V = buf[j];
  delay(del);
  }






}
