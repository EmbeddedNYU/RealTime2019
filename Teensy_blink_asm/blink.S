//#define __SFR_OFFSET 0 //initialize special function register for linker, offsets IO address used by avr-libc's register definitions 
//.thumb  //Tell assembler to recognize THUMB FORMAT
.syntax unified // UNIFIES SYNTAX DIFFERENCES AMOUNG ARM AND THUMB DIVISION


.equ GPIOC_DDR, 0x400FF094  //Declare address macros
.equ PORTC_PCR5, 0x4004B014 
.equ GPIOC_PDOR, 0x400FF080

.global blink  //Declares symbol for linker to use between files and directories, CANNOT USE EXPORT FOR ARDUINO, since the symbol export is a keyword used in keyword.txt

blink: //function name when exported, label name locally

LDR R0,=GPIOC_DDR //Load DDR address to Register0
LDR R1,[R0] // read the value stored in memory location R0
ORR R1,R1,#0x20 //set bit 5, (R1 = R1 OR 0x20)
STR R1,[R0] //update value, Store the value of R1 into memory location of R0,  Mem[R0] <- R1

LDR R0,=PORTC_PCR5 // Load
LDR R1,[R0] // Read value stored at Mem[R0]
ORR R1,R1,#0x100 //set bit 8
STR R1,[R0] //update value



ledloop:
LDR R0,=GPIOC_PDOR 
LDR R1,[R0] // 
ORR R1,R1,#0x20 //set bit 5
STR R1,[R0] //update value

//delays
LDR R2,=0x00300000 //Set R2 as some constant
delay1:
SUBS R2,R2,#0x1 //R2 = R2 - 1, decrement R2
//cmp R2,0x00000000 //Compare if R2 is 0
bne delay1 //If R2 not equal to 0, branch back to label delay1

//Turns off LED
LDR R0,=GPIOC_PDOR 
LDR R1,[R0] // read previous value
BIC R1,R1,#0x20 //clear bit 5
STR R1,[R0] //update value

//delays
LDR R2,=0x00300000
delay2:
SUBS R2,R2,#0x1
//cmp R2,0x00000000
bne delay2

B ledloop //Loop back to label ledloop, this is the infinite loop of the blink





BX LR //This line would normally return back to the function call, it branches to the link register. This never happens in this code since blink neve returns, it is a infinite blink loop



