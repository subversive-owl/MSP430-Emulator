#include <msp430g2553.h>

unsigned int i = 0;

void main(void){
  asm(
      "ADD R4, R5\n"

      "ADD 0x2(R5), 0x2(R4)\n"
      "ADD -0x2, -0x4(R4)\n"
      "ADD 0x2(R5), 0x4\n"
      "ADD 0x8, 0x2\n"
      "ADD &0xC000, 0x2(R4)\n"
      "ADD 0x2(R5), &0xC000\n" 
      "ADD &0xC004, &0xC008\n" 
      "ADD 0x2, &0x3F0\n"
      "ADD &0xC000, 0x2\n"
      
      "ADD @R5, R7\n"

      "ADD @R5, 0x2(R4)\n"
      "ADD @R5, 0x2\n"
      "ADD @R5, &0x300\n"

      "ADD @R5+, R7\n"
      "ADD #0x1234, R7\n"

      "ADD @R5+, 0x2(R4)\n"
      "ADD @R5+, 0x2\n"
      "ADD @R5+, &0x300\n"
      "ADD #0x1234, 0x2(R4)\n"
      "ADD #0x1234, 0x2\n"
      "ADD #0x7829, &0x304\n"

      "ADD.B R4, R5\n"

      "ADD.B @R5+, 0x2(R4)\n"
      "ADD.B @R5+, 0x2\n"
      "ADD.B @R5+, &0x300\n"
      "ADD.B #0x1234, 0x2(R4)\n"
      "ADD.B #0x1234, 0x2\n"
      "ADD.B #0x7829, &0x304\n"

      "ADD.B 0x2(R5), 0x2(R4)\n"
      "ADD.B -0x2, -0x4(R4)\n"
      "ADD.B 0x2(R5), 0x4\n" 
      "ADD.B 0x4, 0x2\n"
      "ADD.B &0xC000, 0x2(R4)\n" 
      "ADD.B 0x2(R5), &0xC000\n"
      "ADD.B &0xC004, &0xC008\n" 
      "ADD.B 0x2, &0x3F0\n"
      "ADD.B &0xC000, 0x2\n"
      
      "ADD.B @R5, R7\n"

      "ADD.B @R5, 0x2(R4)\n" 
      "ADD.B @R5, 0x2\n"
      "ADD.B @R5, &0x300\n"

      "ADD.B @R5+, R7\n"
      "ADD.B #0x1234, R7\n"

      "ADD #-1, R5\n"
      "ADD #0, R5\n"
      "ADD #1, R5\n"
      "ADD #2, R5\n"
      "ADD #4, R5\n"
      "ADD #8, R5\n"
      
      "ADD #-1, 0x2(R5)\n"
      "ADD #0, 0x2(R5)\n"
      "ADD #1, 0x2(R5)\n"
      "ADD #2, 0x2(R5)\n"
      "ADD #4, 0x2(R5)\n"
      "ADD #8, 0x2(R5)\n"
      
      "ADD #-1, 0x10\n"
      "ADD #0, 0x10\n"
      "ADD #1, 0x10\n"
      "ADD #2, 0x10\n"
      "ADD #4, 0x10\n"
      "ADD #8, 0x10\n"      

      "ADD #-1, &0x0300\n"
      "ADD #0, &0x0300\n"
      "ADD #1, &0x0300\n"
      "ADD #2, &0x0300\n"
      "ADD #4, &0x0300\n"
      "ADD #8, &0x0300\n"

      "CALL #0x1\n" 
      "CALL #0x8\n" 
      "CALL #-0x1\n" 
      "CALL &0x1234\n" 
      "CALL #0x72A\n" 
      "CALL 0x4\n" 
      "CALL &0x4\n" 

      "CALL R5\n"
      "CALL 0x2(R5)\n" 
      "CALL @R5\n" 
      "CALL @R5+\n" 

      "PUSH -0x2\n" 
      "PUSH 0x2\n" 
      "PUSH.B 0x4\n" 
      
      "PUSH &0xC000\n" 
      "PUSH.B &0xC010\n" 
      
      "PUSH #4\n" 
      "PUSH #8\n" 
      "PUSH #0\n"
      "PUSH #1\n"
      "PUSH #2\n"
      "PUSH #-1\n"
      
      "PUSH.B #4\n"
      "PUSH.B #8\n"
      "PUSH.B #0\n"
      "PUSH.B #1\n"
      "PUSH.B #2\n"
      "PUSH.B #-1\n"
      
      "PUSH #0x1234\n"
      "PUSH.B #0x78AB\n"

      "PUSH R5\n"
      "PUSH.B R5\n"
      "PUSH 0x2(R5)\n"
      "PUSH.B 0x2(R5)\n"
      "PUSH @R5\n"
      "PUSH.B @R5\n"
      "PUSH @R5+\n"
      "PUSH.B @R5+\n"
      
      "SXT R5\n"
      "SXT -0x2(R5)\n"
      "SXT @R5\n"
      "SXT @R5+\n"
      );
  
  // Stop the watchdog timer
  WDTCTL = WDTPW + WDTHOLD;

  i = 182;
    
  // A register that configures the direction of a port pin as an
  // input or output 
  P1DIR |= 0x10;

  while(1){
    P1OUT ^= 0x10;
    for(i = 0;i < 30000;i++);
  }
 
}
