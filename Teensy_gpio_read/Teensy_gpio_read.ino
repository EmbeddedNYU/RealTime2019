//char count = 0;

void setup() {
  // put your setup code here, to run once:
GPIOC_PDDR |= (1U << 5); // led portC5 data direction register
PORTC_PCR5 |= 0x00000100;  //Enable portC pin5 as GPIO function

//Using portC7 as input  
GPIOC_PDDR &= ~(1U << 7); // portC7 data direction register, make pin input
PORTC_PCR7 |= 0x00000102;  //Enable portC pin7 pull down resistor, bit 8 and 1
Serial.begin(38400);

}

void loop() {
  // put your main code here, to run repeatedly:
if(GPIOC_PDIR & 0x00000080)
{
  GPIOC_PDOR |= (1U << 5); //led on
  Serial.println("LED is ON");
  delay(750);
}
  else
  {
    GPIOC_PDOR &= ~(1U << 5); // portC5 data output register
    Serial.println("OFF");
  delay(750);
    }
  
  
 /*  volatile bool A;
   volatile bool B;

   A = GPIOC_PDIR & 0x00000080;
  // delayMicroseconds(1000);
  delay(1);
   B = GPIOC_PDIR & 0x00000080;
  if(A != B) {
    count++;
    GPIOC_PTOR |= (1U << 5); // portC5 data output register
  
  }
 if(GPIOC_PDIR == 0 && count%2  ){
  Serial.print("Bounce detected , count is  ");
  Serial.println(count,DEC);
  delay(2000);
  }
*/
}

