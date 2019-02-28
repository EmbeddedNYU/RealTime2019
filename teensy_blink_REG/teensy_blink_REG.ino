void setup() {
  // put your setup code here, to run once:
  //We know that the LED is at Port C pin 5 from schematic
 
 
GPIOC_PDDR |= (1U << 5); // led portC5 data direction register
PORTC_PCR5 |= 0x00000100;  //Enable portC pin5 ,bit 8 
//GPIOC_PDOR |= (1U << 5); // portC5 data output register
//Serial.begin(38400);

}

void loop() {
  // put your main code here, to run repeatedly:
GPIOC_PDOR |= (1U << 5); // portC5 data output register
delay(1000);
//Serial.println(GPIOC_PDDR,HEX);
GPIOC_PDOR &= ~(1U << 5); // portC5 data output register
delay(1000);
}
